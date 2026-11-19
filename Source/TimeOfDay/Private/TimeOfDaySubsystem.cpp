#include "TimeOfDaySubsystem.h"

#include "CanvasItem.h"
#include "Components/DirectionalLightComponent.h"
#include "Components/ExponentialHeightFogComponent.h"
#include "Components/LightComponent.h"
#include "Components/SkyLightComponent.h"
#include "Debug/DebugDrawService.h"
#include "Engine/Canvas.h"
#include "Engine/DataTable.h"
#include "Engine/DirectionalLight.h"
#include "Engine/Engine.h"
#include "Engine/ExponentialHeightFog.h"
#include "Engine/PostProcessVolume.h"
#include "Engine/SkyLight.h"
#include "Engine/World.h"
#include "EngineUtils.h"
#include "Engine/Font.h"
#include "GameFramework/Pawn.h"
#include "GameFramework/PlayerController.h"
#include "InputCoreTypes.h"
#include "HAL/IConsoleManager.h"
#include "Kismet/GameplayStatics.h"
#include "TimerManager.h"

DEFINE_LOG_CATEGORY_STATIC(LogTimeOfDay, Log, All);

namespace TimeOfDay
{
	static const FName SunTag(TEXT("TimeOfDaySun"));
	static const FName MoonTag(TEXT("TimeOfDayMoon"));

	// Outdoor states in order, used by StepTimeState and the demo cycle.
	static const ETimeOfDayState OutdoorCycle[] =
	{
		ETimeOfDayState::Dawn,
		ETimeOfDayState::Morning,
		ETimeOfDayState::Noon,
		ETimeOfDayState::Afternoon,
		ETimeOfDayState::Evening,
		ETimeOfDayState::Twilight,
		ETimeOfDayState::Night
	};

	// Prefer an actor of class T carrying Tag; otherwise the first actor of class T.
	template <typename T>
	T* FindTaggedOrFirst(UWorld* World, FName Tag)
	{
		T* First = nullptr;
		for (TActorIterator<T> It(World); It; ++It)
		{
			if (It->ActorHasTag(Tag))
			{
				return *It;
			}
			if (!First)
			{
				First = *It;
			}
		}
		return First;
	}
}

// --------------------------------------------------------------------------
// UTickableWorldSubsystem interface
// --------------------------------------------------------------------------

TStatId UTimeOfDaySubsystem::GetStatId() const
{
	RETURN_QUICK_DECLARE_CYCLE_STAT(UTimeOfDaySubsystem, STATGROUP_Tickables);
}

bool UTimeOfDaySubsystem::DoesSupportWorldType(const EWorldType::Type WorldType) const
{
	return WorldType == EWorldType::Game || WorldType == EWorldType::PIE;
}

void UTimeOfDaySubsystem::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	if (bHotkeysEnabled)
	{
		TickHotkeys();
	}

	if (bTransitionActive)
	{
		TickTransition(DeltaTime);
	}
	else if (bDemoCycleActive)
	{
		TickDemoCycle(DeltaTime);
	}
}

void UTimeOfDaySubsystem::OnWorldBeginPlay(UWorld& InWorld)
{
	Super::OnWorldBeginPlay(InWorld);

	// The overlay draws on the game viewport through the debug draw service, so it needs no HUD class or widget.
	OverlayDrawHandle = UDebugDrawService::Register(TEXT("Game"), FDebugDrawDelegate::CreateUObject(this, &UTimeOfDaySubsystem::DrawOverlay));
}

void UTimeOfDaySubsystem::Deinitialize()
{
	if (OverlayDrawHandle.IsValid())
	{
		UDebugDrawService::Unregister(OverlayDrawHandle);
		OverlayDrawHandle.Reset();
	}

	Super::Deinitialize();
}

// --------------------------------------------------------------------------
// Public API
// --------------------------------------------------------------------------

void UTimeOfDaySubsystem::InitializeTimeOfDay(const FTimeOfDayConfig& Config, UDataTable* InLightingPresets)
{
	DiscoverLightingActors();

	// Capture before applying anything, so state None means "the level as authored".
	LevelLightingPreset = CaptureCurrentLighting();

	FastTransitionDuration      = FMath::Max(Config.FastTransitionSeconds, 0.1f);
	SlowTransitionDuration      = FMath::Max(Config.SlowTransitionSeconds, 0.1f);
	CinematicLockTimeoutSeconds = FMath::Max(Config.CinematicLockTimeoutSeconds, 1.f);
	bCompanionAllowed           = Config.bAllowCompanionLight;
	CompanionLightClass         = Config.CompanionLightClass;
	CompanionOffset             = Config.CompanionOffset;
	TimeStatePresets            = Config.TimeStatePresets;

	// Data table rows override config presets for matching states. Row names match enum names ("Dawn", "Night"...).
	if (InLightingPresets)
	{
		for (const FName& RowName : InLightingPresets->GetRowNames())
		{
			ETimeOfDayState State;
			if (!ParseState(RowName.ToString(), State) || State == ETimeOfDayState::None)
			{
				UE_LOG(LogTimeOfDay, Warning, TEXT("Lighting preset row '%s' doesn't match a time state and was skipped."), *RowName.ToString());
				continue;
			}
			if (const FTimeStatePreset* Row = InLightingPresets->FindRow<FTimeStatePreset>(RowName, TEXT("TimeOfDay")))
			{
				TimeStatePresets.Add(State, *Row);
			}
		}
	}

	bTimeOfDayInitialized = true;
	CurrentTimeState      = ETimeOfDayState::None;

	if (Config.DefaultTimeState != ETimeOfDayState::None)
	{
		SetTimeState(Config.DefaultTimeState, ETimeTransitionMode::Instant);
	}

	UE_LOG(LogTimeOfDay, Log, TEXT("Initialized. Sun: %s, Sky light: %s, Fog: %s, Post process: %s, Sky sphere: %s, Moon: %s"),
		SunLight ? *SunLight->GetName() : TEXT("none"),
		SkyLight ? *SkyLight->GetName() : TEXT("none"),
		HeightFog ? *HeightFog->GetName() : TEXT("none"),
		PostProcessVolume ? *PostProcessVolume->GetName() : TEXT("none"),
		SkySphere ? *SkySphere->GetName() : TEXT("none"),
		MoonLight ? *MoonLight->GetName() : TEXT("none"));
}

void UTimeOfDaySubsystem::RequestTimeState(ETimeOfDayState NewState, ETimeTransitionMode TransitionMode)
{
	EnsureInitialized();

	if (bCinematicLock)
	{
		return;
	}

	SetTimeState(NewState, TransitionMode);
}

void UTimeOfDaySubsystem::CinematicBeginOverride(ETimeOfDayState OverrideState, ETimeTransitionMode TransitionMode, bool bForceCompanionLight, bool bCompanionLightEnabled)
{
	EnsureInitialized();

	StopDemoCycle();
	bCinematicLock = true;
	SetTimeState(OverrideState, TransitionMode);

	if (bForceCompanionLight)
	{
		SetCompanionLightEnabled(bCompanionLightEnabled);
	}

	// Auto-release fallback in case CinematicEndOverride is never called
	if (UWorld* World = GetWorld())
	{
		World->GetTimerManager().SetTimer(
			CinematicLockTimerHandle,
			this,
			&UTimeOfDaySubsystem::AutoReleaseCinematicLock,
			CinematicLockTimeoutSeconds,
			false);
	}
}

void UTimeOfDaySubsystem::CinematicEndOverride()
{
	bCinematicLock = false;

	if (UWorld* World = GetWorld())
	{
		World->GetTimerManager().ClearTimer(CinematicLockTimerHandle);
	}
}

void UTimeOfDaySubsystem::RestoreTimeState(ETimeOfDayState SavedState)
{
	EnsureInitialized();

	// Snap, no transition on load
	SetTimeState(SavedState, ETimeTransitionMode::Instant);
}

void UTimeOfDaySubsystem::SetCompanionLightEnabled(bool bEnabled)
{
	UWorld* World = GetWorld();
	if (!World)
	{
		return;
	}

	if (bEnabled && !ActiveCompanion)
	{
		if (!bCompanionAllowed || !CompanionLightClass)
		{
			return;
		}

		APawn* Pawn = UGameplayStatics::GetPlayerPawn(World, 0);
		if (!Pawn)
		{
			return;
		}

		FActorSpawnParameters Params;
		Params.SpawnCollisionHandlingOverride = ESpawnActorCollisionHandlingMethod::AlwaysSpawn;
		ActiveCompanion = World->SpawnActor<AActor>(CompanionLightClass, Pawn->GetActorTransform(), Params);
		if (ActiveCompanion)
		{
			ActiveCompanion->AttachToActor(Pawn, FAttachmentTransformRules::SnapToTargetNotIncludingScale);
			ActiveCompanion->SetActorRelativeLocation(CompanionOffset);
		}
	}
	else if (!bEnabled && ActiveCompanion)
	{
		ActiveCompanion->Destroy();
		ActiveCompanion = nullptr;
	}
}

void UTimeOfDaySubsystem::StartDemoCycle(float HoldSeconds, ETimeTransitionMode TransitionMode)
{
	EnsureInitialized();

	if (bCinematicLock)
	{
		return;
	}

	DemoHoldSeconds    = FMath::Max(HoldSeconds, 0.f);
	DemoTransitionMode = TransitionMode;
	DemoHoldElapsed    = DemoHoldSeconds; // start moving right away
	bDemoCycleActive   = true;
}

void UTimeOfDaySubsystem::StopDemoCycle()
{
	bDemoCycleActive = false;
}

void UTimeOfDaySubsystem::StepTimeState(bool bForward, ETimeTransitionMode TransitionMode)
{
	EnsureInitialized();

	const int32 Count = UE_ARRAY_COUNT(TimeOfDay::OutdoorCycle);

	// While transitioning, step from where we're heading, so repeated steps don't stall.
	const ETimeOfDayState From = bTransitionActive ? TransitionTargetState : CurrentTimeState;

	int32 Index = INDEX_NONE;
	for (int32 i = 0; i < Count; ++i)
	{
		if (TimeOfDay::OutdoorCycle[i] == From)
		{
			Index = i;
			break;
		}
	}

	if (Index == INDEX_NONE)
	{
		Index = bForward ? 0 : Count - 1;
	}
	else
	{
		Index = (Index + (bForward ? 1 : Count - 1)) % Count;
	}

	RequestTimeState(TimeOfDay::OutdoorCycle[Index], TransitionMode);
}

// --------------------------------------------------------------------------
// Private: setup
// --------------------------------------------------------------------------

void UTimeOfDaySubsystem::EnsureInitialized()
{
	if (!bTimeOfDayInitialized)
	{
		InitializeTimeOfDay(FTimeOfDayConfig(), nullptr);
	}
}

void UTimeOfDaySubsystem::DiscoverLightingActors()
{
	UWorld* World = GetWorld();
	if (!World)
	{
		return;
	}

	SunLight  = TimeOfDay::FindTaggedOrFirst<ADirectionalLight>(World, TimeOfDay::SunTag);
	SkyLight  = TimeOfDay::FindTaggedOrFirst<ASkyLight>(World, NAME_None);
	HeightFog = TimeOfDay::FindTaggedOrFirst<AExponentialHeightFog>(World, NAME_None);

	// Moon: only an explicitly tagged light, so the sun is never mistaken for it.
	MoonLight = nullptr;
	for (TActorIterator<AActor> It(World); It; ++It)
	{
		if (It->ActorHasTag(TimeOfDay::MoonTag) && *It != SunLight)
		{
			MoonLight = *It;
			break;
		}
	}

	// Exposure is driven through the level-wide (unbound) post process volume.
	PostProcessVolume = nullptr;
	for (TActorIterator<APostProcessVolume> It(World); It; ++It)
	{
		if (It->bUnbound)
		{
			PostProcessVolume = *It;
			break;
		}
	}

	// Sky sphere is identified by the interface it implements, not by a specific class.
	TArray<AActor*> SkySphereActors;
	UGameplayStatics::GetAllActorsWithInterface(World, USkySphereInterface::StaticClass(), SkySphereActors);
	SkySphere = SkySphereActors.Num() > 0 ? SkySphereActors[0] : nullptr;

	if (SunLight && SunLight->GetRootComponent() && SunLight->GetRootComponent()->Mobility != EComponentMobility::Movable)
	{
		UE_LOG(LogTimeOfDay, Warning, TEXT("Sun light '%s' isn't Movable. Set its Mobility to Movable so its rotation can change at runtime."), *SunLight->GetName());
	}
}

FTimeStatePreset UTimeOfDaySubsystem::CaptureCurrentLighting() const
{
	FTimeStatePreset Captured;

	if (SunLight)
	{
		Captured.SunRotation = SunLight->GetActorRotation();
		if (const UDirectionalLightComponent* DLC = Cast<UDirectionalLightComponent>(SunLight->GetLightComponent()))
		{
			Captured.LightBrightness  = DLC->Intensity;
			Captured.LightTemperature = DLC->bUseTemperature ? DLC->Temperature : 6500.f;
		}
	}

	if (SkyLight)
	{
		if (const USkyLightComponent* SLC = Cast<USkyLightComponent>(SkyLight->GetLightComponent()))
		{
			Captured.SkyLightIntensity = SLC->Intensity;
		}
	}

	if (HeightFog)
	{
		if (const UExponentialHeightFogComponent* FogComp = HeightFog->FindComponentByClass<UExponentialHeightFogComponent>())
		{
			Captured.FogDensity = FogComp->FogDensity;
		}
	}

	if (PostProcessVolume)
	{
		const FPostProcessSettings& Settings = PostProcessVolume->Settings;
		Captured.Exposure = Settings.bOverride_AutoExposureBias ? Settings.AutoExposureBias : 0.f;
	}

	if (MoonLight)
	{
		if (const ULightComponent* LC = MoonLight->FindComponentByClass<ULightComponent>())
		{
			Captured.MoonIntensity = LC->Intensity;
		}
	}

	return Captured;
}

// --------------------------------------------------------------------------
// Private: state & lighting
// --------------------------------------------------------------------------

void UTimeOfDaySubsystem::SetTimeState(ETimeOfDayState NewState, ETimeTransitionMode TransitionMode)
{
	if (TransitionMode == ETimeTransitionMode::Instant || TransitionMode == ETimeTransitionMode::None)
	{
		bTransitionActive = false;
		ApplyPresetToLights(GetPresetForState(NewState), true);
		FinishStateChange(NewState);
		return;
	}

	// Start from what's on screen right now, so interrupting a transition never pops.
	TransitionFrom        = bTransitionActive ? LerpPresets(TransitionFrom, TransitionTo, FMath::Clamp(TransitionElapsed / TransitionDuration, 0.f, 1.f))
	                                          : GetPresetForState(CurrentTimeState);
	TransitionTo          = GetPresetForState(NewState);
	TransitionTargetState = NewState;
	TransitionElapsed     = 0.f;
	TransitionDuration    = (TransitionMode == ETimeTransitionMode::Slow) ? SlowTransitionDuration : FastTransitionDuration;
	ActiveTransitionMode  = TransitionMode;
	bTransitionActive     = true;
}

void UTimeOfDaySubsystem::FinishStateChange(ETimeOfDayState NewState)
{
	const ETimeOfDayState OldState = CurrentTimeState;
	CurrentTimeState = NewState;

	if (OldState != NewState)
	{
		OnTimeStateChanged.Broadcast(OldState, NewState);
	}
}

void UTimeOfDaySubsystem::ApplyPresetToLights(const FTimeStatePreset& Preset, bool bRecaptureSky)
{
	if (SunLight)
	{
		SunLight->SetActorRotation(Preset.SunRotation);

		if (UDirectionalLightComponent* DLC = Cast<UDirectionalLightComponent>(SunLight->GetLightComponent()))
		{
			DLC->SetIntensity(Preset.LightBrightness);
			DLC->SetUseTemperature(true);
			DLC->SetTemperature(Preset.LightTemperature);
		}
	}

	if (SkyLight)
	{
		if (USkyLightComponent* SLC = Cast<USkyLightComponent>(SkyLight->GetLightComponent()))
		{
			SLC->SetIntensity(Preset.SkyLightIntensity);

			if (bRecaptureSky)
			{
				SLC->RecaptureSky();
			}
		}
	}

	// Sky sphere: sun rotation is already set above, so a Blueprint that reads the
	// sun direction inside ApplySkySpherePreset sees the new value.
	if (SkySphere && SkySphere->Implements<USkySphereInterface>())
	{
		ISkySphereInterface::Execute_ApplySkySpherePreset(
			SkySphere,
			Preset.SkySunBrightness,
			Preset.SkySunHeight,
			Preset.SkyCloudOpacity,
			Preset.bSkyColorsByPosition);

		ISkySphereInterface::Execute_RefreshSkySphere(SkySphere);
	}

	if (MoonLight)
	{
		if (ULightComponent* LC = MoonLight->FindComponentByClass<ULightComponent>())
		{
			LC->SetIntensity(Preset.MoonIntensity);
		}
	}

	if (HeightFog)
	{
		if (UExponentialHeightFogComponent* FogComp = HeightFog->FindComponentByClass<UExponentialHeightFogComponent>())
		{
			FogComp->SetFogDensity(Preset.FogDensity);
		}
	}

	if (PostProcessVolume)
	{
		PostProcessVolume->Settings.bOverride_AutoExposureBias = true;
		PostProcessVolume->Settings.AutoExposureBias = Preset.Exposure;
	}
}

void UTimeOfDaySubsystem::TickTransition(float DeltaTime)
{
	TransitionElapsed += DeltaTime;
	const float Alpha = FMath::Clamp(TransitionElapsed / TransitionDuration, 0.f, 1.f);

	if (Alpha < 1.f)
	{
		// Skip the sky recapture while blending; it runs once at the end.
		ApplyPresetToLights(LerpPresets(TransitionFrom, TransitionTo, FMath::SmoothStep(0.f, 1.f, Alpha)), false);
		return;
	}

	bTransitionActive = false;
	DemoHoldElapsed   = 0.f;
	ApplyPresetToLights(TransitionTo, true);
	FinishStateChange(TransitionTargetState);
}

void UTimeOfDaySubsystem::TickDemoCycle(float DeltaTime)
{
	DemoHoldElapsed += DeltaTime;
	if (DemoHoldElapsed >= DemoHoldSeconds)
	{
		DemoHoldElapsed = 0.f;
		StepTimeState(true, DemoTransitionMode);
	}
}

FTimeStatePreset UTimeOfDaySubsystem::GetLivePreset() const
{
	return bTransitionActive
		? LerpPresets(TransitionFrom, TransitionTo, FMath::SmoothStep(0.f, 1.f, FMath::Clamp(TransitionElapsed / TransitionDuration, 0.f, 1.f)))
		: GetPresetForState(CurrentTimeState);
}

void UTimeOfDaySubsystem::TickHotkeys()
{
	UWorld* World = GetWorld();
	APlayerController* PC = World ? World->GetFirstPlayerController() : nullptr;
	if (!PC || !PC->IsLocalController())
	{
		return;
	}

	const bool bShift = PC->IsInputKeyDown(EKeys::LeftShift) || PC->IsInputKeyDown(EKeys::RightShift);
	const ETimeTransitionMode StepMode = bShift ? ETimeTransitionMode::Fast : ETimeTransitionMode::Slow;

	if (PC->WasInputKeyJustPressed(EKeys::RightBracket))
	{
		StopDemoCycle();
		StepTimeState(true, StepMode);
	}
	else if (PC->WasInputKeyJustPressed(EKeys::LeftBracket))
	{
		StopDemoCycle();
		StepTimeState(false, StepMode);
	}
	else if (PC->WasInputKeyJustPressed(EKeys::Backslash))
	{
		if (bDemoCycleActive)
		{
			StopDemoCycle();
		}
		else
		{
			StartDemoCycle(3.f, StepMode);
		}
	}
	else if (PC->WasInputKeyJustPressed(EKeys::Semicolon))
	{
		StopDemoCycle();
		RequestTimeState(ETimeOfDayState::None, StepMode);
	}
	else if (PC->WasInputKeyJustPressed(EKeys::Slash))
	{
		bShowDebugReadout = !bShowDebugReadout;
	}
}

void UTimeOfDaySubsystem::DrawOverlay(UCanvas* Canvas, APlayerController* PC)
{
	if (!bShowDebugReadout || !Canvas || !GEngine || !PC || PC->GetWorld() != GetWorld())
	{
		return;
	}

	// Layout is authored at 1080p and scaled to the viewport.
	const float S = FMath::Max(Canvas->ClipY / 1080.f, 0.5f);
	const FLinearColor Accent(1.f, 0.757f, 0.027f);
	const FLinearColor Dim(0.62f, 0.62f, 0.62f);
	UFont* SmallFont  = GEngine->GetSmallFont();
	UFont* MediumFont = GEngine->GetMediumFont();
	UFont* LargeFont  = GEngine->GetLargeFont();

	auto Tile = [Canvas](float X, float Y, float W, float H, const FLinearColor& Color)
	{
		FCanvasTileItem Item(FVector2D(X, Y), FVector2D(W, H), Color);
		Item.BlendMode = SE_BLEND_Translucent;
		Canvas->DrawItem(Item);
	};

	auto Text = [Canvas](float X, float Y, const FString& String, UFont* Font, const FLinearColor& Color, float Scale)
	{
		FCanvasTextItem Item(FVector2D(X, Y), FText::FromString(String), Font, Color);
		Item.Scale = FVector2D(Scale, Scale);
		Item.EnableShadow(FLinearColor(0.f, 0.f, 0.f, 0.8f));
		Canvas->DrawItem(Item);
	};

	const float X = 40.f * S;
	const float Y = 40.f * S;
	const float W = 560.f * S;
	const float H = 250.f * S;
	const float Pad = 20.f * S;
	const float InnerW = W - Pad * 2.f;

	// Panel
	Tile(X, Y, W, H, FLinearColor(0.f, 0.f, 0.f, 0.55f));
	Tile(X, Y, 4.f * S, H, Accent);

	float CY = Y + 14.f * S;
	Text(X + Pad, CY, TEXT("TIME OF DAY SYSTEM"), SmallFont, Accent, 1.1f * S);

	FString Tags;
	if (bCinematicLock)   { Tags += TEXT("CINEMATIC LOCK   "); }
	if (bDemoCycleActive) { Tags += TEXT("DEMO LOOP"); }
	if (!Tags.IsEmpty())
	{
		Text(X + W - Pad - 190.f * S, CY, Tags, SmallFont, Accent, 1.f * S);
	}

	// Headline: current state, or "From -> To"
	CY += 26.f * S;
	const FString Headline = bTransitionActive
		? FString::Printf(TEXT("%s  >  %s"), *StateToString(CurrentTimeState), *StateToString(TransitionTargetState))
		: StateToString(CurrentTimeState);
	Text(X + Pad, CY, Headline, LargeFont, FLinearColor::White, 1.25f * S);

	// Progress bar
	CY += 42.f * S;
	const float Alpha = bTransitionActive ? FMath::Clamp(TransitionElapsed / TransitionDuration, 0.f, 1.f) : 1.f;
	Tile(X + Pad, CY, InnerW, 6.f * S, FLinearColor(1.f, 1.f, 1.f, 0.15f));
	Tile(X + Pad, CY, InnerW * Alpha, 6.f * S, Accent);

	CY += 12.f * S;
	const FString Progress = bTransitionActive
		? FString::Printf(TEXT("Blending %d%%   %s transition, %.1fs"), FMath::RoundToInt(Alpha * 100.f),
			ActiveTransitionMode == ETimeTransitionMode::Slow ? TEXT("slow") : TEXT("fast"), TransitionDuration)
		: FString(TEXT("Holding"));
	Text(X + Pad, CY, Progress, SmallFont, Dim, 1.f * S);

	// Timeline strip of the outdoor states
	CY += 28.f * S;
	const int32 Count = UE_ARRAY_COUNT(TimeOfDay::OutdoorCycle);
	const float Gap = 4.f * S;
	const float SegW = (InnerW - Gap * (Count - 1)) / Count;
	for (int32 i = 0; i < Count; ++i)
	{
		const ETimeOfDayState State = TimeOfDay::OutdoorCycle[i];
		const float SX = X + Pad + i * (SegW + Gap);
		const bool bCurrent = State == CurrentTimeState;
		const bool bTarget  = bTransitionActive && State == TransitionTargetState;

		FLinearColor Fill(1.f, 1.f, 1.f, 0.12f);
		if (bCurrent)     { Fill = Accent; }
		else if (bTarget) { Fill = FLinearColor(Accent.R, Accent.G, Accent.B, 0.25f + 0.6f * Alpha); }
		Tile(SX, CY, SegW, 6.f * S, Fill);

		Text(SX, CY + 10.f * S, StateToString(State), SmallFont, (bCurrent || bTarget) ? FLinearColor::White : Dim, 0.85f * S);
	}

	// Live values
	CY += 40.f * S;
	const FTimeStatePreset Live = GetLivePreset();
	const FString Values = FString::Printf(TEXT("Sun %.0f deg    %.0f K    Intensity %.1f    Sky %.2f    Fog %.3f    Exposure %+.1f"),
		-Live.SunRotation.Pitch, Live.LightTemperature, Live.LightBrightness, Live.SkyLightIntensity, Live.FogDensity, Live.Exposure);
	Text(X + Pad, CY, Values, SmallFont, FLinearColor::White, 1.f * S);

	// Hotkey legend
	CY += 26.f * S;
	Text(X + Pad, CY, TEXT("[ ]  step     Shift  fast     \\  demo loop     ;  level lighting     /  hide"), SmallFont, Dim, 0.95f * S);
}

FString UTimeOfDaySubsystem::GetStatusString() const
{
	FString Status;
	if (bTransitionActive)
	{
		const float Alpha = FMath::Clamp(TransitionElapsed / TransitionDuration, 0.f, 1.f);
		Status = FString::Printf(TEXT("Time of Day: %s -> %s  %d%%  (%s)"),
			*StateToString(CurrentTimeState), *StateToString(TransitionTargetState),
			FMath::RoundToInt(Alpha * 100.f),
			ActiveTransitionMode == ETimeTransitionMode::Slow ? TEXT("slow") : TEXT("fast"));
	}
	else
	{
		Status = FString::Printf(TEXT("Time of Day: %s"), *StateToString(CurrentTimeState));
	}

	if (bCinematicLock)
	{
		Status += TEXT("  [cinematic lock]");
	}
	if (bDemoCycleActive)
	{
		Status += TEXT("  [demo cycle]");
	}
	return Status;
}

FTimeStatePreset UTimeOfDaySubsystem::GetPresetForState(ETimeOfDayState State) const
{
	if (State == ETimeOfDayState::None)
	{
		return LevelLightingPreset;
	}

	if (const FTimeStatePreset* Preset = TimeStatePresets.Find(State))
	{
		return *Preset;
	}

	// Built-in fallback defaults. Override per level with a data table.
	FTimeStatePreset Default;
	switch (State)
	{
	case ETimeOfDayState::Dawn:
		Default.SunRotation          = FRotator(-10.f, 90.f, 0.f);
		Default.LightBrightness      = 3.f;
		Default.LightTemperature     = 3500.f;
		Default.Exposure             = 0.f;
		Default.SkyLightIntensity    = 0.4f;
		Default.SkySunBrightness     = 0.3f;
		Default.SkySunHeight         = 0.1f;
		Default.SkyCloudOpacity      = 0.6f;
		Default.bSkyColorsByPosition = true;
		Default.FogDensity           = 0.04f;
		Default.MoonIntensity        = 0.f;
		break;
	case ETimeOfDayState::Morning:
		Default.SunRotation          = FRotator(-25.f, 60.f, 0.f);
		Default.LightBrightness      = 6.f;
		Default.LightTemperature     = 4500.f;
		Default.Exposure             = 0.f;
		Default.SkyLightIntensity    = 0.7f;
		Default.SkySunBrightness     = 0.6f;
		Default.SkySunHeight         = 0.3f;
		Default.SkyCloudOpacity      = 0.5f;
		Default.bSkyColorsByPosition = true;
		Default.FogDensity           = 0.02f;
		Default.MoonIntensity        = 0.f;
		break;
	case ETimeOfDayState::Noon:
		Default.SunRotation          = FRotator(-85.f, 0.f, 0.f);
		Default.LightBrightness      = 12.f;
		Default.LightTemperature     = 7000.f;
		Default.Exposure             = 0.f;
		Default.SkyLightIntensity    = 1.f;
		Default.SkySunBrightness     = 1.f;
		Default.SkySunHeight         = 1.f;
		Default.SkyCloudOpacity      = 0.4f;
		Default.bSkyColorsByPosition = true;
		Default.FogDensity           = 0.005f;
		Default.MoonIntensity        = 0.f;
		break;
	case ETimeOfDayState::Day:
		Default.SunRotation          = FRotator(-60.f, 0.f, 0.f);
		Default.LightBrightness      = 10.f;
		Default.LightTemperature     = 6500.f;
		Default.Exposure             = 0.f;
		Default.SkyLightIntensity    = 1.f;
		Default.SkySunBrightness     = 0.9f;
		Default.SkySunHeight         = 0.7f;
		Default.SkyCloudOpacity      = 0.5f;
		Default.bSkyColorsByPosition = true;
		Default.FogDensity           = 0.01f;
		Default.MoonIntensity        = 0.f;
		break;
	case ETimeOfDayState::Afternoon:
		Default.SunRotation          = FRotator(-35.f, -30.f, 0.f);
		Default.LightBrightness      = 8.f;
		Default.LightTemperature     = 5500.f;
		Default.Exposure             = 0.f;
		Default.SkyLightIntensity    = 0.8f;
		Default.SkySunBrightness     = 0.7f;
		Default.SkySunHeight         = 0.4f;
		Default.SkyCloudOpacity      = 0.5f;
		Default.bSkyColorsByPosition = true;
		Default.FogDensity           = 0.015f;
		Default.MoonIntensity        = 0.f;
		break;
	case ETimeOfDayState::Evening:
		Default.SunRotation          = FRotator(-10.f, -80.f, 0.f);
		Default.LightBrightness      = 4.f;
		Default.LightTemperature     = 3000.f;
		Default.Exposure             = 0.f;
		Default.SkyLightIntensity    = 0.3f;
		Default.SkySunBrightness     = 0.4f;
		Default.SkySunHeight         = 0.1f;
		Default.SkyCloudOpacity      = 0.6f;
		Default.bSkyColorsByPosition = true;
		Default.FogDensity           = 0.03f;
		Default.MoonIntensity        = 0.f;
		break;
	case ETimeOfDayState::Twilight:
		Default.SunRotation          = FRotator(-3.f, -100.f, 0.f);
		Default.LightBrightness      = 1.5f;
		Default.LightTemperature     = 4000.f;
		Default.Exposure             = -0.5f;
		Default.SkyLightIntensity    = 0.15f;
		Default.SkySunBrightness     = 0.2f;
		Default.SkySunHeight         = 0.05f;
		Default.SkyCloudOpacity      = 0.5f;
		Default.bSkyColorsByPosition = true;
		Default.FogDensity           = 0.04f;
		Default.MoonIntensity        = 1.f;
		break;
	case ETimeOfDayState::Night:
		Default.SunRotation          = FRotator(10.f, 180.f, 0.f);
		Default.LightBrightness      = 0.5f;
		Default.LightTemperature     = 8000.f;
		Default.Exposure             = -1.f;
		Default.SkyLightIntensity    = 0.05f;
		Default.SkySunBrightness     = 0.f;
		Default.SkySunHeight         = 0.f;
		Default.SkyCloudOpacity      = 0.3f;
		Default.bSkyColorsByPosition = true;
		Default.FogDensity           = 0.05f;
		Default.MoonIntensity        = 2.f;
		break;
	case ETimeOfDayState::Cave:
		Default.SunRotation          = FRotator(90.f, 0.f, 0.f);
		Default.LightBrightness      = 0.f;
		Default.LightTemperature     = 2000.f;
		Default.Exposure             = -2.f;
		Default.SkyLightIntensity    = 0.f;
		Default.SkySunBrightness     = 0.f;
		Default.SkySunHeight         = 0.f;
		Default.SkyCloudOpacity      = 0.f;
		Default.bSkyColorsByPosition = false;
		Default.FogDensity           = 0.08f;
		Default.MoonIntensity        = 0.f;
		break;
	case ETimeOfDayState::InsideLight:
		Default.SunRotation          = FRotator(90.f, 0.f, 0.f);
		Default.LightBrightness      = 0.f;
		Default.LightTemperature     = 3200.f;
		Default.Exposure             = 0.f;
		Default.SkyLightIntensity    = 0.3f;
		Default.SkySunBrightness     = 0.f;
		Default.SkySunHeight         = 0.f;
		Default.SkyCloudOpacity      = 0.f;
		Default.bSkyColorsByPosition = false;
		Default.FogDensity           = 0.f;
		Default.MoonIntensity        = 0.f;
		break;
	case ETimeOfDayState::InsideDark:
		Default.SunRotation          = FRotator(90.f, 0.f, 0.f);
		Default.LightBrightness      = 0.f;
		Default.LightTemperature     = 2200.f;
		Default.Exposure             = -1.f;
		Default.SkyLightIntensity    = 0.05f;
		Default.SkySunBrightness     = 0.f;
		Default.SkySunHeight         = 0.f;
		Default.SkyCloudOpacity      = 0.f;
		Default.bSkyColorsByPosition = false;
		Default.FogDensity           = 0.f;
		Default.MoonIntensity        = 0.f;
		break;
	default:
		break;
	}
	return Default;
}

FTimeStatePreset UTimeOfDaySubsystem::LerpPresets(const FTimeStatePreset& A, const FTimeStatePreset& B, float Alpha)
{
	FTimeStatePreset Result;

	// Quaternion slerp takes the shortest arc, so the sun never spins the long way around
	// when yaw wraps (for example Evening -80 to Night 180).
	Result.SunRotation = FQuat::Slerp(A.SunRotation.Quaternion(), B.SunRotation.Quaternion(), Alpha).Rotator();

	Result.LightBrightness   = FMath::Lerp(A.LightBrightness,   B.LightBrightness,   Alpha);
	Result.LightTemperature  = FMath::Lerp(A.LightTemperature,  B.LightTemperature,  Alpha);
	Result.Exposure          = FMath::Lerp(A.Exposure,          B.Exposure,          Alpha);
	Result.SkyLightIntensity = FMath::Lerp(A.SkyLightIntensity, B.SkyLightIntensity, Alpha);
	Result.SkySunBrightness  = FMath::Lerp(A.SkySunBrightness,  B.SkySunBrightness,  Alpha);
	Result.SkySunHeight      = FMath::Lerp(A.SkySunHeight,      B.SkySunHeight,      Alpha);
	Result.SkyCloudOpacity   = FMath::Lerp(A.SkyCloudOpacity,   B.SkyCloudOpacity,   Alpha);
	Result.FogDensity        = FMath::Lerp(A.FogDensity,        B.FogDensity,        Alpha);
	Result.MoonIntensity     = FMath::Lerp(A.MoonIntensity,     B.MoonIntensity,     Alpha);

	// Bool: hold the From value during the transition; the final apply snaps to To.
	Result.bSkyColorsByPosition = A.bSkyColorsByPosition;
	return Result;
}

void UTimeOfDaySubsystem::AutoReleaseCinematicLock()
{
	if (bCinematicLock)
	{
		UE_LOG(LogTimeOfDay, Warning, TEXT("Cinematic lock auto-released after %.0f s. Call CinematicEndOverride when the cutscene ends."), CinematicLockTimeoutSeconds);
	}
	bCinematicLock = false;
}

// --------------------------------------------------------------------------
// Parsing helpers
// --------------------------------------------------------------------------

bool UTimeOfDaySubsystem::ParseState(const FString& Text, ETimeOfDayState& OutState)
{
	const UEnum* Enum = StaticEnum<ETimeOfDayState>();
	const FString Wanted = Text.TrimStartAndEnd();

	// NumEnums() includes the hidden _MAX entry, so stop one short.
	for (int32 i = 0; i < Enum->NumEnums() - 1; ++i)
	{
		if (Enum->GetNameStringByIndex(i).Equals(Wanted, ESearchCase::IgnoreCase))
		{
			OutState = static_cast<ETimeOfDayState>(Enum->GetValueByIndex(i));
			return true;
		}
	}
	return false;
}

bool UTimeOfDaySubsystem::ParseTransitionMode(const FString& Text, ETimeTransitionMode& OutMode)
{
	if (Text.Equals(TEXT("slow"), ESearchCase::IgnoreCase))    { OutMode = ETimeTransitionMode::Slow;    return true; }
	if (Text.Equals(TEXT("fast"), ESearchCase::IgnoreCase))    { OutMode = ETimeTransitionMode::Fast;    return true; }
	if (Text.Equals(TEXT("instant"), ESearchCase::IgnoreCase)) { OutMode = ETimeTransitionMode::Instant; return true; }
	return false;
}

FString UTimeOfDaySubsystem::StateToString(ETimeOfDayState State)
{
	return State == ETimeOfDayState::None
		? FString(TEXT("Level Lighting"))
		: StaticEnum<ETimeOfDayState>()->GetNameStringByValue(static_cast<int64>(State));
}

// --------------------------------------------------------------------------
// Console commands: type these in the PIE console (~ key)
// --------------------------------------------------------------------------

namespace TimeOfDay
{
	static UTimeOfDaySubsystem* GetSubsystem(UWorld* World)
	{
		UTimeOfDaySubsystem* Subsystem = World ? World->GetSubsystem<UTimeOfDaySubsystem>() : nullptr;
		if (!Subsystem)
		{
			UE_LOG(LogTimeOfDay, Warning, TEXT("Time of Day commands work while playing (PIE or a packaged game)."));
		}
		return Subsystem;
	}

	static FAutoConsoleCommandWithWorldAndArgs CmdSet(
		TEXT("tod.Set"),
		TEXT("tod.Set <State> [slow|fast|instant]. States: Dawn Morning Noon Day Afternoon Evening Twilight Night Cave InsideLight InsideDark None"),
		FConsoleCommandWithWorldAndArgsDelegate::CreateLambda([](const TArray<FString>& Args, UWorld* World)
		{
			UTimeOfDaySubsystem* Subsystem = GetSubsystem(World);
			if (!Subsystem || Args.Num() == 0)
			{
				return;
			}

			ETimeOfDayState State;
			if (!UTimeOfDaySubsystem::ParseState(Args[0], State))
			{
				UE_LOG(LogTimeOfDay, Warning, TEXT("Unknown time state '%s'."), *Args[0]);
				return;
			}

			ETimeTransitionMode Mode = ETimeTransitionMode::Fast;
			if (Args.Num() > 1)
			{
				UTimeOfDaySubsystem::ParseTransitionMode(Args[1], Mode);
			}

			Subsystem->StopDemoCycle();
			Subsystem->RequestTimeState(State, Mode);
		}));

	static FAutoConsoleCommandWithWorldAndArgs CmdNext(
		TEXT("tod.Next"),
		TEXT("tod.Next [slow|fast|instant]. Step to the next outdoor state."),
		FConsoleCommandWithWorldAndArgsDelegate::CreateLambda([](const TArray<FString>& Args, UWorld* World)
		{
			if (UTimeOfDaySubsystem* Subsystem = GetSubsystem(World))
			{
				ETimeTransitionMode Mode = ETimeTransitionMode::Fast;
				if (Args.Num() > 0)
				{
					UTimeOfDaySubsystem::ParseTransitionMode(Args[0], Mode);
				}
				Subsystem->StopDemoCycle();
				Subsystem->StepTimeState(true, Mode);
			}
		}));

	static FAutoConsoleCommandWithWorldAndArgs CmdPrev(
		TEXT("tod.Prev"),
		TEXT("tod.Prev [slow|fast|instant]. Step to the previous outdoor state."),
		FConsoleCommandWithWorldAndArgsDelegate::CreateLambda([](const TArray<FString>& Args, UWorld* World)
		{
			if (UTimeOfDaySubsystem* Subsystem = GetSubsystem(World))
			{
				ETimeTransitionMode Mode = ETimeTransitionMode::Fast;
				if (Args.Num() > 0)
				{
					UTimeOfDaySubsystem::ParseTransitionMode(Args[0], Mode);
				}
				Subsystem->StopDemoCycle();
				Subsystem->StepTimeState(false, Mode);
			}
		}));

	static FAutoConsoleCommandWithWorldAndArgs CmdDemo(
		TEXT("tod.Demo"),
		TEXT("tod.Demo [HoldSeconds=3] [slow|fast]. Loop Dawn to Night for time-lapse recording. tod.Demo off to stop."),
		FConsoleCommandWithWorldAndArgsDelegate::CreateLambda([](const TArray<FString>& Args, UWorld* World)
		{
			UTimeOfDaySubsystem* Subsystem = GetSubsystem(World);
			if (!Subsystem)
			{
				return;
			}

			if (Args.Num() > 0 && Args[0].Equals(TEXT("off"), ESearchCase::IgnoreCase))
			{
				Subsystem->StopDemoCycle();
				return;
			}

			const float Hold = Args.Num() > 0 ? FCString::Atof(*Args[0]) : 3.f;
			ETimeTransitionMode Mode = ETimeTransitionMode::Slow;
			if (Args.Num() > 1)
			{
				UTimeOfDaySubsystem::ParseTransitionMode(Args[1], Mode);
			}
			Subsystem->StartDemoCycle(Hold, Mode);
		}));

	static FAutoConsoleCommandWithWorldAndArgs CmdDebug(
		TEXT("tod.Debug"),
		TEXT("tod.Debug [0|1]. Toggle the on-screen readout."),
		FConsoleCommandWithWorldAndArgsDelegate::CreateLambda([](const TArray<FString>& Args, UWorld* World)
		{
			if (UTimeOfDaySubsystem* Subsystem = GetSubsystem(World))
			{
				const bool bOn = Args.Num() > 0 ? (FCString::Atoi(*Args[0]) != 0) : !Subsystem->IsDebugReadoutEnabled();
				Subsystem->SetDebugReadoutEnabled(bOn);
			}
		}));

	static FAutoConsoleCommandWithWorldAndArgs CmdHotkeys(
		TEXT("tod.Hotkeys"),
		TEXT("tod.Hotkeys [0|1]. Turn the keyboard shortcuts off or on."),
		FConsoleCommandWithWorldAndArgsDelegate::CreateLambda([](const TArray<FString>& Args, UWorld* World)
		{
			if (UTimeOfDaySubsystem* Subsystem = GetSubsystem(World))
			{
				Subsystem->SetHotkeysEnabled(Args.Num() == 0 || FCString::Atoi(*Args[0]) != 0);
			}
		}));

	static FAutoConsoleCommandWithWorldAndArgs CmdStatus(
		TEXT("tod.Status"),
		TEXT("Log the current time state."),
		FConsoleCommandWithWorldAndArgsDelegate::CreateLambda([](const TArray<FString>& Args, UWorld* World)
		{
			if (UTimeOfDaySubsystem* Subsystem = GetSubsystem(World))
			{
				UE_LOG(LogTimeOfDay, Display, TEXT("%s"), *Subsystem->GetStatusString());
			}
		}));
}
