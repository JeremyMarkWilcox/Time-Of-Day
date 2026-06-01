#include "TimeOfDay/TimeOfDaySubsystem.h"
#include "Actors/LightWisp.h"
#include "ActorComponents/PartyComponent.h"
#include "Caravan/Caravan.h"
#include "Character/HFPlayerCharacter.h"
#include "Components/DirectionalLightComponent.h"
#include "Components/ExponentialHeightFogComponent.h"
#include "Components/LightComponent.h"
#include "Components/SkyLightComponent.h"
#include "Engine/DirectionalLight.h"
#include "Engine/ExponentialHeightFog.h"
#include "Engine/SkyLight.h"
#include "Kismet/GameplayStatics.h"
#include "Engine/DataTable.h"

// --------------------------------------------------------------------------
// UTickableWorldSubsystem interface
// --------------------------------------------------------------------------

TStatId UTimeOfDaySubsystem::GetStatId() const
{
	RETURN_QUICK_DECLARE_CYCLE_STAT(UTimeOfDaySubsystem, STATGROUP_Tickables);
}

void UTimeOfDaySubsystem::OnWorldBeginPlay(UWorld& InWorld)
{
	Super::OnWorldBeginPlay(InWorld);

	// Bind to party leader changes so the wisp can smoothly reattach.
	// Done here (after all BeginPlays) so the Caravan is guaranteed to exist.
	if (ACaravan* Caravan = Cast<ACaravan>(UGameplayStatics::GetActorOfClass(&InWorld, ACaravan::StaticClass())))
	{
		if (UPartyComponent* Party = Caravan->FindComponentByClass<UPartyComponent>())
		{
			CachedPartyComponent = Party;
			Party->PostPartyLeaderChange.AddUObject(this, &UTimeOfDaySubsystem::OnPostPartyLeaderChanged);
		}
	}
}

void UTimeOfDaySubsystem::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	if (bTransitionActive)
	{
		TickTransition(DeltaTime);
	}
}

// --------------------------------------------------------------------------
// Public API
// --------------------------------------------------------------------------

void UTimeOfDaySubsystem::Initialize(const FTimeOfDayConfig& Config,
                                     TSubclassOf<ALightWisp> InWispClass,
                                     UDataTable* InLightingPresets,
                                     AActor* InMoonLight)
{
	UWorld* World = GetWorld();

	// Auto-discover world lighting actors so the level manager doesn't need to gather and pass them.
	DirectionalLight = Cast<ADirectionalLight>(UGameplayStatics::GetActorOfClass(World, ADirectionalLight::StaticClass()));
	SkyLight         = Cast<ASkyLight>(UGameplayStatics::GetActorOfClass(World, ASkyLight::StaticClass()));
	HeightFog        = UGameplayStatics::GetActorOfClass(World, AExponentialHeightFog::StaticClass());
	MoonLight        = InMoonLight;

	// SkySphere is identified by the interface it implements — not by a specific class.
	TArray<AActor*> SkySphereActors;
	UGameplayStatics::GetAllActorsWithInterface(World, USkySphereInterface::StaticClass(), SkySphereActors);
	SkySphere = SkySphereActors.Num() > 0 ? SkySphereActors[0] : nullptr;

	WispClass         = InWispClass;
	TimeStatePresets  = Config.TimeStatePresets;
	bLightWispAllowed = Config.bAllowLightWisp;
	bInitialized      = true;

	// Load per-state presets from data table — overrides Config.TimeStatePresets for matching states
	if (InLightingPresets)
	{
		for (const FName& RowName : InLightingPresets->GetRowNames())
		{
			if (FTimeStatePreset* Row = InLightingPresets->FindRow<FTimeStatePreset>(RowName, TEXT("")))
			{
				const int64 EnumVal = StaticEnum<EC_LightSets>()->GetValueByName(RowName);
				if (EnumVal != INDEX_NONE)
				{
					TimeStatePresets.Add(static_cast<EC_LightSets>(EnumVal), *Row);
				}
			}
		}
	}

	// Apply default state immediately. RestoreTimeState may override this after a load.
	SetTimeState(Config.DefaultTimeState, ETimeTransitionMode::Instant);
}

void UTimeOfDaySubsystem::RequestTimeState(EC_LightSets NewState, ETimeTransitionMode TransitionMode)
{
	if (!bInitialized || bCinematicLock)
	{
		return;
	}

	SetTimeState(NewState, TransitionMode);
}

void UTimeOfDaySubsystem::CinematicBeginOverride(EC_LightSets OverrideState, ETimeTransitionMode TransitionMode, bool bForceLightWisp, bool bLightWispEnabled)
{
	if (!bInitialized)
	{
		return;
	}

	bCinematicLock = true;
	SetTimeState(OverrideState, TransitionMode);

	if (bForceLightWisp)
	{
		SetLightWispEnabled(bLightWispEnabled);
	}

	// Auto-release fallback in case CinematicEndOverride is never called
	if (UWorld* World = GetWorld())
	{
		World->GetTimerManager().SetTimer(
			CinematicLockTimerHandle,
			this,
			&UTimeOfDaySubsystem::AutoReleaseCinematicLock,
			CinematicLockTimeoutSeconds,
			false
		);
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

void UTimeOfDaySubsystem::RestoreTimeState(EC_LightSets SavedState)
{
	if (!bInitialized)
	{
		return;
	}

	// Snap — no transition on load
	SetTimeState(SavedState, ETimeTransitionMode::Instant);
}

// --------------------------------------------------------------------------
// Private — state & lighting
// --------------------------------------------------------------------------

void UTimeOfDaySubsystem::SetTimeState(EC_LightSets NewState, ETimeTransitionMode TransitionMode)
{
	if (TransitionMode == ETimeTransitionMode::Instant || TransitionMode == ETimeTransitionMode::None)
	{
		bTransitionActive = false;
		CurrentTimeState  = NewState;
		ApplyPresetToLights(GetPresetForState(NewState), true);
	}
	else
	{
		TransitionFrom        = GetPresetForState(CurrentTimeState);
		TransitionTo          = GetPresetForState(NewState);
		TransitionTargetState = NewState;
		TransitionElapsed     = 0.f;
		TransitionDuration    = (TransitionMode == ETimeTransitionMode::Slow) ? SlowTransitionDuration : FastTransitionDuration;
		bTransitionActive     = true;
	}
}

void UTimeOfDaySubsystem::ApplyPresetToLights(const FTimeStatePreset& Preset, bool bRecaptureSky)
{
	if (DirectionalLight)
	{
		DirectionalLight->SetActorRotation(Preset.SunRotation);

		if (UDirectionalLightComponent* DLC = Cast<UDirectionalLightComponent>(DirectionalLight->GetLightComponent()))
		{
			DLC->SetIntensity(Preset.LightBrightness);
			DLC->bUseTemperature = true;
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

	// Sky Sphere — DirectionalLight rotation is already set above, so UpdateSunDirection
	// (called inside the BP implementation) will read the correct value.
	// RefreshSkySphere is called separately so the BP can push changes to the dome material.
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

	// Moon Light
	if (MoonLight)
	{
		if (ULightComponent* LC = MoonLight->FindComponentByClass<ULightComponent>())
		{
			LC->SetIntensity(Preset.MoonIntensity);
		}
	}

	// Exponential Height Fog
	if (HeightFog)
	{
		if (UExponentialHeightFogComponent* FogComp = HeightFog->FindComponentByClass<UExponentialHeightFogComponent>())
		{
			FogComp->SetFogDensity(Preset.FogDensity);
		}
	}
}

void UTimeOfDaySubsystem::TickTransition(float DeltaTime)
{
	TransitionElapsed += DeltaTime;
	const float Alpha = FMath::Clamp(TransitionElapsed / TransitionDuration, 0.f, 1.f);
	const FTimeStatePreset Blended = LerpPresets(TransitionFrom, TransitionTo, Alpha);

	// Skip sky recapture on every tick — only do it once at the end
	ApplyPresetToLights(Blended, false);

	if (Alpha >= 1.f)
	{
		bTransitionActive = false;
		CurrentTimeState  = TransitionTargetState;
		ApplyPresetToLights(GetPresetForState(CurrentTimeState), true);
	}
}

FTimeStatePreset UTimeOfDaySubsystem::GetPresetForState(EC_LightSets State) const
{
	if (const FTimeStatePreset* Preset = TimeStatePresets.Find(State))
	{
		return *Preset;
	}

	// Built-in fallback defaults — designers should override these via the initializer
	FTimeStatePreset Default;
	switch (State)
	{
	case EC_LightSets::Dawn:
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
	case EC_LightSets::Morning:
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
	case EC_LightSets::Noon:
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
	case EC_LightSets::Day:
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
	case EC_LightSets::Afternoon:
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
	case EC_LightSets::Evening:
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
	case EC_LightSets::Night:
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
	case EC_LightSets::Twilight:
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
	case EC_LightSets::Cave:
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
	case EC_LightSets::InsideLight:
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
	case EC_LightSets::InsideDark:
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
	case EC_LightSets::NONE:
	case EC_LightSets::_Custom:
	default:
		break;
	}
	return Default;
}

FTimeStatePreset UTimeOfDaySubsystem::LerpPresets(const FTimeStatePreset& A, const FTimeStatePreset& B, float Alpha) const
{
	FTimeStatePreset Result;
	Result.SunRotation = FRotator(
		FMath::Lerp(A.SunRotation.Pitch, B.SunRotation.Pitch, Alpha),
		FMath::Lerp(A.SunRotation.Yaw,   B.SunRotation.Yaw,   Alpha),
		FMath::Lerp(A.SunRotation.Roll,  B.SunRotation.Roll,  Alpha)
	);
	Result.LightBrightness   = FMath::Lerp(A.LightBrightness,   B.LightBrightness,   Alpha);
	Result.LightTemperature  = FMath::Lerp(A.LightTemperature,  B.LightTemperature,  Alpha);
	Result.Exposure          = FMath::Lerp(A.Exposure,          B.Exposure,          Alpha);
	Result.SkyLightIntensity = FMath::Lerp(A.SkyLightIntensity, B.SkyLightIntensity, Alpha);
	Result.SkySunBrightness  = FMath::Lerp(A.SkySunBrightness,  B.SkySunBrightness,  Alpha);
	Result.SkySunHeight      = FMath::Lerp(A.SkySunHeight,      B.SkySunHeight,      Alpha);
	Result.SkyCloudOpacity   = FMath::Lerp(A.SkyCloudOpacity,   B.SkyCloudOpacity,   Alpha);
	Result.FogDensity        = FMath::Lerp(A.FogDensity,        B.FogDensity,        Alpha);
	Result.MoonIntensity     = FMath::Lerp(A.MoonIntensity,     B.MoonIntensity,     Alpha);
	// Bool: hold From value during transition, snap to To at completion
	Result.bSkyColorsByPosition = A.bSkyColorsByPosition;
	return Result;
}

// --------------------------------------------------------------------------
// Private — Light Wisp
// --------------------------------------------------------------------------

void UTimeOfDaySubsystem::SetLightWispEnabled(bool bEnabled)
{
	if (bEnabled && !ActiveWisp)
	{
		if (!WispClass)
		{
			return;
		}

		UWorld* World = GetWorld();
		if (!World)
		{
			return;
		}

		ActiveWisp = World->SpawnActor<ALightWisp>(WispClass);
		bLightWispActive = true;

		// Attach to current party leader — fall back to player 0 if party component wasn't cached
		AHFPlayerCharacter* Leader = nullptr;
		if (CachedPartyComponent)
		{
			Leader = CachedPartyComponent->GetCurrentPartyLeader();
		}
		if (!Leader)
		{
			Leader = Cast<AHFPlayerCharacter>(UGameplayStatics::GetPlayerCharacter(World, 0));
		}
		if (Leader)
		{
			ActiveWisp->AttachToLeader(Leader);
		}
	}
	else if (!bEnabled && ActiveWisp)
	{
		ActiveWisp->Despawn();
		ActiveWisp       = nullptr;
		bLightWispActive = false;
	}
}

void UTimeOfDaySubsystem::OnPostPartyLeaderChanged(AHFPlayerCharacter* NewLeader)
{
	if (ActiveWisp && NewLeader)
	{
		ActiveWisp->AttachToLeader(NewLeader);
	}
}

// --------------------------------------------------------------------------
// Private — Cinematic
// --------------------------------------------------------------------------

void UTimeOfDaySubsystem::AutoReleaseCinematicLock()
{
	bCinematicLock = false;
}
