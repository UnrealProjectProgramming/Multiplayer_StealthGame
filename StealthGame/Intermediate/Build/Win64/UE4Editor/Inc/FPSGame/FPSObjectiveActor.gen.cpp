// Copyright 1998-2017 Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "GeneratedCppIncludes.h"
#include "Public/FPSObjectiveActor.h"
#ifdef _MSC_VER
#pragma warning (push)
#pragma warning (disable : 4883)
#endif
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeFPSObjectiveActor() {}
// Cross Module References
	FPSGAME_API UClass* Z_Construct_UClass_AFPSObjectiveActor_NoRegister();
	FPSGAME_API UClass* Z_Construct_UClass_AFPSObjectiveActor();
	ENGINE_API UClass* Z_Construct_UClass_AActor();
	UPackage* Z_Construct_UPackage__Script_FPSGame();
	ENGINE_API UClass* Z_Construct_UClass_UParticleSystem_NoRegister();
	ENGINE_API UClass* Z_Construct_UClass_USphereComponent_NoRegister();
	ENGINE_API UClass* Z_Construct_UClass_UStaticMeshComponent_NoRegister();
// End Cross Module References
	void AFPSObjectiveActor::StaticRegisterNativesAFPSObjectiveActor()
	{
	}
	UClass* Z_Construct_UClass_AFPSObjectiveActor_NoRegister()
	{
		return AFPSObjectiveActor::StaticClass();
	}
	UClass* Z_Construct_UClass_AFPSObjectiveActor()
	{
		static UClass* OuterClass = nullptr;
		if (!OuterClass)
		{
			static UObject* (*const DependentSingletons[])() = {
				(UObject* (*)())Z_Construct_UClass_AActor,
				(UObject* (*)())Z_Construct_UPackage__Script_FPSGame,
			};
#if WITH_METADATA
			static const UE4CodeGen_Private::FMetaDataPairParam Class_MetaDataParams[] = {
				{ "IncludePath", "FPSObjectiveActor.h" },
				{ "ModuleRelativePath", "Public/FPSObjectiveActor.h" },
			};
#endif
#if WITH_METADATA
			static const UE4CodeGen_Private::FMetaDataPairParam NewProp_PickupFX_MetaData[] = {
				{ "Category", "FX" },
				{ "ModuleRelativePath", "Public/FPSObjectiveActor.h" },
			};
#endif
			static const UE4CodeGen_Private::FObjectPropertyParams NewProp_PickupFX = { UE4CodeGen_Private::EPropertyClass::Object, "PickupFX", RF_Public|RF_Transient|RF_MarkAsNative, 0x0020080000010001, 1, nullptr, STRUCT_OFFSET(AFPSObjectiveActor, PickupFX), Z_Construct_UClass_UParticleSystem_NoRegister, METADATA_PARAMS(NewProp_PickupFX_MetaData, ARRAY_COUNT(NewProp_PickupFX_MetaData)) };
#if WITH_METADATA
			static const UE4CodeGen_Private::FMetaDataPairParam NewProp_SphereComponent_MetaData[] = {
				{ "Category", "Components" },
				{ "EditInline", "true" },
				{ "ModuleRelativePath", "Public/FPSObjectiveActor.h" },
			};
#endif
			static const UE4CodeGen_Private::FObjectPropertyParams NewProp_SphereComponent = { UE4CodeGen_Private::EPropertyClass::Object, "SphereComponent", RF_Public|RF_Transient|RF_MarkAsNative, 0x00200800000a0009, 1, nullptr, STRUCT_OFFSET(AFPSObjectiveActor, SphereComponent), Z_Construct_UClass_USphereComponent_NoRegister, METADATA_PARAMS(NewProp_SphereComponent_MetaData, ARRAY_COUNT(NewProp_SphereComponent_MetaData)) };
#if WITH_METADATA
			static const UE4CodeGen_Private::FMetaDataPairParam NewProp_MeshComponent_MetaData[] = {
				{ "Category", "Components" },
				{ "EditInline", "true" },
				{ "ModuleRelativePath", "Public/FPSObjectiveActor.h" },
			};
#endif
			static const UE4CodeGen_Private::FObjectPropertyParams NewProp_MeshComponent = { UE4CodeGen_Private::EPropertyClass::Object, "MeshComponent", RF_Public|RF_Transient|RF_MarkAsNative, 0x00200800000a0009, 1, nullptr, STRUCT_OFFSET(AFPSObjectiveActor, MeshComponent), Z_Construct_UClass_UStaticMeshComponent_NoRegister, METADATA_PARAMS(NewProp_MeshComponent_MetaData, ARRAY_COUNT(NewProp_MeshComponent_MetaData)) };
			static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[] = {
				(const UE4CodeGen_Private::FPropertyParamsBase*)&NewProp_PickupFX,
				(const UE4CodeGen_Private::FPropertyParamsBase*)&NewProp_SphereComponent,
				(const UE4CodeGen_Private::FPropertyParamsBase*)&NewProp_MeshComponent,
			};
			static const FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
				TCppClassTypeTraits<AFPSObjectiveActor>::IsAbstract,
			};
			static const UE4CodeGen_Private::FClassParams ClassParams = {
				&AFPSObjectiveActor::StaticClass,
				DependentSingletons, ARRAY_COUNT(DependentSingletons),
				0x00900080u,
				nullptr, 0,
				PropPointers, ARRAY_COUNT(PropPointers),
				nullptr,
				&StaticCppClassTypeInfo,
				nullptr, 0,
				METADATA_PARAMS(Class_MetaDataParams, ARRAY_COUNT(Class_MetaDataParams))
			};
			UE4CodeGen_Private::ConstructUClass(OuterClass, ClassParams);
		}
		return OuterClass;
	}
	IMPLEMENT_CLASS(AFPSObjectiveActor, 1852811079);
	static FCompiledInDefer Z_CompiledInDefer_UClass_AFPSObjectiveActor(Z_Construct_UClass_AFPSObjectiveActor, &AFPSObjectiveActor::StaticClass, TEXT("/Script/FPSGame"), TEXT("AFPSObjectiveActor"), false, nullptr, nullptr, nullptr);
	DEFINE_VTABLE_PTR_HELPER_CTOR(AFPSObjectiveActor);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
#ifdef _MSC_VER
#pragma warning (pop)
#endif
