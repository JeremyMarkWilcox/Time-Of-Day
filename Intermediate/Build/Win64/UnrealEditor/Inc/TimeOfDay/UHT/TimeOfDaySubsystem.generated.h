// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

// IWYU pragma: private, include "TimeOfDaySubsystem.h"

#ifdef TIMEOFDAY_TimeOfDaySubsystem_generated_h
#error "TimeOfDaySubsystem.generated.h already included, missing '#pragma once' in TimeOfDaySubsystem.h"
#endif
#define TIMEOFDAY_TimeOfDaySubsystem_generated_h

#include "UObject/ObjectMacros.h"
#include "UObject/ReflectedTypeAccessors.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
class UDataTable;
enum class ETimeOfDayState : uint8;
enum class ETimeTransitionMode : uint8;
struct FTimeOfDayConfig;

// ********** Begin Class UTimeOfDaySubsystem ******************************************************
#define FID_ValleyoftheAncient_Plugins_TimeOfDay_Source_TimeOfDay_Public_TimeOfDaySubsystem_h_44_RPC_WRAPPERS_NO_PURE_DECLS \
	DECLARE_FUNCTION(execIsTransitioning); \
	DECLARE_FUNCTION(execIsTimeOfDayInitialized); \
	DECLARE_FUNCTION(execGetCurrentTimeState); \
	DECLARE_FUNCTION(execSetHotkeysEnabled); \
	DECLARE_FUNCTION(execIsDebugReadoutEnabled); \
	DECLARE_FUNCTION(execSetDebugReadoutEnabled); \
	DECLARE_FUNCTION(execStepTimeState); \
	DECLARE_FUNCTION(execStopDemoCycle); \
	DECLARE_FUNCTION(execStartDemoCycle); \
	DECLARE_FUNCTION(execSetCompanionLightEnabled); \
	DECLARE_FUNCTION(execRestoreTimeState); \
	DECLARE_FUNCTION(execCinematicEndOverride); \
	DECLARE_FUNCTION(execCinematicBeginOverride); \
	DECLARE_FUNCTION(execRequestTimeState); \
	DECLARE_FUNCTION(execInitializeTimeOfDay);


struct Z_Construct_UClass_UTimeOfDaySubsystem_Statics;
TIMEOFDAY_API UClass* Z_Construct_UClass_UTimeOfDaySubsystem(ETypeConstructPhase);

#define FID_ValleyoftheAncient_Plugins_TimeOfDay_Source_TimeOfDay_Public_TimeOfDaySubsystem_h_44_INCLASS_NO_PURE_DECLS \
private: \
	friend struct ::Z_Construct_UClass_UTimeOfDaySubsystem_Statics; \
	friend TIMEOFDAY_API UClass* ::Z_Construct_UClass_UTimeOfDaySubsystem(ETypeConstructPhase); \
public: \
	DECLARE_CLASS2(UTimeOfDaySubsystem, UTickableWorldSubsystem, COMPILED_IN_FLAGS(0), CASTCLASS_None, TEXT("/Script/TimeOfDay"), Z_Construct_UClass_UTimeOfDaySubsystem) \
	DECLARE_SERIALIZER(UTimeOfDaySubsystem)


#define FID_ValleyoftheAncient_Plugins_TimeOfDay_Source_TimeOfDay_Public_TimeOfDaySubsystem_h_44_ENHANCED_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API UTimeOfDaySubsystem(); \
	/** Deleted move- and copy-constructors, should never be used */ \
	UTimeOfDaySubsystem(UTimeOfDaySubsystem&&) = delete; \
	UTimeOfDaySubsystem(const UTimeOfDaySubsystem&) = delete; \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, UTimeOfDaySubsystem); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(UTimeOfDaySubsystem); \
	DEFINE_DEFAULT_CONSTRUCTOR_CALL(UTimeOfDaySubsystem) \
	NO_API virtual ~UTimeOfDaySubsystem();


#define FID_ValleyoftheAncient_Plugins_TimeOfDay_Source_TimeOfDay_Public_TimeOfDaySubsystem_h_41_PROLOG
#define FID_ValleyoftheAncient_Plugins_TimeOfDay_Source_TimeOfDay_Public_TimeOfDaySubsystem_h_44_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	FID_ValleyoftheAncient_Plugins_TimeOfDay_Source_TimeOfDay_Public_TimeOfDaySubsystem_h_44_RPC_WRAPPERS_NO_PURE_DECLS \
	FID_ValleyoftheAncient_Plugins_TimeOfDay_Source_TimeOfDay_Public_TimeOfDaySubsystem_h_44_INCLASS_NO_PURE_DECLS \
	FID_ValleyoftheAncient_Plugins_TimeOfDay_Source_TimeOfDay_Public_TimeOfDaySubsystem_h_44_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


class UTimeOfDaySubsystem;

// ********** End Class UTimeOfDaySubsystem ********************************************************

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID FID_ValleyoftheAncient_Plugins_TimeOfDay_Source_TimeOfDay_Public_TimeOfDaySubsystem_h

PRAGMA_ENABLE_DEPRECATION_WARNINGS
