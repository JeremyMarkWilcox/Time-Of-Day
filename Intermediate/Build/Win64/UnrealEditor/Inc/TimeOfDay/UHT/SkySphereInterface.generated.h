// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

// IWYU pragma: private, include "SkySphereInterface.h"

#ifdef TIMEOFDAY_SkySphereInterface_generated_h
#error "SkySphereInterface.generated.h already included, missing '#pragma once' in SkySphereInterface.h"
#endif
#define TIMEOFDAY_SkySphereInterface_generated_h

#include "UObject/ObjectMacros.h"
#include "UObject/ReflectedTypeAccessors.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS

// ********** Begin Interface USkySphereInterface **************************************************
#define FID_ValleyoftheAncient_Plugins_TimeOfDay_Source_TimeOfDay_Public_SkySphereInterface_h_10_RPC_WRAPPERS_NO_PURE_DECLS \
	virtual void RefreshSkySphere_Implementation() {}; \
	virtual void ApplySkySpherePreset_Implementation(float SunBrightness, float SunHeight, float CloudOpacity, bool bColorsByPosition) {}; \
	DECLARE_FUNCTION(execRefreshSkySphere); \
	DECLARE_FUNCTION(execApplySkySpherePreset);


#define FID_ValleyoftheAncient_Plugins_TimeOfDay_Source_TimeOfDay_Public_SkySphereInterface_h_10_CALLBACK_WRAPPERS
struct Z_Construct_UClass_USkySphereInterface_Statics;
TIMEOFDAY_API UClass* Z_Construct_UClass_USkySphereInterface(ETypeConstructPhase);

#define FID_ValleyoftheAncient_Plugins_TimeOfDay_Source_TimeOfDay_Public_SkySphereInterface_h_10_ENHANCED_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	TIMEOFDAY_API USkySphereInterface(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get()); \
	/** Deleted move- and copy-constructors, should never be used */ \
	USkySphereInterface(USkySphereInterface&&) = delete; \
	USkySphereInterface(const USkySphereInterface&) = delete; \
	DECLARE_VTABLE_PTR_HELPER_CTOR(TIMEOFDAY_API, USkySphereInterface); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(USkySphereInterface); \
	DEFINE_ABSTRACT_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(USkySphereInterface) \
	virtual ~USkySphereInterface() = default;


#define FID_ValleyoftheAncient_Plugins_TimeOfDay_Source_TimeOfDay_Public_SkySphereInterface_h_10_GENERATED_UINTERFACE_BODY() \
private: \
	friend struct ::Z_Construct_UClass_USkySphereInterface_Statics; \
	friend TIMEOFDAY_API UClass* ::Z_Construct_UClass_USkySphereInterface(ETypeConstructPhase); \
public: \
	DECLARE_CLASS2(USkySphereInterface, UInterface, COMPILED_IN_FLAGS(CLASS_Abstract | CLASS_Interface), CASTCLASS_None, TEXT("/Script/TimeOfDay"), Z_Construct_UClass_USkySphereInterface) \
	DECLARE_SERIALIZER(USkySphereInterface)


#define FID_ValleyoftheAncient_Plugins_TimeOfDay_Source_TimeOfDay_Public_SkySphereInterface_h_10_GENERATED_BODY \
	PRAGMA_DISABLE_DEPRECATION_WARNINGS \
	FID_ValleyoftheAncient_Plugins_TimeOfDay_Source_TimeOfDay_Public_SkySphereInterface_h_10_GENERATED_UINTERFACE_BODY() \
	FID_ValleyoftheAncient_Plugins_TimeOfDay_Source_TimeOfDay_Public_SkySphereInterface_h_10_ENHANCED_CONSTRUCTORS \
private: \
	PRAGMA_ENABLE_DEPRECATION_WARNINGS


#define FID_ValleyoftheAncient_Plugins_TimeOfDay_Source_TimeOfDay_Public_SkySphereInterface_h_10_INCLASS_IINTERFACE_NO_PURE_DECLS \
protected: \
	virtual ~ISkySphereInterface() {} \
public: \
	typedef USkySphereInterface UClassType; \
	typedef ISkySphereInterface ThisClass; \
	static void Execute_ApplySkySpherePreset(UObject* O, float SunBrightness, float SunHeight, float CloudOpacity, bool bColorsByPosition); \
	static void Execute_RefreshSkySphere(UObject* O); \
	[[deprecated("Do not call _getUObject(), use Cast.")]] virtual UObject* _getUObject() const { return nullptr; }


#define FID_ValleyoftheAncient_Plugins_TimeOfDay_Source_TimeOfDay_Public_SkySphereInterface_h_7_PROLOG
#define FID_ValleyoftheAncient_Plugins_TimeOfDay_Source_TimeOfDay_Public_SkySphereInterface_h_24_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	FID_ValleyoftheAncient_Plugins_TimeOfDay_Source_TimeOfDay_Public_SkySphereInterface_h_10_RPC_WRAPPERS_NO_PURE_DECLS \
	FID_ValleyoftheAncient_Plugins_TimeOfDay_Source_TimeOfDay_Public_SkySphereInterface_h_10_CALLBACK_WRAPPERS \
	FID_ValleyoftheAncient_Plugins_TimeOfDay_Source_TimeOfDay_Public_SkySphereInterface_h_10_INCLASS_IINTERFACE_NO_PURE_DECLS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


class USkySphereInterface;

// ********** End Interface USkySphereInterface ****************************************************

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID FID_ValleyoftheAncient_Plugins_TimeOfDay_Source_TimeOfDay_Public_SkySphereInterface_h

PRAGMA_ENABLE_DEPRECATION_WARNINGS
