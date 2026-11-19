// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "SkySphereInterface.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
static_assert(!UE_WITH_CONSTINIT_UOBJECT, "This generated code can only be compiled with !UE_WITH_CONSTINIT_UOBJECT");
void EmptyLinkFunctionForGeneratedCodeSkySphereInterface() {}

// ********** Begin Cross Module References ********************************************************
COREUOBJECT_API UClass* Z_Construct_UClass_UInterface(ETypeConstructPhase);
// ********** End Cross Module References **********************************************************

// ********** Begin Same Module References *********************************************************
UPackage* Z_Construct_UPackage__Script_TimeOfDay(ETypeConstructPhase);
TIMEOFDAY_API UClass* Z_Construct_UClass_USkySphereInterface(ETypeConstructPhase);
TIMEOFDAY_API UClass* Z_Construct_UClass_ISkySphereInterface(ETypeConstructPhase);
TIMEOFDAY_API UClass* Z_Construct_UClass_USkySphereInterface(ETypeConstructPhase);
TIMEOFDAY_API UClass* Z_Construct_UClass_ISkySphereInterface(ETypeConstructPhase);
// ********** End Same Module References ***********************************************************
#define UHT_STRUCT_BASE(INIT) UE::CodeGen::ConstInit::TCompiledInObjectPtr<const FStructBaseChain>(UE::Private::AsStructBaseChain(INIT))

// ********** Begin Interface USkySphereInterface Function ApplySkySpherePreset ********************
struct SkySphereInterface_eventApplySkySpherePreset_Parms
{
	float SunBrightness;
	float SunHeight;
	float CloudOpacity;
	bool bColorsByPosition;
};
void ISkySphereInterface::ApplySkySpherePreset(float SunBrightness, float SunHeight, float CloudOpacity, bool bColorsByPosition)
{
	check(0 && "Do not directly call Event functions in Interfaces. Call Execute_ApplySkySpherePreset instead.");
}
static FName NAME_USkySphereInterface_ApplySkySpherePreset = FName(TEXT("ApplySkySpherePreset"));
void ISkySphereInterface::Execute_ApplySkySpherePreset(UObject* O, float SunBrightness, float SunHeight, float CloudOpacity, bool bColorsByPosition)
{
	check(O != NULL);
	check(O->GetClass()->ImplementsInterface(USkySphereInterface::StaticClass()));
	SkySphereInterface_eventApplySkySpherePreset_Parms Parms;
	UFunction* const Func = O->FindFunction(NAME_USkySphereInterface_ApplySkySpherePreset);
	if (Func)
	{
		Parms.SunBrightness=std::move(SunBrightness);
		Parms.SunHeight=std::move(SunHeight);
		Parms.CloudOpacity=std::move(CloudOpacity);
		Parms.bColorsByPosition=std::move(bColorsByPosition);
		O->ProcessEvent(Func, &Parms);
	}
	else if (auto I = (ISkySphereInterface*)(O->GetNativeInterfaceAddress(USkySphereInterface::StaticClass())))
	{
		I->ApplySkySpherePreset_Implementation(SunBrightness,SunHeight,CloudOpacity,bColorsByPosition);
	}
}
#ifdef UHT_STATICS
#error UHT_STATICS already defined
#endif
#define UHT_STATICS Z_Construct_UFunction_USkySphereInterface_ApplySkySpherePreset_Statics
struct UHT_STATICS
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Type_MetaData[] = {
		{ "Category", "Time Of Day" },
		{ "ModuleRelativePath", "Public/SkySphereInterface.h" },
	};
#endif // WITH_METADATA

// ********** Begin Function ApplySkySpherePreset constinit property declarations ******************
	static const UECodeGen_Private::FFloatPropertyParams NewProp_SunBrightness;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_SunHeight;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_CloudOpacity;
	static void NewProp_bColorsByPosition_SetBit(void* Obj)
	{
		((SkySphereInterface_eventApplySkySpherePreset_Parms*)Obj)->bColorsByPosition = 1;
	}
	static const UECodeGen_Private::FBoolPropertyParams NewProp_bColorsByPosition;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function ApplySkySpherePreset constinit property declarations ********************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function ApplySkySpherePreset Property Definitions *****************************
const UECodeGen_Private::FFloatPropertyParams UHT_STATICS::NewProp_SunBrightness = { "SunBrightness", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Float, nullptr, nullptr, 1, STRUCT_OFFSET(SkySphereInterface_eventApplySkySpherePreset_Parms, SunBrightness), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FFloatPropertyParams UHT_STATICS::NewProp_SunHeight = { "SunHeight", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Float, nullptr, nullptr, 1, STRUCT_OFFSET(SkySphereInterface_eventApplySkySpherePreset_Parms, SunHeight), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FFloatPropertyParams UHT_STATICS::NewProp_CloudOpacity = { "CloudOpacity", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Float, nullptr, nullptr, 1, STRUCT_OFFSET(SkySphereInterface_eventApplySkySpherePreset_Parms, CloudOpacity), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FBoolPropertyParams UHT_STATICS::NewProp_bColorsByPosition = { "bColorsByPosition", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, nullptr, nullptr, 1, sizeof(bool), sizeof(SkySphereInterface_eventApplySkySpherePreset_Parms), &UHT_STATICS::NewProp_bColorsByPosition_SetBit, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const UHT_STATICS::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_SunBrightness,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_SunHeight,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_CloudOpacity,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_bColorsByPosition,
};
static_assert(UE_ARRAY_COUNT(UHT_STATICS::PropPointers) < 2048);
// ********** End Function ApplySkySpherePreset Property Definitions *******************************
const UECodeGen_Private::FFunctionParams UHT_STATICS::FuncParams = { { (FTypeConstructFunc*)Z_Construct_UClass_USkySphereInterface, nullptr, "ApplySkySpherePreset", UHT_STATICS::PropPointers, UE_ARRAY_COUNT(UHT_STATICS::PropPointers), DataSizeOf<SkySphereInterface_eventApplySkySpherePreset_Parms>(), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x0C020C00, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(UHT_STATICS::Type_MetaData), UHT_STATICS::Type_MetaData)},  };
static_assert(sizeof(SkySphereInterface_eventApplySkySpherePreset_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_USkySphereInterface_ApplySkySpherePreset(ETypeConstructPhase Phase)
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, UHT_STATICS::FuncParams);
	}
	return ReturnFunction;
}
#undef UHT_STATICS
DEFINE_FUNCTION(ISkySphereInterface::execApplySkySpherePreset)
{
	P_GET_PROPERTY(FFloatProperty,Z_Param_SunBrightness);
	P_GET_PROPERTY(FFloatProperty,Z_Param_SunHeight);
	P_GET_PROPERTY(FFloatProperty,Z_Param_CloudOpacity);
	P_GET_UBOOL(Z_Param_bColorsByPosition);
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->ApplySkySpherePreset_Implementation(Z_Param_SunBrightness,Z_Param_SunHeight,Z_Param_CloudOpacity,Z_Param_bColorsByPosition);
	P_NATIVE_END;
}
// ********** End Interface USkySphereInterface Function ApplySkySpherePreset **********************

// ********** Begin Interface USkySphereInterface Function RefreshSkySphere ************************
void ISkySphereInterface::RefreshSkySphere()
{
	check(0 && "Do not directly call Event functions in Interfaces. Call Execute_RefreshSkySphere instead.");
}
static FName NAME_USkySphereInterface_RefreshSkySphere = FName(TEXT("RefreshSkySphere"));
void ISkySphereInterface::Execute_RefreshSkySphere(UObject* O)
{
	check(O != NULL);
	check(O->GetClass()->ImplementsInterface(USkySphereInterface::StaticClass()));
	UFunction* const Func = O->FindFunction(NAME_USkySphereInterface_RefreshSkySphere);
	if (Func)
	{
		O->ProcessEvent(Func, NULL);
	}
	else if (auto I = (ISkySphereInterface*)(O->GetNativeInterfaceAddress(USkySphereInterface::StaticClass())))
	{
		I->RefreshSkySphere_Implementation();
	}
}
#ifdef UHT_STATICS
#error UHT_STATICS already defined
#endif
#define UHT_STATICS Z_Construct_UFunction_USkySphereInterface_RefreshSkySphere_Statics
struct UHT_STATICS
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Type_MetaData[] = {
		{ "Category", "Time Of Day" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "// Called after ApplySkySpherePreset. A BP_Sky_Sphere implementation should call RefreshMaterial here.\n" },
#endif
		{ "ModuleRelativePath", "Public/SkySphereInterface.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Called after ApplySkySpherePreset. A BP_Sky_Sphere implementation should call RefreshMaterial here." },
#endif
	};
#endif // WITH_METADATA

// ********** Begin Function RefreshSkySphere constinit property declarations **********************
// ********** End Function RefreshSkySphere constinit property declarations ************************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FFunctionParams UHT_STATICS::FuncParams = { { (FTypeConstructFunc*)Z_Construct_UClass_USkySphereInterface, nullptr, "RefreshSkySphere", nullptr, 0, 0, RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x0C020C00, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(UHT_STATICS::Type_MetaData), UHT_STATICS::Type_MetaData)},  };
UFunction* Z_Construct_UFunction_USkySphereInterface_RefreshSkySphere(ETypeConstructPhase Phase)
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, UHT_STATICS::FuncParams);
	}
	return ReturnFunction;
}
#undef UHT_STATICS
DEFINE_FUNCTION(ISkySphereInterface::execRefreshSkySphere)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->RefreshSkySphere_Implementation();
	P_NATIVE_END;
}
// ********** End Interface USkySphereInterface Function RefreshSkySphere **************************

// ********** Begin Interface USkySphereInterface **************************************************
#ifdef UHT_STATICS
#error UHT_STATICS already defined
#endif
#define UHT_STATICS Z_Construct_UClass_USkySphereInterface_Statics
struct UHT_STATICS
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Type_MetaData[] = {
		{ "BlueprintType", "true" },
		{ "ModuleRelativePath", "Public/SkySphereInterface.h" },
	};
#endif // WITH_METADATA

// ********** Begin Interface USkySphereInterface constinit property declarations ******************
// ********** End Interface USkySphereInterface constinit property declarations ********************
	static constexpr UE::CodeGen::FClassNativeFunction Funcs[] = {
		{ .NameUTF8 = UTF8TEXT("ApplySkySpherePreset"), .Pointer = &ISkySphereInterface::execApplySkySpherePreset },
		{ .NameUTF8 = UTF8TEXT("RefreshSkySphere"), .Pointer = &ISkySphereInterface::execRefreshSkySphere },
	};
	static FTypeConstructFunc* DependentSingletons[];
	static constexpr FClassFunctionLinkInfo FuncInfo[] = {
		{ &Z_Construct_UFunction_USkySphereInterface_ApplySkySpherePreset, "ApplySkySpherePreset" }, // 3879aa351a60c0aea2a381b9ecfe5b3a6056f47d
		{ &Z_Construct_UFunction_USkySphereInterface_RefreshSkySphere, "RefreshSkySphere" }, // dde6ab3c4e2fe3c98c4a9eaefea94af81338a109
	};
	static_assert(UE_ARRAY_COUNT(FuncInfo) < 2048);
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<ISkySphereInterface>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
}; // struct UHT_STATICS
FTypeConstructFunc* UHT_STATICS::DependentSingletons[] = {
	(FTypeConstructFunc*)Z_Construct_UClass_UInterface,
	(FTypeConstructFunc*)Z_Construct_UPackage__Script_TimeOfDay,
};
static_assert(UE_ARRAY_COUNT(UHT_STATICS::DependentSingletons) < 16);
const UECodeGen_Private::FClassParams UHT_STATICS::ClassParams = {
	&Z_Construct_UClass_USkySphereInterface,
	nullptr,
	&StaticCppClassTypeInfo,
	DependentSingletons,
	FuncInfo,
	nullptr,
	nullptr,
	UE_ARRAY_COUNT(DependentSingletons),
	UE_ARRAY_COUNT(FuncInfo),
	0,
	0,
	0x000840A1u,
	METADATA_PARAMS(UE_ARRAY_COUNT(UHT_STATICS::Type_MetaData), UHT_STATICS::Type_MetaData)
};
static void USkySphereInterface_StaticRegisterNativesUSkySphereInterface()
{
	UClass* Class = USkySphereInterface::StaticClass();
	FNativeFunctionRegistrar::RegisterFunctions(Class, 		MakeConstArrayView(UHT_STATICS::Funcs));
}
FClassRegistrationInfo Z_Registration_Info_UClass_USkySphereInterface;
UClass* Z_Construct_UClass_USkySphereInterface(ETypeConstructPhase Phase)
{
	if (Phase == ETypeConstructPhase::Inner)
	{
		using TClass = USkySphereInterface;
		if (!Z_Registration_Info_UClass_USkySphereInterface.InnerSingleton)
		{
			GetPrivateStaticClassBody(
				TClass::StaticPackage(),
				TEXT("SkySphereInterface"),
				Z_Registration_Info_UClass_USkySphereInterface.InnerSingleton,
				USkySphereInterface_StaticRegisterNativesUSkySphereInterface,
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
		return Z_Registration_Info_UClass_USkySphereInterface.InnerSingleton;
	}
	if (!Z_Registration_Info_UClass_USkySphereInterface.OuterSingleton)
	{
		UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_USkySphereInterface.OuterSingleton, UHT_STATICS::ClassParams);
	}
	return Z_Registration_Info_UClass_USkySphereInterface.OuterSingleton;
}
#undef UHT_STATICS
USkySphereInterface::USkySphereInterface(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {}
DEFINE_VTABLE_PTR_HELPER_CTOR_NS(, USkySphereInterface);
// ********** End Interface USkySphereInterface ****************************************************

// ********** Begin Registration *******************************************************************
#ifdef UHT_STATICS
#error UHT_STATICS already defined
#endif
#define UHT_STATICS Z_CompiledInDeferFile_FID_ValleyoftheAncient_Plugins_TimeOfDay_Source_TimeOfDay_Public_SkySphereInterface_h__Script_TimeOfDay_Statics
struct UHT_STATICS
{
	static constexpr FClassRegisterCompiledInInfo ClassInfo[] = {
		{ Z_Construct_UClass_USkySphereInterface, TEXT("USkySphereInterface"), &Z_Registration_Info_UClass_USkySphereInterface, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(USkySphereInterface), 3212314480U) },
	};
}; // UHT_STATICS 
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_ValleyoftheAncient_Plugins_TimeOfDay_Source_TimeOfDay_Public_SkySphereInterface_h__Script_TimeOfDay_f971dc0f4cabf6f4b6353d497b20876fbc382ea0{
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
