// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

// IWYU pragma: private, include "TimeOfDayTypes.h"

#ifdef TIMEOFDAY_TimeOfDayTypes_generated_h
#error "TimeOfDayTypes.generated.h already included, missing '#pragma once' in TimeOfDayTypes.h"
#endif
#define TIMEOFDAY_TimeOfDayTypes_generated_h

#include "UObject/ObjectMacros.h"
#include "UObject/ReflectedTypeAccessors.h"
#include "Templates/IsUEnumClass.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS

// ********** Begin ScriptStruct FTimeStatePreset **************************************************
struct Z_Construct_UScriptStruct_FTimeStatePreset_Statics;
TIMEOFDAY_API UScriptStruct* Z_Construct_UScriptStruct_FTimeStatePreset(ETypeConstructPhase);

#define FID_ValleyoftheAncient_Plugins_TimeOfDay_Source_TimeOfDay_Public_TimeOfDayTypes_h_45_GENERATED_BODY \
	friend struct ::Z_Construct_UScriptStruct_FTimeStatePreset_Statics; \
	UE_NODEBUG static UScriptStruct* StaticStruct() { return Z_Construct_UScriptStruct_FTimeStatePreset(ETypeConstructPhase::Inner); } \
	typedef FTableRowBase Super;


struct FTimeStatePreset;
// ********** End ScriptStruct FTimeStatePreset ****************************************************

// ********** Begin ScriptStruct FTimeOfDayConfig **************************************************
struct Z_Construct_UScriptStruct_FTimeOfDayConfig_Statics;
TIMEOFDAY_API UScriptStruct* Z_Construct_UScriptStruct_FTimeOfDayConfig(ETypeConstructPhase);

#define FID_ValleyoftheAncient_Plugins_TimeOfDay_Source_TimeOfDay_Public_TimeOfDayTypes_h_100_GENERATED_BODY \
	friend struct ::Z_Construct_UScriptStruct_FTimeOfDayConfig_Statics; \
	UE_NODEBUG static UScriptStruct* StaticStruct() { return Z_Construct_UScriptStruct_FTimeOfDayConfig(ETypeConstructPhase::Inner); }


struct FTimeOfDayConfig;
// ********** End ScriptStruct FTimeOfDayConfig ****************************************************

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID FID_ValleyoftheAncient_Plugins_TimeOfDay_Source_TimeOfDay_Public_TimeOfDayTypes_h

// ********** Begin Enum ETimeOfDayState ***********************************************************
#define FOREACH_ENUM_ETIMEOFDAYSTATE(op) \
	op(ETimeOfDayState::None) \
	op(ETimeOfDayState::Dawn) \
	op(ETimeOfDayState::Morning) \
	op(ETimeOfDayState::Noon) \
	op(ETimeOfDayState::Day) \
	op(ETimeOfDayState::Afternoon) \
	op(ETimeOfDayState::Evening) \
	op(ETimeOfDayState::Twilight) \
	op(ETimeOfDayState::Night) \
	op(ETimeOfDayState::Cave) \
	op(ETimeOfDayState::InsideLight) \
	op(ETimeOfDayState::InsideDark) 

enum class ETimeOfDayState : uint8;
template<> struct TIsUEnumClass<ETimeOfDayState> { enum { Value = true }; };
template<> UE_NODEBUG TIMEOFDAY_NON_ATTRIBUTED_API UEnum* StaticEnum<ETimeOfDayState>();
// ********** End Enum ETimeOfDayState *************************************************************

// ********** Begin Enum ETimeTransitionMode *******************************************************
#define FOREACH_ENUM_ETIMETRANSITIONMODE(op) \
	op(ETimeTransitionMode::None) \
	op(ETimeTransitionMode::Instant) \
	op(ETimeTransitionMode::Fast) \
	op(ETimeTransitionMode::Slow) 

enum class ETimeTransitionMode : uint8;
template<> struct TIsUEnumClass<ETimeTransitionMode> { enum { Value = true }; };
template<> UE_NODEBUG TIMEOFDAY_NON_ATTRIBUTED_API UEnum* StaticEnum<ETimeTransitionMode>();
// ********** End Enum ETimeTransitionMode *********************************************************

PRAGMA_ENABLE_DEPRECATION_WARNINGS
