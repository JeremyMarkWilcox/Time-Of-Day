#pragma once

#include "CoreMinimal.h"
#include "Engine/DataTable.h"
#include "Generated/GeneratedEnums.h"
#include "TimeOfDayTypes.generated.h"

// TimeOfDaySubsystem uses EC_LightSets directly so it speaks the same enum
// as the event system and data tables.

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
// C++ defaults in TimeOfDaySubsystem::GetPresetForState() serve as fallback for any state
// not present in the table or in the FTimeOfDayConfig override map.
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

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Sun")
	float Exposure = 0.f;

	// --- Sky Light ---

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Sky")
	float SkyLightIntensity = 1.f;

	// --- Sky Sphere (BP_Sky_Sphere) ---

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Sky Sphere")
	float SkySunBrightness = 0.5f;

	// 0 = horizon, 1 = zenith. Drives BP_Sky_Sphere's color curve sampling.
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Sky Sphere")
	float SkySunHeight = 0.5f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Sky Sphere")
	float SkyCloudOpacity = 0.5f;

	// When true, sky sphere derives colors from curves based on sun height (outdoor states).
	// Set false for Cave/InsideLight/InsideDark where no sky is visible.
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Sky Sphere")
	bool bSkyColorsByPosition = true;

	// --- Fog (Exponential Height Fog) ---

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Fog")
	float FogDensity = 0.02f;

	// --- Moon Light ---

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Moon")
	float MoonIntensity = 0.f;
};

// Config passed to TimeOfDaySubsystem::Initialize on level entry.
USTRUCT(BlueprintType)
struct FTimeOfDayConfig
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Time Of Day|Init")
	EC_LightSets DefaultTimeState = EC_LightSets::Day;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Time Of Day|Init")
	bool bAllowLightWisp = true;

	// Per-state lighting presets. States not present here use built-in defaults.
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Time Of Day|Init")
	TMap<EC_LightSets, FTimeStatePreset> TimeStatePresets;
};
