// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "TimeOfDayTypes.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
static_assert(!UE_WITH_CONSTINIT_UOBJECT, "This generated code can only be compiled with !UE_WITH_CONSTINIT_UOBJECT");
void EmptyLinkFunctionForGeneratedCodeTimeOfDayTypes() {}

// ********** Begin Cross Module References ********************************************************
COREUOBJECT_API UScriptStruct* Z_Construct_UScriptStruct_FRotator(ETypeConstructPhase);
COREUOBJECT_API UScriptStruct* Z_Construct_UScriptStruct_FVector(ETypeConstructPhase);
ENGINE_API UScriptStruct* Z_Construct_UScriptStruct_FTableRowBase(ETypeConstructPhase);
COREUOBJECT_API UClass* Z_Construct_UClass_UClass(ETypeConstructPhase);
ENGINE_API UClass* Z_Construct_UClass_AActor(ETypeConstructPhase);
// ********** End Cross Module References **********************************************************

// ********** Begin Same Module References *********************************************************
UPackage* Z_Construct_UPackage__Script_TimeOfDay(ETypeConstructPhase);
TIMEOFDAY_API UEnum* Z_Construct_UEnum_TimeOfDay_ETimeOfDayState(ETypeConstructPhase);
TIMEOFDAY_API UEnum* Z_Construct_UEnum_TimeOfDay_ETimeTransitionMode(ETypeConstructPhase);
TIMEOFDAY_API UScriptStruct* Z_Construct_UScriptStruct_FTimeOfDayConfig(ETypeConstructPhase);
TIMEOFDAY_API UScriptStruct* Z_Construct_UScriptStruct_FTimeStatePreset(ETypeConstructPhase);
// ********** End Same Module References ***********************************************************
#define UHT_STRUCT_BASE(INIT) UE::CodeGen::ConstInit::TCompiledInObjectPtr<const FStructBaseChain>(UE::Private::AsStructBaseChain(INIT))

// ********** Begin Enum ETimeOfDayState ***********************************************************
#ifdef UHT_STATICS
#error UHT_STATICS already defined
#endif
#define UHT_STATICS Z_Construct_UEnum_TimeOfDay_ETimeOfDayState_Statics
template<> TIMEOFDAY_NON_ATTRIBUTED_API UEnum* StaticEnum<ETimeOfDayState>()
{
	return Z_Construct_UEnum_TimeOfDay_ETimeOfDayState(ETypeConstructPhase::Outer);
}
struct UHT_STATICS
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Type_MetaData[] = {
		{ "Afternoon.DisplayName", "Afternoon" },
		{ "Afternoon.Name", "ETimeOfDayState::Afternoon" },
		{ "BlueprintType", "true" },
		{ "Cave.DisplayName", "Cave" },
		{ "Cave.Name", "ETimeOfDayState::Cave" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "// Discrete lighting states. Data table rows are matched to these by name\n// (a row named \"Dawn\" overrides the Dawn preset).\n// None means \"the level's own lighting\": the subsystem captures it when it first\n// initializes, so a scene keeps its authored look until a state is requested.\n" },
#endif
		{ "Dawn.DisplayName", "Dawn" },
		{ "Dawn.Name", "ETimeOfDayState::Dawn" },
		{ "Day.DisplayName", "Day" },
		{ "Day.Name", "ETimeOfDayState::Day" },
		{ "Evening.DisplayName", "Evening" },
		{ "Evening.Name", "ETimeOfDayState::Evening" },
		{ "InsideDark.DisplayName", "Inside (Dark)" },
		{ "InsideDark.Name", "ETimeOfDayState::InsideDark" },
		{ "InsideLight.DisplayName", "Inside (Light)" },
		{ "InsideLight.Name", "ETimeOfDayState::InsideLight" },
		{ "ModuleRelativePath", "Public/TimeOfDayTypes.h" },
		{ "Morning.DisplayName", "Morning" },
		{ "Morning.Name", "ETimeOfDayState::Morning" },
		{ "Night.DisplayName", "Night" },
		{ "Night.Name", "ETimeOfDayState::Night" },
		{ "None.DisplayName", "None (Level Lighting)" },
		{ "None.Name", "ETimeOfDayState::None" },
		{ "Noon.DisplayName", "Noon" },
		{ "Noon.Name", "ETimeOfDayState::Noon" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Discrete lighting states. Data table rows are matched to these by name\n(a row named \"Dawn\" overrides the Dawn preset).\nNone means \"the level's own lighting\": the subsystem captures it when it first\ninitializes, so a scene keeps its authored look until a state is requested." },
#endif
		{ "Twilight.DisplayName", "Twilight" },
		{ "Twilight.Name", "ETimeOfDayState::Twilight" },
	};
#endif // WITH_METADATA
	static constexpr UECodeGen_Private::FEnumeratorParam Enumerators[] = {
		{ "ETimeOfDayState::None", (int64)ETimeOfDayState::None },
		{ "ETimeOfDayState::Dawn", (int64)ETimeOfDayState::Dawn },
		{ "ETimeOfDayState::Morning", (int64)ETimeOfDayState::Morning },
		{ "ETimeOfDayState::Noon", (int64)ETimeOfDayState::Noon },
		{ "ETimeOfDayState::Day", (int64)ETimeOfDayState::Day },
		{ "ETimeOfDayState::Afternoon", (int64)ETimeOfDayState::Afternoon },
		{ "ETimeOfDayState::Evening", (int64)ETimeOfDayState::Evening },
		{ "ETimeOfDayState::Twilight", (int64)ETimeOfDayState::Twilight },
		{ "ETimeOfDayState::Night", (int64)ETimeOfDayState::Night },
		{ "ETimeOfDayState::Cave", (int64)ETimeOfDayState::Cave },
		{ "ETimeOfDayState::InsideLight", (int64)ETimeOfDayState::InsideLight },
		{ "ETimeOfDayState::InsideDark", (int64)ETimeOfDayState::InsideDark },
	};
	static const UECodeGen_Private::FEnumParams EnumParams;
}; // struct UHT_STATICS 
const UECodeGen_Private::FEnumParams UHT_STATICS::EnumParams = {
	(FTypeConstructFunc*)Z_Construct_UPackage__Script_TimeOfDay,
	nullptr,
	"ETimeOfDayState",
	"ETimeOfDayState",
	UHT_STATICS::Enumerators,
	RF_Public|RF_Transient|RF_MarkAsNative,
	UE_ARRAY_COUNT(UHT_STATICS::Enumerators),
	EEnumFlags::None,
	(uint8)UEnum::ECppForm::EnumClass,
	(uint8)UEnum::EUnderlyingType::uint8,
	METADATA_PARAMS(UE_ARRAY_COUNT(UHT_STATICS::Type_MetaData), UHT_STATICS::Type_MetaData)
};
static FEnumRegistrationInfo ZRIE_ETimeOfDayState;
UEnum* Z_Construct_UEnum_TimeOfDay_ETimeOfDayState(ETypeConstructPhase Phase)
{
	if (Phase == ETypeConstructPhase::Outer)
	{
		if (!ZRIE_ETimeOfDayState.OuterSingleton)
		{
			ZRIE_ETimeOfDayState.OuterSingleton = GetStaticEnum(Z_Construct_UEnum_TimeOfDay_ETimeOfDayState, (UObject*)Z_Construct_UPackage__Script_TimeOfDay(ETypeConstructPhase::Outer), TEXT("ETimeOfDayState"));
		}
		return ZRIE_ETimeOfDayState.OuterSingleton;
	}
	if (!ZRIE_ETimeOfDayState.InnerSingleton)
	{
		UECodeGen_Private::ConstructUEnum(ZRIE_ETimeOfDayState.InnerSingleton, UHT_STATICS::EnumParams);
	}
	return ZRIE_ETimeOfDayState.InnerSingleton;
}
#undef UHT_STATICS
// ********** End Enum ETimeOfDayState *************************************************************

// ********** Begin Enum ETimeTransitionMode *******************************************************
#ifdef UHT_STATICS
#error UHT_STATICS already defined
#endif
#define UHT_STATICS Z_Construct_UEnum_TimeOfDay_ETimeTransitionMode_Statics
template<> TIMEOFDAY_NON_ATTRIBUTED_API UEnum* StaticEnum<ETimeTransitionMode>()
{
	return Z_Construct_UEnum_TimeOfDay_ETimeTransitionMode(ETypeConstructPhase::Outer);
}
struct UHT_STATICS
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Type_MetaData[] = {
		{ "BlueprintType", "true" },
		{ "Fast.DisplayName", "Fast" },
		{ "Fast.Name", "ETimeTransitionMode::Fast" },
		{ "Instant.DisplayName", "Instant" },
		{ "Instant.Name", "ETimeTransitionMode::Instant" },
		{ "ModuleRelativePath", "Public/TimeOfDayTypes.h" },
		{ "None.DisplayName", "None" },
		{ "None.Name", "ETimeTransitionMode::None" },
		{ "Slow.DisplayName", "Slow" },
		{ "Slow.Name", "ETimeTransitionMode::Slow" },
	};
#endif // WITH_METADATA
	static constexpr UECodeGen_Private::FEnumeratorParam Enumerators[] = {
		{ "ETimeTransitionMode::None", (int64)ETimeTransitionMode::None },
		{ "ETimeTransitionMode::Instant", (int64)ETimeTransitionMode::Instant },
		{ "ETimeTransitionMode::Fast", (int64)ETimeTransitionMode::Fast },
		{ "ETimeTransitionMode::Slow", (int64)ETimeTransitionMode::Slow },
	};
	static const UECodeGen_Private::FEnumParams EnumParams;
}; // struct UHT_STATICS 
const UECodeGen_Private::FEnumParams UHT_STATICS::EnumParams = {
	(FTypeConstructFunc*)Z_Construct_UPackage__Script_TimeOfDay,
	nullptr,
	"ETimeTransitionMode",
	"ETimeTransitionMode",
	UHT_STATICS::Enumerators,
	RF_Public|RF_Transient|RF_MarkAsNative,
	UE_ARRAY_COUNT(UHT_STATICS::Enumerators),
	EEnumFlags::None,
	(uint8)UEnum::ECppForm::EnumClass,
	(uint8)UEnum::EUnderlyingType::uint8,
	METADATA_PARAMS(UE_ARRAY_COUNT(UHT_STATICS::Type_MetaData), UHT_STATICS::Type_MetaData)
};
static FEnumRegistrationInfo ZRIE_ETimeTransitionMode;
UEnum* Z_Construct_UEnum_TimeOfDay_ETimeTransitionMode(ETypeConstructPhase Phase)
{
	if (Phase == ETypeConstructPhase::Outer)
	{
		if (!ZRIE_ETimeTransitionMode.OuterSingleton)
		{
			ZRIE_ETimeTransitionMode.OuterSingleton = GetStaticEnum(Z_Construct_UEnum_TimeOfDay_ETimeTransitionMode, (UObject*)Z_Construct_UPackage__Script_TimeOfDay(ETypeConstructPhase::Outer), TEXT("ETimeTransitionMode"));
		}
		return ZRIE_ETimeTransitionMode.OuterSingleton;
	}
	if (!ZRIE_ETimeTransitionMode.InnerSingleton)
	{
		UECodeGen_Private::ConstructUEnum(ZRIE_ETimeTransitionMode.InnerSingleton, UHT_STATICS::EnumParams);
	}
	return ZRIE_ETimeTransitionMode.InnerSingleton;
}
#undef UHT_STATICS
// ********** End Enum ETimeTransitionMode *********************************************************

// ********** Begin ScriptStruct FTimeStatePreset **************************************************
#ifdef UHT_STATICS
#error UHT_STATICS already defined
#endif
#define UHT_STATICS Z_Construct_UScriptStruct_FTimeStatePreset_Statics
struct UHT_STATICS
{
	static inline consteval int32 GetStructSize() { return DataSizeOf<FTimeStatePreset>(); }
	static inline consteval int16 GetStructAlignment() { return alignof(FTimeStatePreset); }
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Type_MetaData[] = {
		{ "BlueprintType", "true" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "// Lighting properties for a single time state.\n// Inherits FTableRowBase so it can be authored in a UDataTable asset (DT_LightingPresets).\n// C++ defaults in UTimeOfDaySubsystem::GetPresetForState() are the fallback for any state\n// not present in the table or in FTimeOfDayConfig::TimeStatePresets.\n" },
#endif
		{ "ModuleRelativePath", "Public/TimeOfDayTypes.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Lighting properties for a single time state.\nInherits FTableRowBase so it can be authored in a UDataTable asset (DT_LightingPresets).\nC++ defaults in UTimeOfDaySubsystem::GetPresetForState() are the fallback for any state\nnot present in the table or in FTimeOfDayConfig::TimeStatePresets." },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_SunRotation_MetaData[] = {
		{ "Category", "Sun" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "// --- Sun (Directional Light) ---\n" },
#endif
		{ "ModuleRelativePath", "Public/TimeOfDayTypes.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "--- Sun (Directional Light) ---" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_LightBrightness_MetaData[] = {
		{ "Category", "Sun" },
		{ "ModuleRelativePath", "Public/TimeOfDayTypes.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_LightTemperature_MetaData[] = {
		{ "Category", "Sun" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "// Color temperature in Kelvin. Lower = warmer (dawn/dusk), higher = cooler (noon/night).\n" },
#endif
		{ "ModuleRelativePath", "Public/TimeOfDayTypes.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Color temperature in Kelvin. Lower = warmer (dawn/dusk), higher = cooler (noon/night)." },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Exposure_MetaData[] = {
		{ "Category", "Sun" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "// Exposure compensation in stops, applied to the level's unbound Post Process Volume.\n" },
#endif
		{ "ModuleRelativePath", "Public/TimeOfDayTypes.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Exposure compensation in stops, applied to the level's unbound Post Process Volume." },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_SkyLightIntensity_MetaData[] = {
		{ "Category", "Sky" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "// --- Sky Light ---\n" },
#endif
		{ "ModuleRelativePath", "Public/TimeOfDayTypes.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "--- Sky Light ---" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_SkySunBrightness_MetaData[] = {
		{ "Category", "Sky Sphere" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "// --- Sky Sphere (optional, see ISkySphereInterface) ---\n" },
#endif
		{ "ModuleRelativePath", "Public/TimeOfDayTypes.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "--- Sky Sphere (optional, see ISkySphereInterface) ---" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_SkySunHeight_MetaData[] = {
		{ "Category", "Sky Sphere" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "// 0 = horizon, 1 = zenith. Drives a sky sphere's color curve sampling.\n" },
#endif
		{ "ModuleRelativePath", "Public/TimeOfDayTypes.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "0 = horizon, 1 = zenith. Drives a sky sphere's color curve sampling." },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_SkyCloudOpacity_MetaData[] = {
		{ "Category", "Sky Sphere" },
		{ "ModuleRelativePath", "Public/TimeOfDayTypes.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_bSkyColorsByPosition_MetaData[] = {
		{ "Category", "Sky Sphere" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "// When true, the sky sphere derives colors from sun height (outdoor states).\n// Set false for Cave/InsideLight/InsideDark where no sky is visible.\n" },
#endif
		{ "ModuleRelativePath", "Public/TimeOfDayTypes.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "When true, the sky sphere derives colors from sun height (outdoor states).\nSet false for Cave/InsideLight/InsideDark where no sky is visible." },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_FogDensity_MetaData[] = {
		{ "Category", "Fog" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "// --- Fog (Exponential Height Fog) ---\n" },
#endif
		{ "ModuleRelativePath", "Public/TimeOfDayTypes.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "--- Fog (Exponential Height Fog) ---" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_MoonIntensity_MetaData[] = {
		{ "Category", "Moon" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "// --- Moon Light (optional actor) ---\n" },
#endif
		{ "ModuleRelativePath", "Public/TimeOfDayTypes.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "--- Moon Light (optional actor) ---" },
#endif
	};
#endif // WITH_METADATA

// ********** Begin ScriptStruct FTimeStatePreset constinit property declarations ******************
	static const UECodeGen_Private::FStructPropertyParams NewProp_SunRotation;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_LightBrightness;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_LightTemperature;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_Exposure;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_SkyLightIntensity;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_SkySunBrightness;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_SkySunHeight;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_SkyCloudOpacity;
	static void NewProp_bSkyColorsByPosition_SetBit(void* Obj)
	{
		((FTimeStatePreset*)Obj)->bSkyColorsByPosition = 1;
	}
	static const UECodeGen_Private::FBoolPropertyParams NewProp_bSkyColorsByPosition;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_FogDensity;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_MoonIntensity;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End ScriptStruct FTimeStatePreset constinit property declarations ********************
	static void* NewStructOps()
	{
		return (UScriptStruct::ICppStructOps*)new UScriptStruct::TCppStructOps<FTimeStatePreset>();
	}
	static const UECodeGen_Private::FStructParams StructParams;
}; // struct UHT_STATICS
static_assert(std::is_polymorphic<FTimeStatePreset>() == std::is_polymorphic<FTableRowBase>(), "USTRUCT FTimeStatePreset cannot be polymorphic unless super FTableRowBase is polymorphic");

// ********** Begin ScriptStruct FTimeStatePreset Property Definitions *****************************
const UECodeGen_Private::FStructPropertyParams UHT_STATICS::NewProp_SunRotation = { "SunRotation", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Struct, nullptr, nullptr, 1, STRUCT_OFFSET(FTimeStatePreset, SunRotation), Z_Construct_UScriptStruct_FRotator, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_SunRotation_MetaData), NewProp_SunRotation_MetaData) };
const UECodeGen_Private::FFloatPropertyParams UHT_STATICS::NewProp_LightBrightness = { "LightBrightness", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Float, nullptr, nullptr, 1, STRUCT_OFFSET(FTimeStatePreset, LightBrightness), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_LightBrightness_MetaData), NewProp_LightBrightness_MetaData) };
const UECodeGen_Private::FFloatPropertyParams UHT_STATICS::NewProp_LightTemperature = { "LightTemperature", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Float, nullptr, nullptr, 1, STRUCT_OFFSET(FTimeStatePreset, LightTemperature), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_LightTemperature_MetaData), NewProp_LightTemperature_MetaData) };
const UECodeGen_Private::FFloatPropertyParams UHT_STATICS::NewProp_Exposure = { "Exposure", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Float, nullptr, nullptr, 1, STRUCT_OFFSET(FTimeStatePreset, Exposure), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Exposure_MetaData), NewProp_Exposure_MetaData) };
const UECodeGen_Private::FFloatPropertyParams UHT_STATICS::NewProp_SkyLightIntensity = { "SkyLightIntensity", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Float, nullptr, nullptr, 1, STRUCT_OFFSET(FTimeStatePreset, SkyLightIntensity), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_SkyLightIntensity_MetaData), NewProp_SkyLightIntensity_MetaData) };
const UECodeGen_Private::FFloatPropertyParams UHT_STATICS::NewProp_SkySunBrightness = { "SkySunBrightness", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Float, nullptr, nullptr, 1, STRUCT_OFFSET(FTimeStatePreset, SkySunBrightness), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_SkySunBrightness_MetaData), NewProp_SkySunBrightness_MetaData) };
const UECodeGen_Private::FFloatPropertyParams UHT_STATICS::NewProp_SkySunHeight = { "SkySunHeight", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Float, nullptr, nullptr, 1, STRUCT_OFFSET(FTimeStatePreset, SkySunHeight), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_SkySunHeight_MetaData), NewProp_SkySunHeight_MetaData) };
const UECodeGen_Private::FFloatPropertyParams UHT_STATICS::NewProp_SkyCloudOpacity = { "SkyCloudOpacity", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Float, nullptr, nullptr, 1, STRUCT_OFFSET(FTimeStatePreset, SkyCloudOpacity), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_SkyCloudOpacity_MetaData), NewProp_SkyCloudOpacity_MetaData) };
const UECodeGen_Private::FBoolPropertyParams UHT_STATICS::NewProp_bSkyColorsByPosition = { "bSkyColorsByPosition", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, nullptr, nullptr, 1, sizeof(bool), sizeof(FTimeStatePreset), &UHT_STATICS::NewProp_bSkyColorsByPosition_SetBit, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_bSkyColorsByPosition_MetaData), NewProp_bSkyColorsByPosition_MetaData) };
const UECodeGen_Private::FFloatPropertyParams UHT_STATICS::NewProp_FogDensity = { "FogDensity", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Float, nullptr, nullptr, 1, STRUCT_OFFSET(FTimeStatePreset, FogDensity), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_FogDensity_MetaData), NewProp_FogDensity_MetaData) };
const UECodeGen_Private::FFloatPropertyParams UHT_STATICS::NewProp_MoonIntensity = { "MoonIntensity", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Float, nullptr, nullptr, 1, STRUCT_OFFSET(FTimeStatePreset, MoonIntensity), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_MoonIntensity_MetaData), NewProp_MoonIntensity_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const UHT_STATICS::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_SunRotation,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_LightBrightness,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_LightTemperature,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_Exposure,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_SkyLightIntensity,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_SkySunBrightness,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_SkySunHeight,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_SkyCloudOpacity,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_bSkyColorsByPosition,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_FogDensity,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_MoonIntensity,
};
static_assert(UE_ARRAY_COUNT(UHT_STATICS::PropPointers) < 2048);
// ********** End ScriptStruct FTimeStatePreset Property Definitions *******************************
const UECodeGen_Private::FStructParams UHT_STATICS::StructParams = {
	(FTypeConstructFunc*)Z_Construct_UPackage__Script_TimeOfDay,
	Z_Construct_UScriptStruct_FTableRowBase,
	&NewStructOps,
	"TimeStatePreset",
	UHT_STATICS::PropPointers,
	UE_ARRAY_COUNT(UHT_STATICS::PropPointers),
	DataSizeOf<FTimeStatePreset>(),
	alignof(FTimeStatePreset),
	RF_Public|RF_Transient|RF_MarkAsNative,
	EStructFlags(0x00000001),
	METADATA_PARAMS(UE_ARRAY_COUNT(UHT_STATICS::Type_MetaData), UHT_STATICS::Type_MetaData)
};
static FStructRegistrationInfo Z_Registration_Info_UScriptStruct_FTimeStatePreset;
UScriptStruct* Z_Construct_UScriptStruct_FTimeStatePreset(ETypeConstructPhase Phase)
{
	if (Phase == ETypeConstructPhase::Outer)
	{
		if (!Z_Registration_Info_UScriptStruct_FTimeStatePreset.OuterSingleton)
		{
			Z_Registration_Info_UScriptStruct_FTimeStatePreset.OuterSingleton = GetStaticStruct(Z_Construct_UScriptStruct_FTimeStatePreset, (UObject*)Z_Construct_UPackage__Script_TimeOfDay(ETypeConstructPhase::Outer), TEXT("TimeStatePreset"));
		}
		return Z_Registration_Info_UScriptStruct_FTimeStatePreset.OuterSingleton;
	}
	if (!Z_Registration_Info_UScriptStruct_FTimeStatePreset.InnerSingleton)
	{
		UECodeGen_Private::ConstructUScriptStruct(Z_Registration_Info_UScriptStruct_FTimeStatePreset.InnerSingleton, UHT_STATICS::StructParams);
	}
	return CastChecked<UScriptStruct>(Z_Registration_Info_UScriptStruct_FTimeStatePreset.InnerSingleton);
}
#undef UHT_STATICS
// ********** End ScriptStruct FTimeStatePreset ****************************************************

// ********** Begin ScriptStruct FTimeOfDayConfig **************************************************
#ifdef UHT_STATICS
#error UHT_STATICS already defined
#endif
#define UHT_STATICS Z_Construct_UScriptStruct_FTimeOfDayConfig_Statics
struct UHT_STATICS
{
	static inline consteval int32 GetStructSize() { return DataSizeOf<FTimeOfDayConfig>(); }
	static inline consteval int16 GetStructAlignment() { return alignof(FTimeOfDayConfig); }
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Type_MetaData[] = {
		{ "BlueprintType", "true" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "// Config passed to UTimeOfDaySubsystem::InitializeTimeOfDay on level entry.\n" },
#endif
		{ "ModuleRelativePath", "Public/TimeOfDayTypes.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Config passed to UTimeOfDaySubsystem::InitializeTimeOfDay on level entry." },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_DefaultTimeState_MetaData[] = {
		{ "Category", "Time Of Day|Init" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "// State applied on initialize. Leave as None to keep the level's own lighting until a state is requested.\n" },
#endif
		{ "ModuleRelativePath", "Public/TimeOfDayTypes.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "State applied on initialize. Leave as None to keep the level's own lighting until a state is requested." },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_FastTransitionSeconds_MetaData[] = {
		{ "Category", "Time Of Day|Init" },
		{ "ClampMin", "0.1" },
		{ "ModuleRelativePath", "Public/TimeOfDayTypes.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_SlowTransitionSeconds_MetaData[] = {
		{ "Category", "Time Of Day|Init" },
		{ "ClampMin", "0.1" },
		{ "ModuleRelativePath", "Public/TimeOfDayTypes.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_CinematicLockTimeoutSeconds_MetaData[] = {
		{ "Category", "Time Of Day|Init" },
		{ "ClampMin", "1.0" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "// Safety net: the cinematic lock releases itself after this long if CinematicEndOverride is never called.\n" },
#endif
		{ "ModuleRelativePath", "Public/TimeOfDayTypes.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Safety net: the cinematic lock releases itself after this long if CinematicEndOverride is never called." },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_bAllowCompanionLight_MetaData[] = {
		{ "Category", "Time Of Day|Companion" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "// Optional companion light (for example a glowing wisp) that follows the player pawn when enabled.\n" },
#endif
		{ "ModuleRelativePath", "Public/TimeOfDayTypes.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Optional companion light (for example a glowing wisp) that follows the player pawn when enabled." },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_CompanionLightClass_MetaData[] = {
		{ "Category", "Time Of Day|Companion" },
		{ "EditCondition", "bAllowCompanionLight" },
		{ "ModuleRelativePath", "Public/TimeOfDayTypes.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_CompanionOffset_MetaData[] = {
		{ "Category", "Time Of Day|Companion" },
		{ "EditCondition", "bAllowCompanionLight" },
		{ "ModuleRelativePath", "Public/TimeOfDayTypes.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_TimeStatePresets_MetaData[] = {
		{ "Category", "Time Of Day|Init" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "// Per-state presets. States not present here (or in the data table) use built-in defaults.\n" },
#endif
		{ "ModuleRelativePath", "Public/TimeOfDayTypes.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Per-state presets. States not present here (or in the data table) use built-in defaults." },
#endif
	};
#endif // WITH_METADATA

// ********** Begin ScriptStruct FTimeOfDayConfig constinit property declarations ******************
	static const UECodeGen_Private::FBytePropertyParams NewProp_DefaultTimeState_Underlying;
	static const UECodeGen_Private::FEnumPropertyParams NewProp_DefaultTimeState;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_FastTransitionSeconds;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_SlowTransitionSeconds;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_CinematicLockTimeoutSeconds;
	static void NewProp_bAllowCompanionLight_SetBit(void* Obj)
	{
		((FTimeOfDayConfig*)Obj)->bAllowCompanionLight = 1;
	}
	static const UECodeGen_Private::FBoolPropertyParams NewProp_bAllowCompanionLight;
	static const UECodeGen_Private::FClassPropertyParams NewProp_CompanionLightClass;
	static const UECodeGen_Private::FStructPropertyParams NewProp_CompanionOffset;
	static const UECodeGen_Private::FStructPropertyParams NewProp_TimeStatePresets_ValueProp;
	static const UECodeGen_Private::FBytePropertyParams NewProp_TimeStatePresets_Key_KeyProp_Underlying;
	static const UECodeGen_Private::FEnumPropertyParams NewProp_TimeStatePresets_Key_KeyProp;
	static const UECodeGen_Private::FMapPropertyParams NewProp_TimeStatePresets;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End ScriptStruct FTimeOfDayConfig constinit property declarations ********************
	static void* NewStructOps()
	{
		return (UScriptStruct::ICppStructOps*)new UScriptStruct::TCppStructOps<FTimeOfDayConfig>();
	}
	static const UECodeGen_Private::FStructParams StructParams;
}; // struct UHT_STATICS

// ********** Begin ScriptStruct FTimeOfDayConfig Property Definitions *****************************
const UECodeGen_Private::FBytePropertyParams UHT_STATICS::NewProp_DefaultTimeState_Underlying = { "UnderlyingType", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Byte, nullptr, nullptr, 1, 0, nullptr, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FEnumPropertyParams UHT_STATICS::NewProp_DefaultTimeState = { "DefaultTimeState", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Enum, nullptr, nullptr, 1, STRUCT_OFFSET(FTimeOfDayConfig, DefaultTimeState), Z_Construct_UEnum_TimeOfDay_ETimeOfDayState, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_DefaultTimeState_MetaData), NewProp_DefaultTimeState_MetaData) }; // e535544d7177844a5c4077da9fd10109cb038391
const UECodeGen_Private::FFloatPropertyParams UHT_STATICS::NewProp_FastTransitionSeconds = { "FastTransitionSeconds", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Float, nullptr, nullptr, 1, STRUCT_OFFSET(FTimeOfDayConfig, FastTransitionSeconds), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_FastTransitionSeconds_MetaData), NewProp_FastTransitionSeconds_MetaData) };
const UECodeGen_Private::FFloatPropertyParams UHT_STATICS::NewProp_SlowTransitionSeconds = { "SlowTransitionSeconds", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Float, nullptr, nullptr, 1, STRUCT_OFFSET(FTimeOfDayConfig, SlowTransitionSeconds), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_SlowTransitionSeconds_MetaData), NewProp_SlowTransitionSeconds_MetaData) };
const UECodeGen_Private::FFloatPropertyParams UHT_STATICS::NewProp_CinematicLockTimeoutSeconds = { "CinematicLockTimeoutSeconds", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Float, nullptr, nullptr, 1, STRUCT_OFFSET(FTimeOfDayConfig, CinematicLockTimeoutSeconds), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_CinematicLockTimeoutSeconds_MetaData), NewProp_CinematicLockTimeoutSeconds_MetaData) };
const UECodeGen_Private::FBoolPropertyParams UHT_STATICS::NewProp_bAllowCompanionLight = { "bAllowCompanionLight", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, nullptr, nullptr, 1, sizeof(bool), sizeof(FTimeOfDayConfig), &UHT_STATICS::NewProp_bAllowCompanionLight_SetBit, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_bAllowCompanionLight_MetaData), NewProp_bAllowCompanionLight_MetaData) };
const UECodeGen_Private::FClassPropertyParams UHT_STATICS::NewProp_CompanionLightClass = { "CompanionLightClass", nullptr, (EPropertyFlags)0x0014000000000005, UECodeGen_Private::EPropertyGenFlags::Class, nullptr, nullptr, 1, STRUCT_OFFSET(FTimeOfDayConfig, CompanionLightClass), Z_Construct_UClass_UClass, Z_Construct_UClass_AActor, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_CompanionLightClass_MetaData), NewProp_CompanionLightClass_MetaData) };
const UECodeGen_Private::FStructPropertyParams UHT_STATICS::NewProp_CompanionOffset = { "CompanionOffset", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Struct, nullptr, nullptr, 1, STRUCT_OFFSET(FTimeOfDayConfig, CompanionOffset), Z_Construct_UScriptStruct_FVector, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_CompanionOffset_MetaData), NewProp_CompanionOffset_MetaData) };
const UECodeGen_Private::FStructPropertyParams UHT_STATICS::NewProp_TimeStatePresets_ValueProp = { "TimeStatePresets", nullptr, (EPropertyFlags)0x0000000000000001, UECodeGen_Private::EPropertyGenFlags::Struct, nullptr, nullptr, 1, 1, Z_Construct_UScriptStruct_FTimeStatePreset, METADATA_PARAMS(0, nullptr) }; // 8a9d315fb18e98ea6e15cebdfa577a2588657f2c
const UECodeGen_Private::FBytePropertyParams UHT_STATICS::NewProp_TimeStatePresets_Key_KeyProp_Underlying = { "UnderlyingType", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Byte, nullptr, nullptr, 1, 0, nullptr, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FEnumPropertyParams UHT_STATICS::NewProp_TimeStatePresets_Key_KeyProp = { "TimeStatePresets_Key", nullptr, (EPropertyFlags)0x0000000000000001, UECodeGen_Private::EPropertyGenFlags::Enum, nullptr, nullptr, 1, 0, Z_Construct_UEnum_TimeOfDay_ETimeOfDayState, METADATA_PARAMS(0, nullptr) }; // e535544d7177844a5c4077da9fd10109cb038391
const UECodeGen_Private::FMapPropertyParams UHT_STATICS::NewProp_TimeStatePresets = { "TimeStatePresets", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Map, nullptr, nullptr, 1, STRUCT_OFFSET(FTimeOfDayConfig, TimeStatePresets), EMapPropertyFlags::None, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_TimeStatePresets_MetaData), NewProp_TimeStatePresets_MetaData) }; // e535544d7177844a5c4077da9fd10109cb038391 8a9d315fb18e98ea6e15cebdfa577a2588657f2c
const UECodeGen_Private::FPropertyParamsBase* const UHT_STATICS::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_DefaultTimeState_Underlying,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_DefaultTimeState,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_FastTransitionSeconds,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_SlowTransitionSeconds,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_CinematicLockTimeoutSeconds,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_bAllowCompanionLight,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_CompanionLightClass,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_CompanionOffset,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_TimeStatePresets_ValueProp,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_TimeStatePresets_Key_KeyProp_Underlying,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_TimeStatePresets_Key_KeyProp,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_TimeStatePresets,
};
static_assert(UE_ARRAY_COUNT(UHT_STATICS::PropPointers) < 2048);
// ********** End ScriptStruct FTimeOfDayConfig Property Definitions *******************************
const UECodeGen_Private::FStructParams UHT_STATICS::StructParams = {
	(FTypeConstructFunc*)Z_Construct_UPackage__Script_TimeOfDay,
	nullptr,
	&NewStructOps,
	"TimeOfDayConfig",
	UHT_STATICS::PropPointers,
	UE_ARRAY_COUNT(UHT_STATICS::PropPointers),
	DataSizeOf<FTimeOfDayConfig>(),
	alignof(FTimeOfDayConfig),
	RF_Public|RF_Transient|RF_MarkAsNative,
	EStructFlags(0x00000001),
	METADATA_PARAMS(UE_ARRAY_COUNT(UHT_STATICS::Type_MetaData), UHT_STATICS::Type_MetaData)
};
static FStructRegistrationInfo Z_Registration_Info_UScriptStruct_FTimeOfDayConfig;
UScriptStruct* Z_Construct_UScriptStruct_FTimeOfDayConfig(ETypeConstructPhase Phase)
{
	if (Phase == ETypeConstructPhase::Outer)
	{
		if (!Z_Registration_Info_UScriptStruct_FTimeOfDayConfig.OuterSingleton)
		{
			Z_Registration_Info_UScriptStruct_FTimeOfDayConfig.OuterSingleton = GetStaticStruct(Z_Construct_UScriptStruct_FTimeOfDayConfig, (UObject*)Z_Construct_UPackage__Script_TimeOfDay(ETypeConstructPhase::Outer), TEXT("TimeOfDayConfig"));
		}
		return Z_Registration_Info_UScriptStruct_FTimeOfDayConfig.OuterSingleton;
	}
	if (!Z_Registration_Info_UScriptStruct_FTimeOfDayConfig.InnerSingleton)
	{
		UECodeGen_Private::ConstructUScriptStruct(Z_Registration_Info_UScriptStruct_FTimeOfDayConfig.InnerSingleton, UHT_STATICS::StructParams);
	}
	return CastChecked<UScriptStruct>(Z_Registration_Info_UScriptStruct_FTimeOfDayConfig.InnerSingleton);
}
#undef UHT_STATICS
// ********** End ScriptStruct FTimeOfDayConfig ****************************************************

// ********** Begin Registration *******************************************************************
#ifdef UHT_STATICS
#error UHT_STATICS already defined
#endif
#define UHT_STATICS Z_CompiledInDeferFile_FID_ValleyoftheAncient_Plugins_TimeOfDay_Source_TimeOfDay_Public_TimeOfDayTypes_h__Script_TimeOfDay_Statics
struct UHT_STATICS
{
	static constexpr FEnumRegisterCompiledInInfo EnumInfo[] = {
		{ Z_Construct_UEnum_TimeOfDay_ETimeOfDayState, TEXT("ETimeOfDayState"), &ZRIE_ETimeOfDayState, CONSTRUCT_RELOAD_VERSION_INFO(FEnumReloadVersionInfo, 3845477453U) },
		{ Z_Construct_UEnum_TimeOfDay_ETimeTransitionMode, TEXT("ETimeTransitionMode"), &ZRIE_ETimeTransitionMode, CONSTRUCT_RELOAD_VERSION_INFO(FEnumReloadVersionInfo, 3825763091U) },
	};
	static constexpr FStructRegisterCompiledInInfo ScriptStructInfo[] = {
		{ Z_Construct_UScriptStruct_FTimeStatePreset, Z_Construct_UScriptStruct_FTimeStatePreset_Statics::NewStructOps, TEXT("TimeStatePreset"),&Z_Registration_Info_UScriptStruct_FTimeStatePreset, CONSTRUCT_RELOAD_VERSION_INFO(FStructReloadVersionInfo, sizeof(FTimeStatePreset), 2325557599U) },
		{ Z_Construct_UScriptStruct_FTimeOfDayConfig, Z_Construct_UScriptStruct_FTimeOfDayConfig_Statics::NewStructOps, TEXT("TimeOfDayConfig"),&Z_Registration_Info_UScriptStruct_FTimeOfDayConfig, CONSTRUCT_RELOAD_VERSION_INFO(FStructReloadVersionInfo, sizeof(FTimeOfDayConfig), 2567924573U) },
	};
}; // UHT_STATICS 
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_ValleyoftheAncient_Plugins_TimeOfDay_Source_TimeOfDay_Public_TimeOfDayTypes_h__Script_TimeOfDay_0235822a14a077f47a40886c09900e417375de11{
	TEXT("/Script/TimeOfDay"),
	nullptr, 0,
	UHT_STATICS::ScriptStructInfo, UE_ARRAY_COUNT(UHT_STATICS::ScriptStructInfo),
	UHT_STATICS::EnumInfo, UE_ARRAY_COUNT(UHT_STATICS::EnumInfo),
	nullptr, 0,
};
#undef UHT_STATICS
// ********** End Registration *********************************************************************
#undef UHT_STRUCT_BASE

PRAGMA_ENABLE_DEPRECATION_WARNINGS
