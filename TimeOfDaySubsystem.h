#pragma once

#include "CoreMinimal.h"
#include "Subsystems/WorldSubsystem.h"
#include "Generated/GeneratedEnums.h"
#include "TimeOfDay/TimeOfDayTypes.h"
#include "TimeOfDay/SkySphereInterface.h"
#include "TimeOfDaySubsystem.generated.h"

class ALightWisp;
class AHFPlayerCharacter;
class ADirectionalLight;
class ASkyLight;
class UPartyComponent;
class UDataTable;

/*
 * TimeOfDaySubsystem
 *
 * UTickableWorldSubsystem that manages discrete time-of-day states, smooth lighting
 * transitions, and an optional Light Wisp companion actor.
 *
 * Design notes:
 *   - World subsystem: zero-dependency access from anywhere in the world via
 *     GetWorld()->GetSubsystem<UTimeOfDaySubsystem>().
 *   - Data-table-driven: per-state presets (FTimeStatePreset) can be authored in a UDataTable
 *     asset and supplied at Initialize time — no code changes needed to tune lighting values.
 *   - C++ fallback defaults in GetPresetForState() guarantee the system runs without a data table.
 *   - Cinematic lock: CinematicBeginOverride prevents gate/gameplay state changes from
 *     overriding lighting during a cutscene. Auto-releases after CinematicLockTimeoutSeconds
 *     as a safeguard if CinematicEndOverride is never called.
 *   - Transitions lerp all float lighting properties each tick; the sky recapture is deferred
 *     to the end of the transition to avoid per-frame GPU cost.
 */
UCLASS(BlueprintType)
class HVFALPHA_API UTimeOfDaySubsystem : public UTickableWorldSubsystem
{
	GENERATED_BODY()

public:

	// Called by the level manager on world entry to configure lighting for this level.
	// Auto-discovers DirectionalLight, SkyLight, SkySphere (via interface), and HeightFog from the world.
	// LightingPresets and WispClass cannot be auto-discovered and must be supplied.
	// MoonLight is optional — pass the actor if the level has a moon light, nullptr otherwise.
	UFUNCTION(BlueprintCallable, Category = "Time Of Day")
	void Initialize(const FTimeOfDayConfig& Config,
	                TSubclassOf<ALightWisp> InWispClass,
	                UDataTable* InLightingPresets = nullptr,
	                AActor* InMoonLight = nullptr);

	// Cinematic control. Lock prevents gate/gameplay changes from overriding lighting during a cutscene.
	// Auto-releases after CinematicLockTimeoutSeconds if CinematicEndOverride is never called.
	UFUNCTION(BlueprintCallable, Category = "Time Of Day")
	void CinematicBeginOverride(EC_LightSets OverrideState, ETimeTransitionMode TransitionMode, bool bForceLightWisp, bool bLightWispEnabled);

	UFUNCTION(BlueprintCallable, Category = "Time Of Day")
	void CinematicEndOverride();

	// Called after a game load to restore the saved time state.
	UFUNCTION(BlueprintCallable, Category = "Time Of Day")
	void RestoreTimeState(EC_LightSets SavedState);

	// Set time state directly — use for testing and gameplay triggers.
	UFUNCTION(BlueprintCallable, Category = "Time Of Day")
	void RequestTimeState(EC_LightSets NewState, ETimeTransitionMode TransitionMode = ETimeTransitionMode::Instant);

	UFUNCTION(BlueprintPure)
	EC_LightSets GetCurrentTimeState() const { return CurrentTimeState; }

	UFUNCTION(BlueprintPure)
	bool IsInitialized() const { return bInitialized; }

	// UTickableWorldSubsystem
	virtual void Tick(float DeltaTime) override;
	virtual TStatId GetStatId() const override;

protected:

	virtual void OnWorldBeginPlay(UWorld& InWorld) override;

private:

	void SetTimeState(EC_LightSets NewState, ETimeTransitionMode TransitionMode);
	void ApplyPresetToLights(const FTimeStatePreset& Preset, bool bRecaptureSky);
	void TickTransition(float DeltaTime);
	FTimeStatePreset GetPresetForState(EC_LightSets State) const;
	FTimeStatePreset LerpPresets(const FTimeStatePreset& A, const FTimeStatePreset& B, float Alpha) const;

	UFUNCTION(BlueprintCallable, Category = "Time Of Day")
	void SetLightWispEnabled(bool bEnabled);
	void OnPostPartyLeaderChanged(AHFPlayerCharacter* NewLeader);

	void AutoReleaseCinematicLock();

	// Lighting actor refs — set by Initialize
	UPROPERTY()
	TObjectPtr<ADirectionalLight> DirectionalLight;

	UPROPERTY()
	TObjectPtr<ASkyLight> SkyLight;

	// Optional actors — null-checked before use
	UPROPERTY()
	TObjectPtr<AActor> SkySphere;

	UPROPERTY()
	TObjectPtr<AActor> MoonLight;

	UPROPERTY()
	TObjectPtr<AActor> HeightFog;

	// Wisp
	UPROPERTY()
	TObjectPtr<ALightWisp> ActiveWisp;

	TSubclassOf<ALightWisp> WispClass;

	float FastTransitionDuration = 1.5f;
	float SlowTransitionDuration = 10.f;
	float TransitionDuration = 1.5f;

	// State
	EC_LightSets CurrentTimeState = EC_LightSets::Day;

	bool bInitialized = false;
	bool bLightWispAllowed = false;
	bool bLightWispActive = false;
	bool bCinematicLock = false;

	// Per-state presets supplied by the initializer
	TMap<EC_LightSets, FTimeStatePreset> TimeStatePresets;

	// Active transition state
	bool bTransitionActive = false;
	float TransitionElapsed = 0.f;
	FTimeStatePreset TransitionFrom;
	FTimeStatePreset TransitionTo;
	EC_LightSets TransitionTargetState = EC_LightSets::Day;

	// Cinematic auto-release timer — fires if CinematicEndOverride is never called
	FTimerHandle CinematicLockTimerHandle;
	float CinematicLockTimeoutSeconds = 30.f;

	// Party component for wisp leader-change binding
	UPROPERTY()
	TObjectPtr<UPartyComponent> CachedPartyComponent;
};
