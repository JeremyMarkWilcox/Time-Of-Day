#pragma once

#include "CoreMinimal.h"
#include "Subsystems/WorldSubsystem.h"
#include "TimeOfDayTypes.h"
#include "SkySphereInterface.h"
#include "TimeOfDaySubsystem.generated.h"

class ADirectionalLight;
class ASkyLight;
class APostProcessVolume;
class UDataTable;
class UCanvas;
class APlayerController;

DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnTimeStateChanged, ETimeOfDayState, OldState, ETimeOfDayState, NewState);

/*
 * UTimeOfDaySubsystem
 *
 * World subsystem that manages discrete time-of-day states, smooth lighting transitions,
 * a cinematic lock, and an optional companion light.
 *
 * Design notes:
 *   - World subsystem: access from anywhere via GetWorld()->GetSubsystem<UTimeOfDaySubsystem>().
 *   - Data-table-driven: per-state presets (FTimeStatePreset) can be authored in a UDataTable
 *     and supplied at initialize time, so lighting is tuned without code changes.
 *   - C++ fallback defaults in GetPresetForState() mean the system runs without a data table.
 *   - Captures the level's own lighting on initialize (state None), so a scene keeps its
 *     authored look until a state is requested, and transitions start from what's on screen.
 *   - Cinematic lock: CinematicBeginOverride blocks gameplay state requests during a cutscene,
 *     and auto-releases after a timeout if CinematicEndOverride is never called.
 *   - Transitions blend every lighting property each tick (sun rotation via quaternion slerp);
 *     the sky light recapture is deferred to the end of a transition to avoid per-frame GPU cost.
 *   - Auto-discovery: finds the sun, sky light, height fog, unbound post process volume and an
 *     optional sky sphere (by interface). Tag an actor "TimeOfDaySun" or "TimeOfDayMoon" to pick
 *     a specific light when a level has several.
 *   - Testing tools: console commands (tod.Set, tod.Next, tod.Demo, tod.Debug, tod.Status) and
 *     an on-screen readout, so states can be scrubbed live without any Blueprint wiring.
 */
UCLASS(BlueprintType)
class TIMEOFDAY_API UTimeOfDaySubsystem : public UTickableWorldSubsystem
{
	GENERATED_BODY()

public:

	// Configure lighting for this level. Call from a level Blueprint, game mode or level manager.
	// Not required for testing: any request or console command initializes with defaults on first use.
	UFUNCTION(BlueprintCallable, Category = "Time Of Day")
	void InitializeTimeOfDay(const FTimeOfDayConfig& Config, UDataTable* InLightingPresets = nullptr);

	// Gameplay request. Ignored while the cinematic lock is held.
	UFUNCTION(BlueprintCallable, Category = "Time Of Day")
	void RequestTimeState(ETimeOfDayState NewState, ETimeTransitionMode TransitionMode = ETimeTransitionMode::Fast);

	// Cinematic control. The lock blocks gameplay requests until CinematicEndOverride
	// (or the auto-release timeout).
	UFUNCTION(BlueprintCallable, Category = "Time Of Day")
	void CinematicBeginOverride(ETimeOfDayState OverrideState, ETimeTransitionMode TransitionMode, bool bForceCompanionLight = false, bool bCompanionLightEnabled = false);

	UFUNCTION(BlueprintCallable, Category = "Time Of Day")
	void CinematicEndOverride();

	// Snap to a saved state after a game load (no transition).
	UFUNCTION(BlueprintCallable, Category = "Time Of Day")
	void RestoreTimeState(ETimeOfDayState SavedState);

	UFUNCTION(BlueprintCallable, Category = "Time Of Day")
	void SetCompanionLightEnabled(bool bEnabled);

	// Loops through the outdoor states (Dawn to Night) for time-lapse recording.
	UFUNCTION(BlueprintCallable, Category = "Time Of Day|Debug")
	void StartDemoCycle(float HoldSeconds = 3.f, ETimeTransitionMode TransitionMode = ETimeTransitionMode::Slow);

	UFUNCTION(BlueprintCallable, Category = "Time Of Day|Debug")
	void StopDemoCycle();

	// Steps to the next (or previous) outdoor state.
	UFUNCTION(BlueprintCallable, Category = "Time Of Day|Debug")
	void StepTimeState(bool bForward = true, ETimeTransitionMode TransitionMode = ETimeTransitionMode::Fast);

	// On-screen overlay: current state, transition progress, a timeline of states, live light values and the hotkeys.
	UFUNCTION(BlueprintCallable, Category = "Time Of Day|Debug")
	void SetDebugReadoutEnabled(bool bEnabled) { bShowDebugReadout = bEnabled; }

	UFUNCTION(BlueprintPure, Category = "Time Of Day|Debug")
	bool IsDebugReadoutEnabled() const { return bShowDebugReadout; }

	// Keyboard shortcuts while playing:  ] next  [ previous  (hold Shift for fast)  \ demo loop  ; level lighting  / overlay
	UFUNCTION(BlueprintCallable, Category = "Time Of Day|Debug")
	void SetHotkeysEnabled(bool bEnabled) { bHotkeysEnabled = bEnabled; }

	UFUNCTION(BlueprintPure, Category = "Time Of Day")
	ETimeOfDayState GetCurrentTimeState() const { return CurrentTimeState; }

	UFUNCTION(BlueprintPure, Category = "Time Of Day")
	bool IsTimeOfDayInitialized() const { return bTimeOfDayInitialized; }

	UFUNCTION(BlueprintPure, Category = "Time Of Day")
	bool IsTransitioning() const { return bTransitionActive; }

	UPROPERTY(BlueprintAssignable, Category = "Time Of Day")
	FOnTimeStateChanged OnTimeStateChanged;

	// Helpers shared with the console commands.
	static bool ParseState(const FString& Text, ETimeOfDayState& OutState);
	static bool ParseTransitionMode(const FString& Text, ETimeTransitionMode& OutMode);
	static FString StateToString(ETimeOfDayState State);
	FString GetStatusString() const;

	// UTickableWorldSubsystem
	virtual void Tick(float DeltaTime) override;
	virtual TStatId GetStatId() const override;

protected:

	// Game and PIE worlds only: no lighting changes in editor preview worlds.
	virtual bool DoesSupportWorldType(const EWorldType::Type WorldType) const override;
	virtual void OnWorldBeginPlay(UWorld& InWorld) override;
	virtual void Deinitialize() override;

private:

	void EnsureInitialized();
	void DiscoverLightingActors();
	FTimeStatePreset CaptureCurrentLighting() const;

	void SetTimeState(ETimeOfDayState NewState, ETimeTransitionMode TransitionMode);
	void FinishStateChange(ETimeOfDayState NewState);
	void ApplyPresetToLights(const FTimeStatePreset& Preset, bool bRecaptureSky);
	void TickTransition(float DeltaTime);
	void TickDemoCycle(float DeltaTime);
	void TickHotkeys();
	void DrawOverlay(UCanvas* Canvas, APlayerController* PC);
	FTimeStatePreset GetLivePreset() const;
	FTimeStatePreset GetPresetForState(ETimeOfDayState State) const;
	static FTimeStatePreset LerpPresets(const FTimeStatePreset& A, const FTimeStatePreset& B, float Alpha);

	void AutoReleaseCinematicLock();

	// Lighting actors, auto-discovered
	UPROPERTY()
	TObjectPtr<ADirectionalLight> SunLight;

	UPROPERTY()
	TObjectPtr<ASkyLight> SkyLight;

	UPROPERTY()
	TObjectPtr<AActor> HeightFog;

	UPROPERTY()
	TObjectPtr<APostProcessVolume> PostProcessVolume;

	// Optional actors, null-checked before use
	UPROPERTY()
	TObjectPtr<AActor> SkySphere;

	UPROPERTY()
	TObjectPtr<AActor> MoonLight;

	// Companion light
	UPROPERTY()
	TObjectPtr<AActor> ActiveCompanion;

	UPROPERTY()
	TSubclassOf<AActor> CompanionLightClass;

	FVector CompanionOffset = FVector::ZeroVector;
	bool bCompanionAllowed = false;

	// Timing
	float FastTransitionDuration = 1.5f;
	float SlowTransitionDuration = 10.f;
	float TransitionDuration = 1.5f;
	float CinematicLockTimeoutSeconds = 30.f;

	// State
	ETimeOfDayState CurrentTimeState = ETimeOfDayState::None;
	bool bTimeOfDayInitialized = false;
	bool bCinematicLock = false;

	// The level's lighting as it was when the subsystem initialized (state None)
	FTimeStatePreset LevelLightingPreset;

	// Per-state presets from the config and data table
	TMap<ETimeOfDayState, FTimeStatePreset> TimeStatePresets;

	// Active transition
	bool bTransitionActive = false;
	float TransitionElapsed = 0.f;
	FTimeStatePreset TransitionFrom;
	FTimeStatePreset TransitionTo;
	ETimeOfDayState TransitionTargetState = ETimeOfDayState::None;
	ETimeTransitionMode ActiveTransitionMode = ETimeTransitionMode::Instant;

	// Demo cycle
	bool bDemoCycleActive = false;
	float DemoHoldSeconds = 3.f;
	float DemoHoldElapsed = 0.f;
	ETimeTransitionMode DemoTransitionMode = ETimeTransitionMode::Slow;

	bool bShowDebugReadout = false;
	bool bHotkeysEnabled = true;
	FDelegateHandle OverlayDrawHandle;

	FTimerHandle CinematicLockTimerHandle;
};
