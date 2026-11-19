#pragma once

#include "CoreMinimal.h"
#include "Engine/DataTable.h"
#include "GameFramework/Actor.h"
#include "TimeOfDayTypes.generated.h"

// Discrete lighting states. Data table rows are matched to these by name
// (a row named "Dawn" overrides the Dawn preset).
// None means "the level's own lighting": the subsystem captures it when it first
// initializes, so a scene keeps its authored look until a state is requested.
UENUM(BlueprintType)
enum class ETimeOfDayState : uint8
{
	None        UMETA(DisplayName = "None (Level Lighting)"),
	Dawn        UMETA(DisplayName = "Dawn"),
	Morning     UMETA(DisplayName = "Morning"),
	Noon        UMETA(DisplayName = "Noon"),
	Day         UMETA(DisplayName = "Day"),
	Afternoon   UMETA(DisplayName = "Afternoon"),
	Evening     UMETA(DisplayName = "Evening"),
	Twilight    UMETA(DisplayName = "Twilight"),
	Night       UMETA(DisplayName = "Night"),
	Cave        UMETA(DisplayName = "Cave"),
	InsideLight UMETA(DisplayName = "Inside (Light)"),
	InsideDark  UMETA(DisplayName = "Inside (Dark)")
};

UENUM(BlueprintType)
enum class ETimeTransitionMode : uint8
{
	None    UMETA(DisplayName = "None"),
	Instant UMETA(DisplayName = "Instant"),
	Fast    UMETA(DisplayName = "Fast"),
	Slow    UMETA(DisplayName = "Slow")
};

// Lighting properties for a single time state.
// Inherits FTableRowBase so it can be authored in a UDataTable asset (DT_LightingPresets).
// C++ defaults in UTimeOfDaySubsystem::GetPresetForState() are the fallback for any state
// not present in the table or in FTimeOfDayConfig::TimeStatePresets.
USTRUCT(BlueprintType)
struct FTimeStatePreset : public FTableRowBase
{
	GENERATED_BODY()

	// --- Sun (Directional Light) ---

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Sun")
	FRotator SunRotation = FRotator(-45.f, 0.f, 0.f);

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Sun")
	float LightBrightness = 10.f;

	// Color temperature in Kelvin. Lower = warmer (dawn/dusk), higher = cooler (noon/night).
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Sun")
	float LightTemperature = 6500.f;

	// Exposure compensation in stops, applied to the level's unbound Post Process Volume.
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Sun")
	float Exposure = 0.f;

	// --- Sky Light ---

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Sky")
	float SkyLightIntensity = 1.f;

	// --- Sky Sphere (optional, see ISkySphereInterface) ---

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Sky Sphere")
	float SkySunBrightness = 0.5f;

	// 0 = horizon, 1 = zenith. Drives a sky sphere's color curve sampling.
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Sky Sphere")
	float SkySunHeight = 0.5f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Sky Sphere")
	float SkyCloudOpacity = 0.5f;

	// When true, the sky sphere derives colors from sun height (outdoor states).
	// Set false for Cave/InsideLight/InsideDark where no sky is visible.
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Sky Sphere")
	bool bSkyColorsByPosition = true;

	// --- Fog (Exponential Height Fog) ---

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Fog")
	float FogDensity = 0.02f;

	// --- Moon Light (optional actor) ---

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Moon")
	float MoonIntensity = 0.f;
};

// Config passed to UTimeOfDaySubsystem::InitializeTimeOfDay on level entry.
USTRUCT(BlueprintType)
struct FTimeOfDayConfig
{
	GENERATED_BODY()

	// State applied on initialize. Leave as None to keep the level's own lighting until a state is requested.
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Time Of Day|Init")
	ETimeOfDayState DefaultTimeState = ETimeOfDayState::None;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Time Of Day|Init", meta = (ClampMin = "0.1"))
	float FastTransitionSeconds = 1.5f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Time Of Day|Init", meta = (ClampMin = "0.1"))
	float SlowTransitionSeconds = 10.f;

	// Safety net: the cinematic lock releases itself after this long if CinematicEndOverride is never called.
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Time Of Day|Init", meta = (ClampMin = "1.0"))
	float CinematicLockTimeoutSeconds = 30.f;

	// Optional companion light (for example a glowing wisp) that follows the player pawn when enabled.
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Time Of Day|Companion")
	bool bAllowCompanionLight = false;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Time Of Day|Companion", meta = (EditCondition = "bAllowCompanionLight"))
	TSubclassOf<AActor> CompanionLightClass;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Time Of Day|Companion", meta = (EditCondition = "bAllowCompanionLight"))
	FVector CompanionOffset = FVector(-60.f, 40.f, 90.f);

	// Per-state presets. States not present here (or in the data table) use built-in defaults.
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Time Of Day|Init")
	TMap<ETimeOfDayState, FTimeStatePreset> TimeStatePresets;
};
