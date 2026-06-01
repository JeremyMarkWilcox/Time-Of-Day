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
 * Implemented by BP_Sky_Sphere.
 * TimeOfDaySubsystem calls ApplySkySpherePreset first (after setting the DirectionalLight
 * rotation), then calls RefreshSkySphere to push the changes to the dome material.
 *
 * BP implementation of ApplySkySpherePreset should:
 *   1. Set SunBrightness, SunHeight, CloudOpacity, ColorsDeterminedBySunPos variables
 *   2. Call UpdateSunDirection
 *
 * BP implementation of RefreshSkySphere should:
 *   1. Call RefreshMaterial
 */
class HVFALPHA_API ISkySphereInterface
{
	GENERATED_BODY()

public:

	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "Time Of Day")
	void ApplySkySpherePreset(float SunBrightness, float SunHeight, float CloudOpacity, bool bColorsByPosition);

	// Called after ApplySkySpherePreset — BP should call RefreshMaterial here.
	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "Time Of Day")
	void RefreshSkySphere();
};
