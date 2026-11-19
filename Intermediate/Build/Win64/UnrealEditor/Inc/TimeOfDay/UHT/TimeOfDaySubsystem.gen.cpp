// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "TimeOfDaySubsystem.h"
#include "TimeOfDayTypes.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
static_assert(!UE_WITH_CONSTINIT_UOBJECT, "This generated code can only be compiled with !UE_WITH_CONSTINIT_UOBJECT");
void EmptyLinkFunctionForGeneratedCodeTimeOfDaySubsystem() {}

// ********** Begin Cross Module References ********************************************************
ENGINE_API UClass* Z_Construct_UClass_UTickableWorldSubsystem(ETypeConstructPhase);
COREUOBJECT_API UClass* Z_Construct_UClass_UClass(ETypeConstructPhase);
ENGINE_API UClass* Z_Construct_UClass_AActor(ETypeConstructPhase);
ENGINE_API UClass* Z_Construct_UClass_UDataTable(ETypeConstructPhase);
ENGINE_API UClass* Z_Construct_UClass_ADirectionalLight(ETypeConstructPhase);
ENGINE_API UClass* Z_Construct_UClass_APostProcessVolume(ETypeConstructPhase);
ENGINE_API UClass* Z_Construct_UClass_ASkyLight(ETypeConstructPhase);
// ********** End Cross Module References **********************************************************

// ********** Begin Same Module References *********************************************************
UPackage* Z_Construct_UPackage__Script_TimeOfDay(ETypeConstructPhase);
TIMEOFDAY_API UEnum* Z_Construct_UEnum_TimeOfDay_ETimeOfDayState(ETypeConstructPhase);
TIMEOFDAY_API UEnum* Z_Construct_UEnum_TimeOfDay_ETimeTransitionMode(ETypeConstructPhase);
TIMEOFDAY_API UFunction* Z_Construct_UDelegateFunction_TimeOfDay_OnTimeStateChanged__DelegateSignature(ETypeConstructPhase);
TIMEOFDAY_API UScriptStruct* Z_Construct_UScriptStruct_FTimeOfDayConfig(ETypeConstructPhase);
TIMEOFDAY_API UClass* Z_Construct_UClass_UTimeOfDaySubsystem(ETypeConstructPhase);
TIMEOFDAY_API UClass* Z_Construct_UClass_UTimeOfDaySubsystem(ETypeConstructPhase);
// ********** End Same Module References ***********************************************************
#define UHT_STRUCT_BASE(INIT) UE::CodeGen::ConstInit::TCompiledInObjectPtr<const FStructBaseChain>(UE::Private::AsStructBaseChain(INIT))

// ********** Begin Delegate FOnTimeStateChanged ***************************************************
#ifdef UHT_STATICS
#error UHT_STATICS already defined
#endif
#define UHT_STATICS Z_Construct_UDelegateFunction_TimeOfDay_OnTimeStateChanged__DelegateSignature_Statics
struct UHT_STATICS
{
	struct _Script_TimeOfDay_eventOnTimeStateChanged_Parms
	{
		ETimeOfDayState OldState;
		ETimeOfDayState NewState;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Type_MetaData[] = {
		{ "ModuleRelativePath", "Public/TimeOfDaySubsystem.h" },
	};
#endif // WITH_METADATA

// ********** Begin Delegate FOnTimeStateChanged constinit property declarations *******************
	static const UECodeGen_Private::FBytePropertyParams NewProp_OldState_Underlying;
	static const UECodeGen_Private::FEnumPropertyParams NewProp_OldState;
	static const UECodeGen_Private::FBytePropertyParams NewProp_NewState_Underlying;
	static const UECodeGen_Private::FEnumPropertyParams NewProp_NewState;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Delegate FOnTimeStateChanged constinit property declarations *********************
	static const UECodeGen_Private::FDelegateFunctionParams FuncParams;
};

// ********** Begin Delegate FOnTimeStateChanged Property Definitions ******************************
const UECodeGen_Private::FBytePropertyParams UHT_STATICS::NewProp_OldState_Underlying = { "UnderlyingType", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Byte, nullptr, nullptr, 1, 0, nullptr, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FEnumPropertyParams UHT_STATICS::NewProp_OldState = { "OldState", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Enum, nullptr, nullptr, 1, STRUCT_OFFSET(_Script_TimeOfDay_eventOnTimeStateChanged_Parms, OldState), Z_Construct_UEnum_TimeOfDay_ETimeOfDayState, METADATA_PARAMS(0, nullptr) }; // e535544d7177844a5c4077da9fd10109cb038391
const UECodeGen_Private::FBytePropertyParams UHT_STATICS::NewProp_NewState_Underlying = { "UnderlyingType", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Byte, nullptr, nullptr, 1, 0, nullptr, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FEnumPropertyParams UHT_STATICS::NewProp_NewState = { "NewState", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Enum, nullptr, nullptr, 1, STRUCT_OFFSET(_Script_TimeOfDay_eventOnTimeStateChanged_Parms, NewState), Z_Construct_UEnum_TimeOfDay_ETimeOfDayState, METADATA_PARAMS(0, nullptr) }; // e535544d7177844a5c4077da9fd10109cb038391
const UECodeGen_Private::FPropertyParamsBase* const UHT_STATICS::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_OldState_Underlying,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_OldState,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_NewState_Underlying,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_NewState,
};
static_assert(UE_ARRAY_COUNT(UHT_STATICS::PropPointers) < 2048);
// ********** End Delegate FOnTimeStateChanged Property Definitions ********************************
const UECodeGen_Private::FDelegateFunctionParams UHT_STATICS::FuncParams = { { (FTypeConstructFunc*)Z_Construct_UPackage__Script_TimeOfDay, nullptr, "OnTimeStateChanged__DelegateSignature", UHT_STATICS::PropPointers, UE_ARRAY_COUNT(UHT_STATICS::PropPointers), DataSizeOf<UHT_STATICS::_Script_TimeOfDay_eventOnTimeStateChanged_Parms>(), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00130000, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(UHT_STATICS::Type_MetaData), UHT_STATICS::Type_MetaData)},  };
static_assert(sizeof(UHT_STATICS::_Script_TimeOfDay_eventOnTimeStateChanged_Parms) < MAX_uint16);
UFunction* Z_Construct_UDelegateFunction_TimeOfDay_OnTimeStateChanged__DelegateSignature(ETypeConstructPhase Phase)
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUDelegateFunction(&ReturnFunction, UHT_STATICS::FuncParams);
	}
	return ReturnFunction;
}
#undef UHT_STATICS
// ********** End Delegate FOnTimeStateChanged *****************************************************

// ********** Begin Class UTimeOfDaySubsystem Function CinematicBeginOverride **********************
#ifdef UHT_STATICS
#error UHT_STATICS already defined
#endif
#define UHT_STATICS Z_Construct_UFunction_UTimeOfDaySubsystem_CinematicBeginOverride_Statics
struct UHT_STATICS
{
	struct TimeOfDaySubsystem_eventCinematicBeginOverride_Parms
	{
		ETimeOfDayState OverrideState;
		ETimeTransitionMode TransitionMode;
		bool bForceCompanionLight;
		bool bCompanionLightEnabled;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Type_MetaData[] = {
		{ "Category", "Time Of Day" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "// Cinematic control. The lock blocks gameplay requests until CinematicEndOverride\n// (or the auto-release timeout).\n" },
#endif
		{ "CPP_Default_bCompanionLightEnabled", "false" },
		{ "CPP_Default_bForceCompanionLight", "false" },
		{ "ModuleRelativePath", "Public/TimeOfDaySubsystem.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Cinematic control. The lock blocks gameplay requests until CinematicEndOverride\n(or the auto-release timeout)." },
#endif
	};
#endif // WITH_METADATA

// ********** Begin Function CinematicBeginOverride constinit property declarations ****************
	static const UECodeGen_Private::FBytePropertyParams NewProp_OverrideState_Underlying;
	static const UECodeGen_Private::FEnumPropertyParams NewProp_OverrideState;
	static const UECodeGen_Private::FBytePropertyParams NewProp_TransitionMode_Underlying;
	static const UECodeGen_Private::FEnumPropertyParams NewProp_TransitionMode;
	static void NewProp_bForceCompanionLight_SetBit(void* Obj)
	{
		((TimeOfDaySubsystem_eventCinematicBeginOverride_Parms*)Obj)->bForceCompanionLight = 1;
	}
	static const UECodeGen_Private::FBoolPropertyParams NewProp_bForceCompanionLight;
	static void NewProp_bCompanionLightEnabled_SetBit(void* Obj)
	{
		((TimeOfDaySubsystem_eventCinematicBeginOverride_Parms*)Obj)->bCompanionLightEnabled = 1;
	}
	static const UECodeGen_Private::FBoolPropertyParams NewProp_bCompanionLightEnabled;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function CinematicBeginOverride constinit property declarations ******************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function CinematicBeginOverride Property Definitions ***************************
const UECodeGen_Private::FBytePropertyParams UHT_STATICS::NewProp_OverrideState_Underlying = { "UnderlyingType", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Byte, nullptr, nullptr, 1, 0, nullptr, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FEnumPropertyParams UHT_STATICS::NewProp_OverrideState = { "OverrideState", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Enum, nullptr, nullptr, 1, STRUCT_OFFSET(TimeOfDaySubsystem_eventCinematicBeginOverride_Parms, OverrideState), Z_Construct_UEnum_TimeOfDay_ETimeOfDayState, METADATA_PARAMS(0, nullptr) }; // e535544d7177844a5c4077da9fd10109cb038391
const UECodeGen_Private::FBytePropertyParams UHT_STATICS::NewProp_TransitionMode_Underlying = { "UnderlyingType", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Byte, nullptr, nullptr, 1, 0, nullptr, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FEnumPropertyParams UHT_STATICS::NewProp_TransitionMode = { "TransitionMode", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Enum, nullptr, nullptr, 1, STRUCT_OFFSET(TimeOfDaySubsystem_eventCinematicBeginOverride_Parms, TransitionMode), Z_Construct_UEnum_TimeOfDay_ETimeTransitionMode, METADATA_PARAMS(0, nullptr) }; // e408831340c582aafd4d81eacaa0ff00939513ad
const UECodeGen_Private::FBoolPropertyParams UHT_STATICS::NewProp_bForceCompanionLight = { "bForceCompanionLight", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, nullptr, nullptr, 1, sizeof(bool), sizeof(TimeOfDaySubsystem_eventCinematicBeginOverride_Parms), &UHT_STATICS::NewProp_bForceCompanionLight_SetBit, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FBoolPropertyParams UHT_STATICS::NewProp_bCompanionLightEnabled = { "bCompanionLightEnabled", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, nullptr, nullptr, 1, sizeof(bool), sizeof(TimeOfDaySubsystem_eventCinematicBeginOverride_Parms), &UHT_STATICS::NewProp_bCompanionLightEnabled_SetBit, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const UHT_STATICS::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_OverrideState_Underlying,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_OverrideState,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_TransitionMode_Underlying,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_TransitionMode,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_bForceCompanionLight,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_bCompanionLightEnabled,
};
static_assert(UE_ARRAY_COUNT(UHT_STATICS::PropPointers) < 2048);
// ********** End Function CinematicBeginOverride Property Definitions *****************************
const UECodeGen_Private::FFunctionParams UHT_STATICS::FuncParams = { { (FTypeConstructFunc*)Z_Construct_UClass_UTimeOfDaySubsystem, nullptr, "CinematicBeginOverride", UHT_STATICS::PropPointers, UE_ARRAY_COUNT(UHT_STATICS::PropPointers), DataSizeOf<UHT_STATICS::TimeOfDaySubsystem_eventCinematicBeginOverride_Parms>(), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(UHT_STATICS::Type_MetaData), UHT_STATICS::Type_MetaData)},  };
static_assert(sizeof(UHT_STATICS::TimeOfDaySubsystem_eventCinematicBeginOverride_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UTimeOfDaySubsystem_CinematicBeginOverride(ETypeConstructPhase Phase)
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, UHT_STATICS::FuncParams);
	}
	return ReturnFunction;
}
#undef UHT_STATICS
DEFINE_FUNCTION(UTimeOfDaySubsystem::execCinematicBeginOverride)
{
	P_GET_ENUM(ETimeOfDayState,Z_Param_OverrideState);
	P_GET_ENUM(ETimeTransitionMode,Z_Param_TransitionMode);
	P_GET_UBOOL(Z_Param_bForceCompanionLight);
	P_GET_UBOOL(Z_Param_bCompanionLightEnabled);
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->CinematicBeginOverride(ETimeOfDayState(Z_Param_OverrideState),ETimeTransitionMode(Z_Param_TransitionMode),Z_Param_bForceCompanionLight,Z_Param_bCompanionLightEnabled);
	P_NATIVE_END;
}
// ********** End Class UTimeOfDaySubsystem Function CinematicBeginOverride ************************

// ********** Begin Class UTimeOfDaySubsystem Function CinematicEndOverride ************************
#ifdef UHT_STATICS
#error UHT_STATICS already defined
#endif
#define UHT_STATICS Z_Construct_UFunction_UTimeOfDaySubsystem_CinematicEndOverride_Statics
struct UHT_STATICS
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Type_MetaData[] = {
		{ "Category", "Time Of Day" },
		{ "ModuleRelativePath", "Public/TimeOfDaySubsystem.h" },
	};
#endif // WITH_METADATA

// ********** Begin Function CinematicEndOverride constinit property declarations ******************
// ********** End Function CinematicEndOverride constinit property declarations ********************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FFunctionParams UHT_STATICS::FuncParams = { { (FTypeConstructFunc*)Z_Construct_UClass_UTimeOfDaySubsystem, nullptr, "CinematicEndOverride", nullptr, 0, 0, RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(UHT_STATICS::Type_MetaData), UHT_STATICS::Type_MetaData)},  };
UFunction* Z_Construct_UFunction_UTimeOfDaySubsystem_CinematicEndOverride(ETypeConstructPhase Phase)
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, UHT_STATICS::FuncParams);
	}
	return ReturnFunction;
}
#undef UHT_STATICS
DEFINE_FUNCTION(UTimeOfDaySubsystem::execCinematicEndOverride)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->CinematicEndOverride();
	P_NATIVE_END;
}
// ********** End Class UTimeOfDaySubsystem Function CinematicEndOverride **************************

// ********** Begin Class UTimeOfDaySubsystem Function GetCurrentTimeState *************************
#ifdef UHT_STATICS
#error UHT_STATICS already defined
#endif
#define UHT_STATICS Z_Construct_UFunction_UTimeOfDaySubsystem_GetCurrentTimeState_Statics
struct UHT_STATICS
{
	struct TimeOfDaySubsystem_eventGetCurrentTimeState_Parms
	{
		ETimeOfDayState ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Type_MetaData[] = {
		{ "Category", "Time Of Day" },
		{ "ModuleRelativePath", "Public/TimeOfDaySubsystem.h" },
	};
#endif // WITH_METADATA

// ********** Begin Function GetCurrentTimeState constinit property declarations *******************
	static const UECodeGen_Private::FBytePropertyParams NewProp_ReturnValue_Underlying;
	static const UECodeGen_Private::FEnumPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function GetCurrentTimeState constinit property declarations *********************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function GetCurrentTimeState Property Definitions ******************************
const UECodeGen_Private::FBytePropertyParams UHT_STATICS::NewProp_ReturnValue_Underlying = { "UnderlyingType", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Byte, nullptr, nullptr, 1, 0, nullptr, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FEnumPropertyParams UHT_STATICS::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Enum, nullptr, nullptr, 1, STRUCT_OFFSET(TimeOfDaySubsystem_eventGetCurrentTimeState_Parms, ReturnValue), Z_Construct_UEnum_TimeOfDay_ETimeOfDayState, METADATA_PARAMS(0, nullptr) }; // e535544d7177844a5c4077da9fd10109cb038391
const UECodeGen_Private::FPropertyParamsBase* const UHT_STATICS::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_ReturnValue_Underlying,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(UHT_STATICS::PropPointers) < 2048);
// ********** End Function GetCurrentTimeState Property Definitions ********************************
const UECodeGen_Private::FFunctionParams UHT_STATICS::FuncParams = { { (FTypeConstructFunc*)Z_Construct_UClass_UTimeOfDaySubsystem, nullptr, "GetCurrentTimeState", UHT_STATICS::PropPointers, UE_ARRAY_COUNT(UHT_STATICS::PropPointers), DataSizeOf<UHT_STATICS::TimeOfDaySubsystem_eventGetCurrentTimeState_Parms>(), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x54020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(UHT_STATICS::Type_MetaData), UHT_STATICS::Type_MetaData)},  };
static_assert(sizeof(UHT_STATICS::TimeOfDaySubsystem_eventGetCurrentTimeState_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UTimeOfDaySubsystem_GetCurrentTimeState(ETypeConstructPhase Phase)
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, UHT_STATICS::FuncParams);
	}
	return ReturnFunction;
}
#undef UHT_STATICS
DEFINE_FUNCTION(UTimeOfDaySubsystem::execGetCurrentTimeState)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	*(ETimeOfDayState*)Z_Param__Result=P_THIS->GetCurrentTimeState();
	P_NATIVE_END;
}
// ********** End Class UTimeOfDaySubsystem Function GetCurrentTimeState ***************************

// ********** Begin Class UTimeOfDaySubsystem Function InitializeTimeOfDay *************************
#ifdef UHT_STATICS
#error UHT_STATICS already defined
#endif
#define UHT_STATICS Z_Construct_UFunction_UTimeOfDaySubsystem_InitializeTimeOfDay_Statics
struct UHT_STATICS
{
	struct TimeOfDaySubsystem_eventInitializeTimeOfDay_Parms
	{
		FTimeOfDayConfig Config;
		UDataTable* InLightingPresets;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Type_MetaData[] = {
		{ "Category", "Time Of Day" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "// Configure lighting for this level. Call from a level Blueprint, game mode or level manager.\n// Not required for testing: any request or console command initializes with defaults on first use.\n" },
#endif
		{ "CPP_Default_InLightingPresets", "None" },
		{ "ModuleRelativePath", "Public/TimeOfDaySubsystem.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Configure lighting for this level. Call from a level Blueprint, game mode or level manager.\nNot required for testing: any request or console command initializes with defaults on first use." },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Config_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif // WITH_METADATA

// ********** Begin Function InitializeTimeOfDay constinit property declarations *******************
	static const UECodeGen_Private::FStructPropertyParams NewProp_Config;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_InLightingPresets;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function InitializeTimeOfDay constinit property declarations *********************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function InitializeTimeOfDay Property Definitions ******************************
const UECodeGen_Private::FStructPropertyParams UHT_STATICS::NewProp_Config = { "Config", nullptr, (EPropertyFlags)0x0010000008000182, UECodeGen_Private::EPropertyGenFlags::Struct, nullptr, nullptr, 1, STRUCT_OFFSET(TimeOfDaySubsystem_eventInitializeTimeOfDay_Parms, Config), Z_Construct_UScriptStruct_FTimeOfDayConfig, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Config_MetaData), NewProp_Config_MetaData) }; // 990f6b5d8c7501c501430e72577e53e34a2e5a4a
const UECodeGen_Private::FObjectPropertyParams UHT_STATICS::NewProp_InLightingPresets = { "InLightingPresets", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Object, nullptr, nullptr, 1, STRUCT_OFFSET(TimeOfDaySubsystem_eventInitializeTimeOfDay_Parms, InLightingPresets), Z_Construct_UClass_UDataTable, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const UHT_STATICS::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_Config,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_InLightingPresets,
};
static_assert(UE_ARRAY_COUNT(UHT_STATICS::PropPointers) < 2048);
// ********** End Function InitializeTimeOfDay Property Definitions ********************************
const UECodeGen_Private::FFunctionParams UHT_STATICS::FuncParams = { { (FTypeConstructFunc*)Z_Construct_UClass_UTimeOfDaySubsystem, nullptr, "InitializeTimeOfDay", UHT_STATICS::PropPointers, UE_ARRAY_COUNT(UHT_STATICS::PropPointers), DataSizeOf<UHT_STATICS::TimeOfDaySubsystem_eventInitializeTimeOfDay_Parms>(), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04420401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(UHT_STATICS::Type_MetaData), UHT_STATICS::Type_MetaData)},  };
static_assert(sizeof(UHT_STATICS::TimeOfDaySubsystem_eventInitializeTimeOfDay_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UTimeOfDaySubsystem_InitializeTimeOfDay(ETypeConstructPhase Phase)
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, UHT_STATICS::FuncParams);
	}
	return ReturnFunction;
}
#undef UHT_STATICS
DEFINE_FUNCTION(UTimeOfDaySubsystem::execInitializeTimeOfDay)
{
	P_GET_STRUCT_REF(FTimeOfDayConfig,Z_Param_Out_Config);
	P_GET_OBJECT(UDataTable,Z_Param_InLightingPresets);
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->InitializeTimeOfDay(Z_Param_Out_Config,Z_Param_InLightingPresets);
	P_NATIVE_END;
}
// ********** End Class UTimeOfDaySubsystem Function InitializeTimeOfDay ***************************

// ********** Begin Class UTimeOfDaySubsystem Function IsDebugReadoutEnabled ***********************
#ifdef UHT_STATICS
#error UHT_STATICS already defined
#endif
#define UHT_STATICS Z_Construct_UFunction_UTimeOfDaySubsystem_IsDebugReadoutEnabled_Statics
struct UHT_STATICS
{
	struct TimeOfDaySubsystem_eventIsDebugReadoutEnabled_Parms
	{
		bool ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Type_MetaData[] = {
		{ "Category", "Time Of Day|Debug" },
		{ "ModuleRelativePath", "Public/TimeOfDaySubsystem.h" },
	};
#endif // WITH_METADATA

// ********** Begin Function IsDebugReadoutEnabled constinit property declarations *****************
	static void NewProp_ReturnValue_SetBit(void* Obj)
	{
		((TimeOfDaySubsystem_eventIsDebugReadoutEnabled_Parms*)Obj)->ReturnValue = 1;
	}
	static const UECodeGen_Private::FBoolPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function IsDebugReadoutEnabled constinit property declarations *******************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function IsDebugReadoutEnabled Property Definitions ****************************
const UECodeGen_Private::FBoolPropertyParams UHT_STATICS::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, nullptr, nullptr, 1, sizeof(bool), sizeof(TimeOfDaySubsystem_eventIsDebugReadoutEnabled_Parms), &UHT_STATICS::NewProp_ReturnValue_SetBit, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const UHT_STATICS::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(UHT_STATICS::PropPointers) < 2048);
// ********** End Function IsDebugReadoutEnabled Property Definitions ******************************
const UECodeGen_Private::FFunctionParams UHT_STATICS::FuncParams = { { (FTypeConstructFunc*)Z_Construct_UClass_UTimeOfDaySubsystem, nullptr, "IsDebugReadoutEnabled", UHT_STATICS::PropPointers, UE_ARRAY_COUNT(UHT_STATICS::PropPointers), DataSizeOf<UHT_STATICS::TimeOfDaySubsystem_eventIsDebugReadoutEnabled_Parms>(), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x54020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(UHT_STATICS::Type_MetaData), UHT_STATICS::Type_MetaData)},  };
static_assert(sizeof(UHT_STATICS::TimeOfDaySubsystem_eventIsDebugReadoutEnabled_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UTimeOfDaySubsystem_IsDebugReadoutEnabled(ETypeConstructPhase Phase)
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, UHT_STATICS::FuncParams);
	}
	return ReturnFunction;
}
#undef UHT_STATICS
DEFINE_FUNCTION(UTimeOfDaySubsystem::execIsDebugReadoutEnabled)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	*(bool*)Z_Param__Result=P_THIS->IsDebugReadoutEnabled();
	P_NATIVE_END;
}
// ********** End Class UTimeOfDaySubsystem Function IsDebugReadoutEnabled *************************

// ********** Begin Class UTimeOfDaySubsystem Function IsTimeOfDayInitialized **********************
#ifdef UHT_STATICS
#error UHT_STATICS already defined
#endif
#define UHT_STATICS Z_Construct_UFunction_UTimeOfDaySubsystem_IsTimeOfDayInitialized_Statics
struct UHT_STATICS
{
	struct TimeOfDaySubsystem_eventIsTimeOfDayInitialized_Parms
	{
		bool ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Type_MetaData[] = {
		{ "Category", "Time Of Day" },
		{ "ModuleRelativePath", "Public/TimeOfDaySubsystem.h" },
	};
#endif // WITH_METADATA

// ********** Begin Function IsTimeOfDayInitialized constinit property declarations ****************
	static void NewProp_ReturnValue_SetBit(void* Obj)
	{
		((TimeOfDaySubsystem_eventIsTimeOfDayInitialized_Parms*)Obj)->ReturnValue = 1;
	}
	static const UECodeGen_Private::FBoolPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function IsTimeOfDayInitialized constinit property declarations ******************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function IsTimeOfDayInitialized Property Definitions ***************************
const UECodeGen_Private::FBoolPropertyParams UHT_STATICS::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, nullptr, nullptr, 1, sizeof(bool), sizeof(TimeOfDaySubsystem_eventIsTimeOfDayInitialized_Parms), &UHT_STATICS::NewProp_ReturnValue_SetBit, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const UHT_STATICS::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(UHT_STATICS::PropPointers) < 2048);
// ********** End Function IsTimeOfDayInitialized Property Definitions *****************************
const UECodeGen_Private::FFunctionParams UHT_STATICS::FuncParams = { { (FTypeConstructFunc*)Z_Construct_UClass_UTimeOfDaySubsystem, nullptr, "IsTimeOfDayInitialized", UHT_STATICS::PropPointers, UE_ARRAY_COUNT(UHT_STATICS::PropPointers), DataSizeOf<UHT_STATICS::TimeOfDaySubsystem_eventIsTimeOfDayInitialized_Parms>(), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x54020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(UHT_STATICS::Type_MetaData), UHT_STATICS::Type_MetaData)},  };
static_assert(sizeof(UHT_STATICS::TimeOfDaySubsystem_eventIsTimeOfDayInitialized_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UTimeOfDaySubsystem_IsTimeOfDayInitialized(ETypeConstructPhase Phase)
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, UHT_STATICS::FuncParams);
	}
	return ReturnFunction;
}
#undef UHT_STATICS
DEFINE_FUNCTION(UTimeOfDaySubsystem::execIsTimeOfDayInitialized)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	*(bool*)Z_Param__Result=P_THIS->IsTimeOfDayInitialized();
	P_NATIVE_END;
}
// ********** End Class UTimeOfDaySubsystem Function IsTimeOfDayInitialized ************************

// ********** Begin Class UTimeOfDaySubsystem Function IsTransitioning *****************************
#ifdef UHT_STATICS
#error UHT_STATICS already defined
#endif
#define UHT_STATICS Z_Construct_UFunction_UTimeOfDaySubsystem_IsTransitioning_Statics
struct UHT_STATICS
{
	struct TimeOfDaySubsystem_eventIsTransitioning_Parms
	{
		bool ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Type_MetaData[] = {
		{ "Category", "Time Of Day" },
		{ "ModuleRelativePath", "Public/TimeOfDaySubsystem.h" },
	};
#endif // WITH_METADATA

// ********** Begin Function IsTransitioning constinit property declarations ***********************
	static void NewProp_ReturnValue_SetBit(void* Obj)
	{
		((TimeOfDaySubsystem_eventIsTransitioning_Parms*)Obj)->ReturnValue = 1;
	}
	static const UECodeGen_Private::FBoolPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function IsTransitioning constinit property declarations *************************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function IsTransitioning Property Definitions **********************************
const UECodeGen_Private::FBoolPropertyParams UHT_STATICS::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, nullptr, nullptr, 1, sizeof(bool), sizeof(TimeOfDaySubsystem_eventIsTransitioning_Parms), &UHT_STATICS::NewProp_ReturnValue_SetBit, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const UHT_STATICS::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(UHT_STATICS::PropPointers) < 2048);
// ********** End Function IsTransitioning Property Definitions ************************************
const UECodeGen_Private::FFunctionParams UHT_STATICS::FuncParams = { { (FTypeConstructFunc*)Z_Construct_UClass_UTimeOfDaySubsystem, nullptr, "IsTransitioning", UHT_STATICS::PropPointers, UE_ARRAY_COUNT(UHT_STATICS::PropPointers), DataSizeOf<UHT_STATICS::TimeOfDaySubsystem_eventIsTransitioning_Parms>(), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x54020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(UHT_STATICS::Type_MetaData), UHT_STATICS::Type_MetaData)},  };
static_assert(sizeof(UHT_STATICS::TimeOfDaySubsystem_eventIsTransitioning_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UTimeOfDaySubsystem_IsTransitioning(ETypeConstructPhase Phase)
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, UHT_STATICS::FuncParams);
	}
	return ReturnFunction;
}
#undef UHT_STATICS
DEFINE_FUNCTION(UTimeOfDaySubsystem::execIsTransitioning)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	*(bool*)Z_Param__Result=P_THIS->IsTransitioning();
	P_NATIVE_END;
}
// ********** End Class UTimeOfDaySubsystem Function IsTransitioning *******************************

// ********** Begin Class UTimeOfDaySubsystem Function RequestTimeState ****************************
#ifdef UHT_STATICS
#error UHT_STATICS already defined
#endif
#define UHT_STATICS Z_Construct_UFunction_UTimeOfDaySubsystem_RequestTimeState_Statics
struct UHT_STATICS
{
	struct TimeOfDaySubsystem_eventRequestTimeState_Parms
	{
		ETimeOfDayState NewState;
		ETimeTransitionMode TransitionMode;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Type_MetaData[] = {
		{ "Category", "Time Of Day" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "// Gameplay request. Ignored while the cinematic lock is held.\n" },
#endif
		{ "CPP_Default_TransitionMode", "Fast" },
		{ "ModuleRelativePath", "Public/TimeOfDaySubsystem.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Gameplay request. Ignored while the cinematic lock is held." },
#endif
	};
#endif // WITH_METADATA

// ********** Begin Function RequestTimeState constinit property declarations **********************
	static const UECodeGen_Private::FBytePropertyParams NewProp_NewState_Underlying;
	static const UECodeGen_Private::FEnumPropertyParams NewProp_NewState;
	static const UECodeGen_Private::FBytePropertyParams NewProp_TransitionMode_Underlying;
	static const UECodeGen_Private::FEnumPropertyParams NewProp_TransitionMode;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function RequestTimeState constinit property declarations ************************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function RequestTimeState Property Definitions *********************************
const UECodeGen_Private::FBytePropertyParams UHT_STATICS::NewProp_NewState_Underlying = { "UnderlyingType", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Byte, nullptr, nullptr, 1, 0, nullptr, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FEnumPropertyParams UHT_STATICS::NewProp_NewState = { "NewState", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Enum, nullptr, nullptr, 1, STRUCT_OFFSET(TimeOfDaySubsystem_eventRequestTimeState_Parms, NewState), Z_Construct_UEnum_TimeOfDay_ETimeOfDayState, METADATA_PARAMS(0, nullptr) }; // e535544d7177844a5c4077da9fd10109cb038391
const UECodeGen_Private::FBytePropertyParams UHT_STATICS::NewProp_TransitionMode_Underlying = { "UnderlyingType", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Byte, nullptr, nullptr, 1, 0, nullptr, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FEnumPropertyParams UHT_STATICS::NewProp_TransitionMode = { "TransitionMode", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Enum, nullptr, nullptr, 1, STRUCT_OFFSET(TimeOfDaySubsystem_eventRequestTimeState_Parms, TransitionMode), Z_Construct_UEnum_TimeOfDay_ETimeTransitionMode, METADATA_PARAMS(0, nullptr) }; // e408831340c582aafd4d81eacaa0ff00939513ad
const UECodeGen_Private::FPropertyParamsBase* const UHT_STATICS::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_NewState_Underlying,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_NewState,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_TransitionMode_Underlying,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_TransitionMode,
};
static_assert(UE_ARRAY_COUNT(UHT_STATICS::PropPointers) < 2048);
// ********** End Function RequestTimeState Property Definitions ***********************************
const UECodeGen_Private::FFunctionParams UHT_STATICS::FuncParams = { { (FTypeConstructFunc*)Z_Construct_UClass_UTimeOfDaySubsystem, nullptr, "RequestTimeState", UHT_STATICS::PropPointers, UE_ARRAY_COUNT(UHT_STATICS::PropPointers), DataSizeOf<UHT_STATICS::TimeOfDaySubsystem_eventRequestTimeState_Parms>(), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(UHT_STATICS::Type_MetaData), UHT_STATICS::Type_MetaData)},  };
static_assert(sizeof(UHT_STATICS::TimeOfDaySubsystem_eventRequestTimeState_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UTimeOfDaySubsystem_RequestTimeState(ETypeConstructPhase Phase)
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, UHT_STATICS::FuncParams);
	}
	return ReturnFunction;
}
#undef UHT_STATICS
DEFINE_FUNCTION(UTimeOfDaySubsystem::execRequestTimeState)
{
	P_GET_ENUM(ETimeOfDayState,Z_Param_NewState);
	P_GET_ENUM(ETimeTransitionMode,Z_Param_TransitionMode);
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->RequestTimeState(ETimeOfDayState(Z_Param_NewState),ETimeTransitionMode(Z_Param_TransitionMode));
	P_NATIVE_END;
}
// ********** End Class UTimeOfDaySubsystem Function RequestTimeState ******************************

// ********** Begin Class UTimeOfDaySubsystem Function RestoreTimeState ****************************
#ifdef UHT_STATICS
#error UHT_STATICS already defined
#endif
#define UHT_STATICS Z_Construct_UFunction_UTimeOfDaySubsystem_RestoreTimeState_Statics
struct UHT_STATICS
{
	struct TimeOfDaySubsystem_eventRestoreTimeState_Parms
	{
		ETimeOfDayState SavedState;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Type_MetaData[] = {
		{ "Category", "Time Of Day" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "// Snap to a saved state after a game load (no transition).\n" },
#endif
		{ "ModuleRelativePath", "Public/TimeOfDaySubsystem.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Snap to a saved state after a game load (no transition)." },
#endif
	};
#endif // WITH_METADATA

// ********** Begin Function RestoreTimeState constinit property declarations **********************
	static const UECodeGen_Private::FBytePropertyParams NewProp_SavedState_Underlying;
	static const UECodeGen_Private::FEnumPropertyParams NewProp_SavedState;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function RestoreTimeState constinit property declarations ************************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function RestoreTimeState Property Definitions *********************************
const UECodeGen_Private::FBytePropertyParams UHT_STATICS::NewProp_SavedState_Underlying = { "UnderlyingType", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Byte, nullptr, nullptr, 1, 0, nullptr, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FEnumPropertyParams UHT_STATICS::NewProp_SavedState = { "SavedState", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Enum, nullptr, nullptr, 1, STRUCT_OFFSET(TimeOfDaySubsystem_eventRestoreTimeState_Parms, SavedState), Z_Construct_UEnum_TimeOfDay_ETimeOfDayState, METADATA_PARAMS(0, nullptr) }; // e535544d7177844a5c4077da9fd10109cb038391
const UECodeGen_Private::FPropertyParamsBase* const UHT_STATICS::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_SavedState_Underlying,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_SavedState,
};
static_assert(UE_ARRAY_COUNT(UHT_STATICS::PropPointers) < 2048);
// ********** End Function RestoreTimeState Property Definitions ***********************************
const UECodeGen_Private::FFunctionParams UHT_STATICS::FuncParams = { { (FTypeConstructFunc*)Z_Construct_UClass_UTimeOfDaySubsystem, nullptr, "RestoreTimeState", UHT_STATICS::PropPointers, UE_ARRAY_COUNT(UHT_STATICS::PropPointers), DataSizeOf<UHT_STATICS::TimeOfDaySubsystem_eventRestoreTimeState_Parms>(), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(UHT_STATICS::Type_MetaData), UHT_STATICS::Type_MetaData)},  };
static_assert(sizeof(UHT_STATICS::TimeOfDaySubsystem_eventRestoreTimeState_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UTimeOfDaySubsystem_RestoreTimeState(ETypeConstructPhase Phase)
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, UHT_STATICS::FuncParams);
	}
	return ReturnFunction;
}
#undef UHT_STATICS
DEFINE_FUNCTION(UTimeOfDaySubsystem::execRestoreTimeState)
{
	P_GET_ENUM(ETimeOfDayState,Z_Param_SavedState);
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->RestoreTimeState(ETimeOfDayState(Z_Param_SavedState));
	P_NATIVE_END;
}
// ********** End Class UTimeOfDaySubsystem Function RestoreTimeState ******************************

// ********** Begin Class UTimeOfDaySubsystem Function SetCompanionLightEnabled ********************
#ifdef UHT_STATICS
#error UHT_STATICS already defined
#endif
#define UHT_STATICS Z_Construct_UFunction_UTimeOfDaySubsystem_SetCompanionLightEnabled_Statics
struct UHT_STATICS
{
	struct TimeOfDaySubsystem_eventSetCompanionLightEnabled_Parms
	{
		bool bEnabled;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Type_MetaData[] = {
		{ "Category", "Time Of Day" },
		{ "ModuleRelativePath", "Public/TimeOfDaySubsystem.h" },
	};
#endif // WITH_METADATA

// ********** Begin Function SetCompanionLightEnabled constinit property declarations **************
	static void NewProp_bEnabled_SetBit(void* Obj)
	{
		((TimeOfDaySubsystem_eventSetCompanionLightEnabled_Parms*)Obj)->bEnabled = 1;
	}
	static const UECodeGen_Private::FBoolPropertyParams NewProp_bEnabled;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function SetCompanionLightEnabled constinit property declarations ****************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function SetCompanionLightEnabled Property Definitions *************************
const UECodeGen_Private::FBoolPropertyParams UHT_STATICS::NewProp_bEnabled = { "bEnabled", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, nullptr, nullptr, 1, sizeof(bool), sizeof(TimeOfDaySubsystem_eventSetCompanionLightEnabled_Parms), &UHT_STATICS::NewProp_bEnabled_SetBit, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const UHT_STATICS::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_bEnabled,
};
static_assert(UE_ARRAY_COUNT(UHT_STATICS::PropPointers) < 2048);
// ********** End Function SetCompanionLightEnabled Property Definitions ***************************
const UECodeGen_Private::FFunctionParams UHT_STATICS::FuncParams = { { (FTypeConstructFunc*)Z_Construct_UClass_UTimeOfDaySubsystem, nullptr, "SetCompanionLightEnabled", UHT_STATICS::PropPointers, UE_ARRAY_COUNT(UHT_STATICS::PropPointers), DataSizeOf<UHT_STATICS::TimeOfDaySubsystem_eventSetCompanionLightEnabled_Parms>(), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(UHT_STATICS::Type_MetaData), UHT_STATICS::Type_MetaData)},  };
static_assert(sizeof(UHT_STATICS::TimeOfDaySubsystem_eventSetCompanionLightEnabled_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UTimeOfDaySubsystem_SetCompanionLightEnabled(ETypeConstructPhase Phase)
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, UHT_STATICS::FuncParams);
	}
	return ReturnFunction;
}
#undef UHT_STATICS
DEFINE_FUNCTION(UTimeOfDaySubsystem::execSetCompanionLightEnabled)
{
	P_GET_UBOOL(Z_Param_bEnabled);
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->SetCompanionLightEnabled(Z_Param_bEnabled);
	P_NATIVE_END;
}
// ********** End Class UTimeOfDaySubsystem Function SetCompanionLightEnabled **********************

// ********** Begin Class UTimeOfDaySubsystem Function SetDebugReadoutEnabled **********************
#ifdef UHT_STATICS
#error UHT_STATICS already defined
#endif
#define UHT_STATICS Z_Construct_UFunction_UTimeOfDaySubsystem_SetDebugReadoutEnabled_Statics
struct UHT_STATICS
{
	struct TimeOfDaySubsystem_eventSetDebugReadoutEnabled_Parms
	{
		bool bEnabled;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Type_MetaData[] = {
		{ "Category", "Time Of Day|Debug" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "// On-screen overlay: current state, transition progress, a timeline of states, live light values and the hotkeys.\n" },
#endif
		{ "ModuleRelativePath", "Public/TimeOfDaySubsystem.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "On-screen overlay: current state, transition progress, a timeline of states, live light values and the hotkeys." },
#endif
	};
#endif // WITH_METADATA

// ********** Begin Function SetDebugReadoutEnabled constinit property declarations ****************
	static void NewProp_bEnabled_SetBit(void* Obj)
	{
		((TimeOfDaySubsystem_eventSetDebugReadoutEnabled_Parms*)Obj)->bEnabled = 1;
	}
	static const UECodeGen_Private::FBoolPropertyParams NewProp_bEnabled;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function SetDebugReadoutEnabled constinit property declarations ******************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function SetDebugReadoutEnabled Property Definitions ***************************
const UECodeGen_Private::FBoolPropertyParams UHT_STATICS::NewProp_bEnabled = { "bEnabled", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, nullptr, nullptr, 1, sizeof(bool), sizeof(TimeOfDaySubsystem_eventSetDebugReadoutEnabled_Parms), &UHT_STATICS::NewProp_bEnabled_SetBit, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const UHT_STATICS::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_bEnabled,
};
static_assert(UE_ARRAY_COUNT(UHT_STATICS::PropPointers) < 2048);
// ********** End Function SetDebugReadoutEnabled Property Definitions *****************************
const UECodeGen_Private::FFunctionParams UHT_STATICS::FuncParams = { { (FTypeConstructFunc*)Z_Construct_UClass_UTimeOfDaySubsystem, nullptr, "SetDebugReadoutEnabled", UHT_STATICS::PropPointers, UE_ARRAY_COUNT(UHT_STATICS::PropPointers), DataSizeOf<UHT_STATICS::TimeOfDaySubsystem_eventSetDebugReadoutEnabled_Parms>(), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(UHT_STATICS::Type_MetaData), UHT_STATICS::Type_MetaData)},  };
static_assert(sizeof(UHT_STATICS::TimeOfDaySubsystem_eventSetDebugReadoutEnabled_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UTimeOfDaySubsystem_SetDebugReadoutEnabled(ETypeConstructPhase Phase)
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, UHT_STATICS::FuncParams);
	}
	return ReturnFunction;
}
#undef UHT_STATICS
DEFINE_FUNCTION(UTimeOfDaySubsystem::execSetDebugReadoutEnabled)
{
	P_GET_UBOOL(Z_Param_bEnabled);
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->SetDebugReadoutEnabled(Z_Param_bEnabled);
	P_NATIVE_END;
}
// ********** End Class UTimeOfDaySubsystem Function SetDebugReadoutEnabled ************************

// ********** Begin Class UTimeOfDaySubsystem Function SetHotkeysEnabled ***************************
#ifdef UHT_STATICS
#error UHT_STATICS already defined
#endif
#define UHT_STATICS Z_Construct_UFunction_UTimeOfDaySubsystem_SetHotkeysEnabled_Statics
struct UHT_STATICS
{
	struct TimeOfDaySubsystem_eventSetHotkeysEnabled_Parms
	{
		bool bEnabled;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Type_MetaData[] = {
		{ "Category", "Time Of Day|Debug" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "// Keyboard shortcuts while playing:  ] next  [ previous  (hold Shift for fast)  \\ demo loop  ; level lighting  / overlay\n" },
#endif
		{ "ModuleRelativePath", "Public/TimeOfDaySubsystem.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Keyboard shortcuts while playing:  ] next  [ previous  (hold Shift for fast)  \\ demo loop  ; level lighting  / overlay" },
#endif
	};
#endif // WITH_METADATA

// ********** Begin Function SetHotkeysEnabled constinit property declarations *********************
	static void NewProp_bEnabled_SetBit(void* Obj)
	{
		((TimeOfDaySubsystem_eventSetHotkeysEnabled_Parms*)Obj)->bEnabled = 1;
	}
	static const UECodeGen_Private::FBoolPropertyParams NewProp_bEnabled;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function SetHotkeysEnabled constinit property declarations ***********************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function SetHotkeysEnabled Property Definitions ********************************
const UECodeGen_Private::FBoolPropertyParams UHT_STATICS::NewProp_bEnabled = { "bEnabled", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, nullptr, nullptr, 1, sizeof(bool), sizeof(TimeOfDaySubsystem_eventSetHotkeysEnabled_Parms), &UHT_STATICS::NewProp_bEnabled_SetBit, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const UHT_STATICS::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_bEnabled,
};
static_assert(UE_ARRAY_COUNT(UHT_STATICS::PropPointers) < 2048);
// ********** End Function SetHotkeysEnabled Property Definitions **********************************
const UECodeGen_Private::FFunctionParams UHT_STATICS::FuncParams = { { (FTypeConstructFunc*)Z_Construct_UClass_UTimeOfDaySubsystem, nullptr, "SetHotkeysEnabled", UHT_STATICS::PropPointers, UE_ARRAY_COUNT(UHT_STATICS::PropPointers), DataSizeOf<UHT_STATICS::TimeOfDaySubsystem_eventSetHotkeysEnabled_Parms>(), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(UHT_STATICS::Type_MetaData), UHT_STATICS::Type_MetaData)},  };
static_assert(sizeof(UHT_STATICS::TimeOfDaySubsystem_eventSetHotkeysEnabled_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UTimeOfDaySubsystem_SetHotkeysEnabled(ETypeConstructPhase Phase)
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, UHT_STATICS::FuncParams);
	}
	return ReturnFunction;
}
#undef UHT_STATICS
DEFINE_FUNCTION(UTimeOfDaySubsystem::execSetHotkeysEnabled)
{
	P_GET_UBOOL(Z_Param_bEnabled);
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->SetHotkeysEnabled(Z_Param_bEnabled);
	P_NATIVE_END;
}
// ********** End Class UTimeOfDaySubsystem Function SetHotkeysEnabled *****************************

// ********** Begin Class UTimeOfDaySubsystem Function StartDemoCycle ******************************
#ifdef UHT_STATICS
#error UHT_STATICS already defined
#endif
#define UHT_STATICS Z_Construct_UFunction_UTimeOfDaySubsystem_StartDemoCycle_Statics
struct UHT_STATICS
{
	struct TimeOfDaySubsystem_eventStartDemoCycle_Parms
	{
		float HoldSeconds;
		ETimeTransitionMode TransitionMode;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Type_MetaData[] = {
		{ "Category", "Time Of Day|Debug" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "// Loops through the outdoor states (Dawn to Night) for time-lapse recording.\n" },
#endif
		{ "CPP_Default_HoldSeconds", "3.000000" },
		{ "CPP_Default_TransitionMode", "Slow" },
		{ "ModuleRelativePath", "Public/TimeOfDaySubsystem.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Loops through the outdoor states (Dawn to Night) for time-lapse recording." },
#endif
	};
#endif // WITH_METADATA

// ********** Begin Function StartDemoCycle constinit property declarations ************************
	static const UECodeGen_Private::FFloatPropertyParams NewProp_HoldSeconds;
	static const UECodeGen_Private::FBytePropertyParams NewProp_TransitionMode_Underlying;
	static const UECodeGen_Private::FEnumPropertyParams NewProp_TransitionMode;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function StartDemoCycle constinit property declarations **************************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function StartDemoCycle Property Definitions ***********************************
const UECodeGen_Private::FFloatPropertyParams UHT_STATICS::NewProp_HoldSeconds = { "HoldSeconds", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Float, nullptr, nullptr, 1, STRUCT_OFFSET(TimeOfDaySubsystem_eventStartDemoCycle_Parms, HoldSeconds), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FBytePropertyParams UHT_STATICS::NewProp_TransitionMode_Underlying = { "UnderlyingType", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Byte, nullptr, nullptr, 1, 0, nullptr, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FEnumPropertyParams UHT_STATICS::NewProp_TransitionMode = { "TransitionMode", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Enum, nullptr, nullptr, 1, STRUCT_OFFSET(TimeOfDaySubsystem_eventStartDemoCycle_Parms, TransitionMode), Z_Construct_UEnum_TimeOfDay_ETimeTransitionMode, METADATA_PARAMS(0, nullptr) }; // e408831340c582aafd4d81eacaa0ff00939513ad
const UECodeGen_Private::FPropertyParamsBase* const UHT_STATICS::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_HoldSeconds,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_TransitionMode_Underlying,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_TransitionMode,
};
static_assert(UE_ARRAY_COUNT(UHT_STATICS::PropPointers) < 2048);
// ********** End Function StartDemoCycle Property Definitions *************************************
const UECodeGen_Private::FFunctionParams UHT_STATICS::FuncParams = { { (FTypeConstructFunc*)Z_Construct_UClass_UTimeOfDaySubsystem, nullptr, "StartDemoCycle", UHT_STATICS::PropPointers, UE_ARRAY_COUNT(UHT_STATICS::PropPointers), DataSizeOf<UHT_STATICS::TimeOfDaySubsystem_eventStartDemoCycle_Parms>(), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(UHT_STATICS::Type_MetaData), UHT_STATICS::Type_MetaData)},  };
static_assert(sizeof(UHT_STATICS::TimeOfDaySubsystem_eventStartDemoCycle_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UTimeOfDaySubsystem_StartDemoCycle(ETypeConstructPhase Phase)
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, UHT_STATICS::FuncParams);
	}
	return ReturnFunction;
}
#undef UHT_STATICS
DEFINE_FUNCTION(UTimeOfDaySubsystem::execStartDemoCycle)
{
	P_GET_PROPERTY(FFloatProperty,Z_Param_HoldSeconds);
	P_GET_ENUM(ETimeTransitionMode,Z_Param_TransitionMode);
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->StartDemoCycle(Z_Param_HoldSeconds,ETimeTransitionMode(Z_Param_TransitionMode));
	P_NATIVE_END;
}
// ********** End Class UTimeOfDaySubsystem Function StartDemoCycle ********************************

// ********** Begin Class UTimeOfDaySubsystem Function StepTimeState *******************************
#ifdef UHT_STATICS
#error UHT_STATICS already defined
#endif
#define UHT_STATICS Z_Construct_UFunction_UTimeOfDaySubsystem_StepTimeState_Statics
struct UHT_STATICS
{
	struct TimeOfDaySubsystem_eventStepTimeState_Parms
	{
		bool bForward;
		ETimeTransitionMode TransitionMode;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Type_MetaData[] = {
		{ "Category", "Time Of Day|Debug" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "// Steps to the next (or previous) outdoor state.\n" },
#endif
		{ "CPP_Default_bForward", "true" },
		{ "CPP_Default_TransitionMode", "Fast" },
		{ "ModuleRelativePath", "Public/TimeOfDaySubsystem.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Steps to the next (or previous) outdoor state." },
#endif
	};
#endif // WITH_METADATA

// ********** Begin Function StepTimeState constinit property declarations *************************
	static void NewProp_bForward_SetBit(void* Obj)
	{
		((TimeOfDaySubsystem_eventStepTimeState_Parms*)Obj)->bForward = 1;
	}
	static const UECodeGen_Private::FBoolPropertyParams NewProp_bForward;
	static const UECodeGen_Private::FBytePropertyParams NewProp_TransitionMode_Underlying;
	static const UECodeGen_Private::FEnumPropertyParams NewProp_TransitionMode;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function StepTimeState constinit property declarations ***************************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function StepTimeState Property Definitions ************************************
const UECodeGen_Private::FBoolPropertyParams UHT_STATICS::NewProp_bForward = { "bForward", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, nullptr, nullptr, 1, sizeof(bool), sizeof(TimeOfDaySubsystem_eventStepTimeState_Parms), &UHT_STATICS::NewProp_bForward_SetBit, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FBytePropertyParams UHT_STATICS::NewProp_TransitionMode_Underlying = { "UnderlyingType", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Byte, nullptr, nullptr, 1, 0, nullptr, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FEnumPropertyParams UHT_STATICS::NewProp_TransitionMode = { "TransitionMode", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Enum, nullptr, nullptr, 1, STRUCT_OFFSET(TimeOfDaySubsystem_eventStepTimeState_Parms, TransitionMode), Z_Construct_UEnum_TimeOfDay_ETimeTransitionMode, METADATA_PARAMS(0, nullptr) }; // e408831340c582aafd4d81eacaa0ff00939513ad
const UECodeGen_Private::FPropertyParamsBase* const UHT_STATICS::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_bForward,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_TransitionMode_Underlying,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_TransitionMode,
};
static_assert(UE_ARRAY_COUNT(UHT_STATICS::PropPointers) < 2048);
// ********** End Function StepTimeState Property Definitions **************************************
const UECodeGen_Private::FFunctionParams UHT_STATICS::FuncParams = { { (FTypeConstructFunc*)Z_Construct_UClass_UTimeOfDaySubsystem, nullptr, "StepTimeState", UHT_STATICS::PropPointers, UE_ARRAY_COUNT(UHT_STATICS::PropPointers), DataSizeOf<UHT_STATICS::TimeOfDaySubsystem_eventStepTimeState_Parms>(), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(UHT_STATICS::Type_MetaData), UHT_STATICS::Type_MetaData)},  };
static_assert(sizeof(UHT_STATICS::TimeOfDaySubsystem_eventStepTimeState_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UTimeOfDaySubsystem_StepTimeState(ETypeConstructPhase Phase)
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, UHT_STATICS::FuncParams);
	}
	return ReturnFunction;
}
#undef UHT_STATICS
DEFINE_FUNCTION(UTimeOfDaySubsystem::execStepTimeState)
{
	P_GET_UBOOL(Z_Param_bForward);
	P_GET_ENUM(ETimeTransitionMode,Z_Param_TransitionMode);
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->StepTimeState(Z_Param_bForward,ETimeTransitionMode(Z_Param_TransitionMode));
	P_NATIVE_END;
}
// ********** End Class UTimeOfDaySubsystem Function StepTimeState *********************************

// ********** Begin Class UTimeOfDaySubsystem Function StopDemoCycle *******************************
#ifdef UHT_STATICS
#error UHT_STATICS already defined
#endif
#define UHT_STATICS Z_Construct_UFunction_UTimeOfDaySubsystem_StopDemoCycle_Statics
struct UHT_STATICS
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Type_MetaData[] = {
		{ "Category", "Time Of Day|Debug" },
		{ "ModuleRelativePath", "Public/TimeOfDaySubsystem.h" },
	};
#endif // WITH_METADATA

// ********** Begin Function StopDemoCycle constinit property declarations *************************
// ********** End Function StopDemoCycle constinit property declarations ***************************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FFunctionParams UHT_STATICS::FuncParams = { { (FTypeConstructFunc*)Z_Construct_UClass_UTimeOfDaySubsystem, nullptr, "StopDemoCycle", nullptr, 0, 0, RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(UHT_STATICS::Type_MetaData), UHT_STATICS::Type_MetaData)},  };
UFunction* Z_Construct_UFunction_UTimeOfDaySubsystem_StopDemoCycle(ETypeConstructPhase Phase)
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, UHT_STATICS::FuncParams);
	}
	return ReturnFunction;
}
#undef UHT_STATICS
DEFINE_FUNCTION(UTimeOfDaySubsystem::execStopDemoCycle)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->StopDemoCycle();
	P_NATIVE_END;
}
// ********** End Class UTimeOfDaySubsystem Function StopDemoCycle *********************************

// ********** Begin Class UTimeOfDaySubsystem ******************************************************
#ifdef UHT_STATICS
#error UHT_STATICS already defined
#endif
#define UHT_STATICS Z_Construct_UClass_UTimeOfDaySubsystem_Statics
struct UHT_STATICS
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Type_MetaData[] = {
		{ "BlueprintType", "true" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/*\n * UTimeOfDaySubsystem\n *\n * World subsystem that manages discrete time-of-day states, smooth lighting transitions,\n * a cinematic lock, and an optional companion light.\n *\n * Design notes:\n *   - World subsystem: access from anywhere via GetWorld()->GetSubsystem<UTimeOfDaySubsystem>().\n *   - Data-table-driven: per-state presets (FTimeStatePreset) can be authored in a UDataTable\n *     and supplied at initialize time, so lighting is tuned without code changes.\n *   - C++ fallback defaults in GetPresetForState() mean the system runs without a data table.\n *   - Captures the level's own lighting on initialize (state None), so a scene keeps its\n *     authored look until a state is requested, and transitions start from what's on screen.\n *   - Cinematic lock: CinematicBeginOverride blocks gameplay state requests during a cutscene,\n *     and auto-releases after a timeout if CinematicEndOverride is never called.\n *   - Transitions blend every lighting property each tick (sun rotation via quaternion slerp);\n *     the sky light recapture is deferred to the end of a transition to avoid per-frame GPU cost.\n *   - Auto-discovery: finds the sun, sky light, height fog, unbound post process volume and an\n *     optional sky sphere (by interface). Tag an actor \"TimeOfDaySun\" or \"TimeOfDayMoon\" to pick\n *     a specific light when a level has several.\n *   - Testing tools: console commands (tod.Set, tod.Next, tod.Demo, tod.Debug, tod.Status) and\n *     an on-screen readout, so states can be scrubbed live without any Blueprint wiring.\n */" },
#endif
		{ "IncludePath", "TimeOfDaySubsystem.h" },
		{ "ModuleRelativePath", "Public/TimeOfDaySubsystem.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "UTimeOfDaySubsystem\n\nWorld subsystem that manages discrete time-of-day states, smooth lighting transitions,\na cinematic lock, and an optional companion light.\n\nDesign notes:\n  - World subsystem: access from anywhere via GetWorld()->GetSubsystem<UTimeOfDaySubsystem>().\n  - Data-table-driven: per-state presets (FTimeStatePreset) can be authored in a UDataTable\n    and supplied at initialize time, so lighting is tuned without code changes.\n  - C++ fallback defaults in GetPresetForState() mean the system runs without a data table.\n  - Captures the level's own lighting on initialize (state None), so a scene keeps its\n    authored look until a state is requested, and transitions start from what's on screen.\n  - Cinematic lock: CinematicBeginOverride blocks gameplay state requests during a cutscene,\n    and auto-releases after a timeout if CinematicEndOverride is never called.\n  - Transitions blend every lighting property each tick (sun rotation via quaternion slerp);\n    the sky light recapture is deferred to the end of a transition to avoid per-frame GPU cost.\n  - Auto-discovery: finds the sun, sky light, height fog, unbound post process volume and an\n    optional sky sphere (by interface). Tag an actor \"TimeOfDaySun\" or \"TimeOfDayMoon\" to pick\n    a specific light when a level has several.\n  - Testing tools: console commands (tod.Set, tod.Next, tod.Demo, tod.Debug, tod.Status) and\n    an on-screen readout, so states can be scrubbed live without any Blueprint wiring." },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_OnTimeStateChanged_MetaData[] = {
		{ "Category", "Time Of Day" },
		{ "ModuleRelativePath", "Public/TimeOfDaySubsystem.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_SunLight_MetaData[] = {
#if !UE_BUILD_SHIPPING
		{ "Comment", "// Lighting actors, auto-discovered\n" },
#endif
		{ "ModuleRelativePath", "Public/TimeOfDaySubsystem.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Lighting actors, auto-discovered" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_SkyLight_MetaData[] = {
		{ "ModuleRelativePath", "Public/TimeOfDaySubsystem.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_HeightFog_MetaData[] = {
		{ "ModuleRelativePath", "Public/TimeOfDaySubsystem.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_PostProcessVolume_MetaData[] = {
		{ "ModuleRelativePath", "Public/TimeOfDaySubsystem.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_SkySphere_MetaData[] = {
#if !UE_BUILD_SHIPPING
		{ "Comment", "// Optional actors, null-checked before use\n" },
#endif
		{ "ModuleRelativePath", "Public/TimeOfDaySubsystem.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Optional actors, null-checked before use" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_MoonLight_MetaData[] = {
		{ "ModuleRelativePath", "Public/TimeOfDaySubsystem.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_ActiveCompanion_MetaData[] = {
#if !UE_BUILD_SHIPPING
		{ "Comment", "// Companion light\n" },
#endif
		{ "ModuleRelativePath", "Public/TimeOfDaySubsystem.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Companion light" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_CompanionLightClass_MetaData[] = {
		{ "ModuleRelativePath", "Public/TimeOfDaySubsystem.h" },
	};
#endif // WITH_METADATA

// ********** Begin Class UTimeOfDaySubsystem constinit property declarations **********************
	static const UECodeGen_Private::FMulticastDelegatePropertyParams NewProp_OnTimeStateChanged;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_SunLight;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_SkyLight;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_HeightFog;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_PostProcessVolume;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_SkySphere;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_MoonLight;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_ActiveCompanion;
	static const UECodeGen_Private::FClassPropertyParams NewProp_CompanionLightClass;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Class UTimeOfDaySubsystem constinit property declarations ************************
	static constexpr UE::CodeGen::FClassNativeFunction Funcs[] = {
		{ .NameUTF8 = UTF8TEXT("CinematicBeginOverride"), .Pointer = &UTimeOfDaySubsystem::execCinematicBeginOverride },
		{ .NameUTF8 = UTF8TEXT("CinematicEndOverride"), .Pointer = &UTimeOfDaySubsystem::execCinematicEndOverride },
		{ .NameUTF8 = UTF8TEXT("GetCurrentTimeState"), .Pointer = &UTimeOfDaySubsystem::execGetCurrentTimeState },
		{ .NameUTF8 = UTF8TEXT("InitializeTimeOfDay"), .Pointer = &UTimeOfDaySubsystem::execInitializeTimeOfDay },
		{ .NameUTF8 = UTF8TEXT("IsDebugReadoutEnabled"), .Pointer = &UTimeOfDaySubsystem::execIsDebugReadoutEnabled },
		{ .NameUTF8 = UTF8TEXT("IsTimeOfDayInitialized"), .Pointer = &UTimeOfDaySubsystem::execIsTimeOfDayInitialized },
		{ .NameUTF8 = UTF8TEXT("IsTransitioning"), .Pointer = &UTimeOfDaySubsystem::execIsTransitioning },
		{ .NameUTF8 = UTF8TEXT("RequestTimeState"), .Pointer = &UTimeOfDaySubsystem::execRequestTimeState },
		{ .NameUTF8 = UTF8TEXT("RestoreTimeState"), .Pointer = &UTimeOfDaySubsystem::execRestoreTimeState },
		{ .NameUTF8 = UTF8TEXT("SetCompanionLightEnabled"), .Pointer = &UTimeOfDaySubsystem::execSetCompanionLightEnabled },
		{ .NameUTF8 = UTF8TEXT("SetDebugReadoutEnabled"), .Pointer = &UTimeOfDaySubsystem::execSetDebugReadoutEnabled },
		{ .NameUTF8 = UTF8TEXT("SetHotkeysEnabled"), .Pointer = &UTimeOfDaySubsystem::execSetHotkeysEnabled },
		{ .NameUTF8 = UTF8TEXT("StartDemoCycle"), .Pointer = &UTimeOfDaySubsystem::execStartDemoCycle },
		{ .NameUTF8 = UTF8TEXT("StepTimeState"), .Pointer = &UTimeOfDaySubsystem::execStepTimeState },
		{ .NameUTF8 = UTF8TEXT("StopDemoCycle"), .Pointer = &UTimeOfDaySubsystem::execStopDemoCycle },
	};
	static FTypeConstructFunc* DependentSingletons[];
	static constexpr FClassFunctionLinkInfo FuncInfo[] = {
		{ &Z_Construct_UFunction_UTimeOfDaySubsystem_CinematicBeginOverride, "CinematicBeginOverride" }, // fac5c72e20b44ace8cdcfaac684fc66395fb878d
		{ &Z_Construct_UFunction_UTimeOfDaySubsystem_CinematicEndOverride, "CinematicEndOverride" }, // 5dc7e56f00ef193a3221c4664989d0dc49082dc0
		{ &Z_Construct_UFunction_UTimeOfDaySubsystem_GetCurrentTimeState, "GetCurrentTimeState" }, // eed77b57d592e542ef7ef02e0ce5a88784684b49
		{ &Z_Construct_UFunction_UTimeOfDaySubsystem_InitializeTimeOfDay, "InitializeTimeOfDay" }, // 2cdc50cf0b1a78c46bec50b9dc399bc064c46d27
		{ &Z_Construct_UFunction_UTimeOfDaySubsystem_IsDebugReadoutEnabled, "IsDebugReadoutEnabled" }, // 9a6eb06d7699591632ded9d6b9b4e9c1f7a67119
		{ &Z_Construct_UFunction_UTimeOfDaySubsystem_IsTimeOfDayInitialized, "IsTimeOfDayInitialized" }, // f6de61e8474e375860f36d1c30c8e93c6ae387cc
		{ &Z_Construct_UFunction_UTimeOfDaySubsystem_IsTransitioning, "IsTransitioning" }, // 2c5564ea8f2d0e1eea6694e31973f6fd01b8460d
		{ &Z_Construct_UFunction_UTimeOfDaySubsystem_RequestTimeState, "RequestTimeState" }, // 560c0f401517fc30b0509abbab880a9958c01bd7
		{ &Z_Construct_UFunction_UTimeOfDaySubsystem_RestoreTimeState, "RestoreTimeState" }, // a2978754d611b90970f132d381cf7883f7074e2b
		{ &Z_Construct_UFunction_UTimeOfDaySubsystem_SetCompanionLightEnabled, "SetCompanionLightEnabled" }, // 1c607659ee0f02f62c98d41462ac79064b682ba2
		{ &Z_Construct_UFunction_UTimeOfDaySubsystem_SetDebugReadoutEnabled, "SetDebugReadoutEnabled" }, // b58167ee7502f9e1c7157cf5f4a38ac84c82cbbf
		{ &Z_Construct_UFunction_UTimeOfDaySubsystem_SetHotkeysEnabled, "SetHotkeysEnabled" }, // e5ffafb7bb49b3b5c02568b5b948cd56ab12d4fa
		{ &Z_Construct_UFunction_UTimeOfDaySubsystem_StartDemoCycle, "StartDemoCycle" }, // b8817706d9f07cd748e604c00d508fc4f076ed9d
		{ &Z_Construct_UFunction_UTimeOfDaySubsystem_StepTimeState, "StepTimeState" }, // 86f5ba71dfbb72f2885b547d9fd0e04bb984e42c
		{ &Z_Construct_UFunction_UTimeOfDaySubsystem_StopDemoCycle, "StopDemoCycle" }, // 924d1949ddf5f5c2ce30aa9a9c288576c708d25c
	};
	static_assert(UE_ARRAY_COUNT(FuncInfo) < 2048);
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UTimeOfDaySubsystem>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
}; // struct UHT_STATICS

// ********** Begin Class UTimeOfDaySubsystem Property Definitions *********************************
const UECodeGen_Private::FMulticastDelegatePropertyParams UHT_STATICS::NewProp_OnTimeStateChanged = { "OnTimeStateChanged", nullptr, (EPropertyFlags)0x0010000010080000, UECodeGen_Private::EPropertyGenFlags::InlineMulticastDelegate, nullptr, nullptr, 1, STRUCT_OFFSET(UTimeOfDaySubsystem, OnTimeStateChanged), Z_Construct_UDelegateFunction_TimeOfDay_OnTimeStateChanged__DelegateSignature, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_OnTimeStateChanged_MetaData), NewProp_OnTimeStateChanged_MetaData) }; // db7ecdc7d0c3a48537a2e39aebd4e78d9210bf95
const UECodeGen_Private::FObjectPropertyParams UHT_STATICS::NewProp_SunLight = { "SunLight", nullptr, (EPropertyFlags)0x0144000000000000, UECodeGen_Private::EPropertyGenFlags::Object | UECodeGen_Private::EPropertyGenFlags::ObjectPtr, nullptr, nullptr, 1, STRUCT_OFFSET(UTimeOfDaySubsystem, SunLight), Z_Construct_UClass_ADirectionalLight, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_SunLight_MetaData), NewProp_SunLight_MetaData) };
const UECodeGen_Private::FObjectPropertyParams UHT_STATICS::NewProp_SkyLight = { "SkyLight", nullptr, (EPropertyFlags)0x0144000000000000, UECodeGen_Private::EPropertyGenFlags::Object | UECodeGen_Private::EPropertyGenFlags::ObjectPtr, nullptr, nullptr, 1, STRUCT_OFFSET(UTimeOfDaySubsystem, SkyLight), Z_Construct_UClass_ASkyLight, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_SkyLight_MetaData), NewProp_SkyLight_MetaData) };
const UECodeGen_Private::FObjectPropertyParams UHT_STATICS::NewProp_HeightFog = { "HeightFog", nullptr, (EPropertyFlags)0x0144000000000000, UECodeGen_Private::EPropertyGenFlags::Object | UECodeGen_Private::EPropertyGenFlags::ObjectPtr, nullptr, nullptr, 1, STRUCT_OFFSET(UTimeOfDaySubsystem, HeightFog), Z_Construct_UClass_AActor, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_HeightFog_MetaData), NewProp_HeightFog_MetaData) };
const UECodeGen_Private::FObjectPropertyParams UHT_STATICS::NewProp_PostProcessVolume = { "PostProcessVolume", nullptr, (EPropertyFlags)0x0144000000000000, UECodeGen_Private::EPropertyGenFlags::Object | UECodeGen_Private::EPropertyGenFlags::ObjectPtr, nullptr, nullptr, 1, STRUCT_OFFSET(UTimeOfDaySubsystem, PostProcessVolume), Z_Construct_UClass_APostProcessVolume, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_PostProcessVolume_MetaData), NewProp_PostProcessVolume_MetaData) };
const UECodeGen_Private::FObjectPropertyParams UHT_STATICS::NewProp_SkySphere = { "SkySphere", nullptr, (EPropertyFlags)0x0144000000000000, UECodeGen_Private::EPropertyGenFlags::Object | UECodeGen_Private::EPropertyGenFlags::ObjectPtr, nullptr, nullptr, 1, STRUCT_OFFSET(UTimeOfDaySubsystem, SkySphere), Z_Construct_UClass_AActor, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_SkySphere_MetaData), NewProp_SkySphere_MetaData) };
const UECodeGen_Private::FObjectPropertyParams UHT_STATICS::NewProp_MoonLight = { "MoonLight", nullptr, (EPropertyFlags)0x0144000000000000, UECodeGen_Private::EPropertyGenFlags::Object | UECodeGen_Private::EPropertyGenFlags::ObjectPtr, nullptr, nullptr, 1, STRUCT_OFFSET(UTimeOfDaySubsystem, MoonLight), Z_Construct_UClass_AActor, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_MoonLight_MetaData), NewProp_MoonLight_MetaData) };
const UECodeGen_Private::FObjectPropertyParams UHT_STATICS::NewProp_ActiveCompanion = { "ActiveCompanion", nullptr, (EPropertyFlags)0x0144000000000000, UECodeGen_Private::EPropertyGenFlags::Object | UECodeGen_Private::EPropertyGenFlags::ObjectPtr, nullptr, nullptr, 1, STRUCT_OFFSET(UTimeOfDaySubsystem, ActiveCompanion), Z_Construct_UClass_AActor, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_ActiveCompanion_MetaData), NewProp_ActiveCompanion_MetaData) };
const UECodeGen_Private::FClassPropertyParams UHT_STATICS::NewProp_CompanionLightClass = { "CompanionLightClass", nullptr, (EPropertyFlags)0x0044000000000000, UECodeGen_Private::EPropertyGenFlags::Class, nullptr, nullptr, 1, STRUCT_OFFSET(UTimeOfDaySubsystem, CompanionLightClass), Z_Construct_UClass_UClass, Z_Construct_UClass_AActor, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_CompanionLightClass_MetaData), NewProp_CompanionLightClass_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const UHT_STATICS::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_OnTimeStateChanged,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_SunLight,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_SkyLight,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_HeightFog,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_PostProcessVolume,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_SkySphere,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_MoonLight,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_ActiveCompanion,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_CompanionLightClass,
};
static_assert(UE_ARRAY_COUNT(UHT_STATICS::PropPointers) < 2048);
// ********** End Class UTimeOfDaySubsystem Property Definitions ***********************************
FTypeConstructFunc* UHT_STATICS::DependentSingletons[] = {
	(FTypeConstructFunc*)Z_Construct_UClass_UTickableWorldSubsystem,
	(FTypeConstructFunc*)Z_Construct_UPackage__Script_TimeOfDay,
};
static_assert(UE_ARRAY_COUNT(UHT_STATICS::DependentSingletons) < 16);
const UECodeGen_Private::FClassParams UHT_STATICS::ClassParams = {
	&Z_Construct_UClass_UTimeOfDaySubsystem,
	nullptr,
	&StaticCppClassTypeInfo,
	DependentSingletons,
	FuncInfo,
	UHT_STATICS::PropPointers,
	nullptr,
	UE_ARRAY_COUNT(DependentSingletons),
	UE_ARRAY_COUNT(FuncInfo),
	UE_ARRAY_COUNT(UHT_STATICS::PropPointers),
	0,
	0x009000A0u,
	METADATA_PARAMS(UE_ARRAY_COUNT(UHT_STATICS::Type_MetaData), UHT_STATICS::Type_MetaData)
};
static void UTimeOfDaySubsystem_StaticRegisterNativesUTimeOfDaySubsystem()
{
	UClass* Class = UTimeOfDaySubsystem::StaticClass();
	FNativeFunctionRegistrar::RegisterFunctions(Class, 		MakeConstArrayView(UHT_STATICS::Funcs));
}
FClassRegistrationInfo Z_Registration_Info_UClass_UTimeOfDaySubsystem;
UClass* Z_Construct_UClass_UTimeOfDaySubsystem(ETypeConstructPhase Phase)
{
	if (Phase == ETypeConstructPhase::Inner)
	{
		using TClass = UTimeOfDaySubsystem;
		if (!Z_Registration_Info_UClass_UTimeOfDaySubsystem.InnerSingleton)
		{
			GetPrivateStaticClassBody(
				TClass::StaticPackage(),
				TEXT("TimeOfDaySubsystem"),
				Z_Registration_Info_UClass_UTimeOfDaySubsystem.InnerSingleton,
				UTimeOfDaySubsystem_StaticRegisterNativesUTimeOfDaySubsystem,
				DataSizeOf<TClass>(),
				alignof(TClass),
				TClass::StaticClassFlags,
				TClass::StaticClassCastFlags(),
				TClass::StaticConfigName(),
				(UClass::ClassConstructorType)InternalConstructor<TClass>,
				(UClass::ClassVTableHelperCtorCallerType)InternalVTableHelperCtorCaller<TClass>,
				UOBJECT_CPPCLASS_STATICFUNCTIONS_FORCLASS(TClass),
				&TClass::Super::StaticClass,
				&TClass::WithinClass::StaticClass
			);
		}
		return Z_Registration_Info_UClass_UTimeOfDaySubsystem.InnerSingleton;
	}
	if (!Z_Registration_Info_UClass_UTimeOfDaySubsystem.OuterSingleton)
	{
		UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_UTimeOfDaySubsystem.OuterSingleton, UHT_STATICS::ClassParams);
	}
	return Z_Registration_Info_UClass_UTimeOfDaySubsystem.OuterSingleton;
}
#undef UHT_STATICS
UTimeOfDaySubsystem::UTimeOfDaySubsystem() {}
DEFINE_VTABLE_PTR_HELPER_CTOR_NS(, UTimeOfDaySubsystem);
UTimeOfDaySubsystem::~UTimeOfDaySubsystem() {}
// ********** End Class UTimeOfDaySubsystem ********************************************************

// ********** Begin Registration *******************************************************************
#ifdef UHT_STATICS
#error UHT_STATICS already defined
#endif
#define UHT_STATICS Z_CompiledInDeferFile_FID_ValleyoftheAncient_Plugins_TimeOfDay_Source_TimeOfDay_Public_TimeOfDaySubsystem_h__Script_TimeOfDay_Statics
struct UHT_STATICS
{
	static constexpr FClassRegisterCompiledInInfo ClassInfo[] = {
		{ Z_Construct_UClass_UTimeOfDaySubsystem, TEXT("UTimeOfDaySubsystem"), &Z_Registration_Info_UClass_UTimeOfDaySubsystem, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(UTimeOfDaySubsystem), 709652076U) },
	};
}; // UHT_STATICS 
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_ValleyoftheAncient_Plugins_TimeOfDay_Source_TimeOfDay_Public_TimeOfDaySubsystem_h__Script_TimeOfDay_2a5ae6b3d8fdcdcde3be0bac232393e6273416c0{
	TEXT("/Script/TimeOfDay"),
	UHT_STATICS::ClassInfo, UE_ARRAY_COUNT(UHT_STATICS::ClassInfo),
	nullptr, 0,
	nullptr, 0,
	nullptr, 0,
};
#undef UHT_STATICS
// ********** End Registration *********************************************************************
#undef UHT_STRUCT_BASE

PRAGMA_ENABLE_DEPRECATION_WARNINGS
