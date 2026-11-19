// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeTimeOfDay_init() {}
static_assert(!UE_WITH_CONSTINIT_UOBJECT, "This generated code can only be compiled with !UE_WITH_CONSTINIT_OBJECT");
	TIMEOFDAY_API UFunction* Z_Construct_UDelegateFunction_TimeOfDay_OnTimeStateChanged__DelegateSignature(ETypeConstructPhase);
	static FPackageRegistrationInfo Z_Registration_Info_UPackage__Script_TimeOfDay;
	FORCENOINLINE UPackage* Z_Construct_UPackage__Script_TimeOfDay(ETypeConstructPhase)
	{
		if (!Z_Registration_Info_UPackage__Script_TimeOfDay.OuterSingleton)
		{
		static FTypeConstructFunc* SingletonFuncArray[] = {
			(FTypeConstructFunc*)Z_Construct_UDelegateFunction_TimeOfDay_OnTimeStateChanged__DelegateSignature,
		};
		static const UECodeGen_Private::FPackageParams PackageParams = {
			"/Script/TimeOfDay",
			SingletonFuncArray,
			UE_ARRAY_COUNT(SingletonFuncArray),
			PKG_CompiledIn | 0x00000000,
			0x63E66D47,
			0x4775C53E,
			METADATA_PARAMS(0, nullptr)
		};
		UECodeGen_Private::ConstructUPackage(Z_Registration_Info_UPackage__Script_TimeOfDay.OuterSingleton, PackageParams);
	}
	return Z_Registration_Info_UPackage__Script_TimeOfDay.OuterSingleton;
}
static FRegisterCompiledInInfo Z_CompiledInDeferPackage_UPackage__Script_TimeOfDay(Z_Construct_UPackage__Script_TimeOfDay, TEXT("/Script/TimeOfDay"), Z_Registration_Info_UPackage__Script_TimeOfDay, CONSTRUCT_RELOAD_VERSION_INFO(FPackageReloadVersionInfo, 0x63E66D47, 0x4775C53E));
PRAGMA_ENABLE_DEPRECATION_WARNINGS
