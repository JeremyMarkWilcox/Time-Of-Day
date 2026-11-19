#pragma once

#include "CoreMinimal.h"
#include "UObject/Interface.h"
#include "SkySphereInterface.generated.h"

UINTERFACE(MinimalAPI, BlueprintType)
class USkySphereInterface : public UInterface
{
	GENERATED_BODY()
};

/*
 * Optional. Implement on a sky dome Blueprint (for example BP_Sky_Sphere) to let the
 * TimeOfDaySubsystem drive it. Levels that use Sky Atmosphere instead of a sky sphere
 * (such as Valley of the Ancient) don't need this: the atmosphere follows the sun
 * rotation on its own.
 *
 * TimeOfDaySubsystem calls ApplySkySpherePreset first (after setting the sun rotation),
 * then RefreshSkySphere so the Blueprint can push changes to its dome material.
 */
class TIMEOFDAY_API ISkySphereInterface
{
	GENERATED_BODY()

public:

	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "Time Of Day")
	void ApplySkySpherePreset(float SunBrightness, float SunHeight, float CloudOpacity, bool bColorsByPosition);

	// Called after ApplySkySpherePreset. A BP_Sky_Sphere implementation should call RefreshMaterial here.
	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "Time Of Day")
	void RefreshSkySphere();
};
