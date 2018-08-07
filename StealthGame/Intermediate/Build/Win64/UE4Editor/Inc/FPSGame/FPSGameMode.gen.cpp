// Copyright 1998-2018 Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "FPSGame/Public/FPSGameMode.h"
#ifdef _MSC_VER
#pragma warning (push)
#pragma warning (disable : 4883)
#endif
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeFPSGameMode() {}
// Cross Module References
	FPSGAME_API UClass* Z_Construct_UClass_AFPSGameMode_NoRegister();
	FPSGAME_API UClass* Z_Construct_UClass_AFPSGameMode();
	ENGINE_API UClass* Z_Construct_UClass_AGameModeBase();
	UPackage* Z_Construct_UPackage__Script_FPSGame();
	FPSGAME_API UFunction* Z_Construct_UFunction_AFPSGameMode_MissionComplete();
	ENGINE_API UClass* Z_Construct_UClass_APawn_NoRegister();
	FPSGAME_API UFunction* Z_Construct_UFunction_AFPSGameMode_OnMissionCompleted();
	COREUOBJECT_API UClass* Z_Construct_UClass_UClass();
	ENGINE_API UClass* Z_Construct_UClass_AActor_NoRegister();
// End Cross Module References
	static FName NAME_AFPSGameMode_OnMissionCompleted = FName(TEXT("OnMissionCompleted"));
	void AFPSGameMode::OnMissionCompleted(APawn* InstigatorPawn)
	{
		FPSGameMode_eventOnMissionCompleted_Parms Parms;
		Parms.InstigatorPawn=InstigatorPawn;
		ProcessEvent(FindFunctionChecked(NAME_AFPSGameMode_OnMissionCompleted),&Parms);
	}
	void AFPSGameMode::StaticRegisterNativesAFPSGameMode()
	{
		UClass* Class = AFPSGameMode::StaticClass();
		static const FNameNativePtrPair Funcs[] = {
			{ "MissionComplete", &AFPSGameMode::execMissionComplete },
		};
		FNativeFunctionRegistrar::RegisterFunctions(Class, Funcs, ARRAY_COUNT(Funcs));
	}
	struct Z_Construct_UFunction_AFPSGameMode_MissionComplete_Statics
	{
		struct FPSGameMode_eventMissionComplete_Parms
		{
			APawn* InstigatorPawn;
		};
		static const UE4CodeGen_Private::FObjectPropertyParams NewProp_InstigatorPawn;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UE4CodeGen_Private::FFunctionParams FuncParams;
	};
	const UE4CodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_AFPSGameMode_MissionComplete_Statics::NewProp_InstigatorPawn = { UE4CodeGen_Private::EPropertyClass::Object, "InstigatorPawn", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0010000000000080, 1, nullptr, STRUCT_OFFSET(FPSGameMode_eventMissionComplete_Parms, InstigatorPawn), Z_Construct_UClass_APawn_NoRegister, METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_AFPSGameMode_MissionComplete_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AFPSGameMode_MissionComplete_Statics::NewProp_InstigatorPawn,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_AFPSGameMode_MissionComplete_Statics::Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "Public/FPSGameMode.h" },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UFunction_AFPSGameMode_MissionComplete_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_AFPSGameMode, "MissionComplete", RF_Public|RF_Transient|RF_MarkAsNative, nullptr, (EFunctionFlags)0x00020401, sizeof(FPSGameMode_eventMissionComplete_Parms), Z_Construct_UFunction_AFPSGameMode_MissionComplete_Statics::PropPointers, ARRAY_COUNT(Z_Construct_UFunction_AFPSGameMode_MissionComplete_Statics::PropPointers), 0, 0, METADATA_PARAMS(Z_Construct_UFunction_AFPSGameMode_MissionComplete_Statics::Function_MetaDataParams, ARRAY_COUNT(Z_Construct_UFunction_AFPSGameMode_MissionComplete_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_AFPSGameMode_MissionComplete()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_AFPSGameMode_MissionComplete_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_AFPSGameMode_OnMissionCompleted_Statics
	{
		static const UE4CodeGen_Private::FObjectPropertyParams NewProp_InstigatorPawn;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UE4CodeGen_Private::FFunctionParams FuncParams;
	};
	const UE4CodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_AFPSGameMode_OnMissionCompleted_Statics::NewProp_InstigatorPawn = { UE4CodeGen_Private::EPropertyClass::Object, "InstigatorPawn", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0010000000000080, 1, nullptr, STRUCT_OFFSET(FPSGameMode_eventOnMissionCompleted_Parms, InstigatorPawn), Z_Construct_UClass_APawn_NoRegister, METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_AFPSGameMode_OnMissionCompleted_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AFPSGameMode_OnMissionCompleted_Statics::NewProp_InstigatorPawn,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_AFPSGameMode_OnMissionCompleted_Statics::Function_MetaDataParams[] = {
		{ "Category", "GameMode" },
		{ "ModuleRelativePath", "Public/FPSGameMode.h" },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UFunction_AFPSGameMode_OnMissionCompleted_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_AFPSGameMode, "OnMissionCompleted", RF_Public|RF_Transient|RF_MarkAsNative, nullptr, (EFunctionFlags)0x08020800, sizeof(FPSGameMode_eventOnMissionCompleted_Parms), Z_Construct_UFunction_AFPSGameMode_OnMissionCompleted_Statics::PropPointers, ARRAY_COUNT(Z_Construct_UFunction_AFPSGameMode_OnMissionCompleted_Statics::PropPointers), 0, 0, METADATA_PARAMS(Z_Construct_UFunction_AFPSGameMode_OnMissionCompleted_Statics::Function_MetaDataParams, ARRAY_COUNT(Z_Construct_UFunction_AFPSGameMode_OnMissionCompleted_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_AFPSGameMode_OnMissionCompleted()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_AFPSGameMode_OnMissionCompleted_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	UClass* Z_Construct_UClass_AFPSGameMode_NoRegister()
	{
		return AFPSGameMode::StaticClass();
	}
	struct Z_Construct_UClass_AFPSGameMode_Statics
	{
		static UObject* (*const DependentSingletons[])();
		static const FClassFunctionLinkInfo FuncInfo[];
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_Spectating_MetaData[];
#endif
		static const UE4CodeGen_Private::FClassPropertyParams NewProp_Spectating;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UE4CodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_AFPSGameMode_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_AGameModeBase,
		(UObject* (*)())Z_Construct_UPackage__Script_FPSGame,
	};
	const FClassFunctionLinkInfo Z_Construct_UClass_AFPSGameMode_Statics::FuncInfo[] = {
		{ &Z_Construct_UFunction_AFPSGameMode_MissionComplete, "MissionComplete" }, // 2203951503
		{ &Z_Construct_UFunction_AFPSGameMode_OnMissionCompleted, "OnMissionCompleted" }, // 594001951
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AFPSGameMode_Statics::Class_MetaDataParams[] = {
		{ "HideCategories", "Info Rendering MovementReplication Replication Actor Input Movement Collision Rendering Utilities|Transformation" },
		{ "IncludePath", "FPSGameMode.h" },
		{ "ModuleRelativePath", "Public/FPSGameMode.h" },
		{ "ShowCategories", "Input|MouseInput Input|TouchInput" },
	};
#endif
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AFPSGameMode_Statics::NewProp_Spectating_MetaData[] = {
		{ "Category", "Spectating" },
		{ "ModuleRelativePath", "Public/FPSGameMode.h" },
	};
#endif
	const UE4CodeGen_Private::FClassPropertyParams Z_Construct_UClass_AFPSGameMode_Statics::NewProp_Spectating = { UE4CodeGen_Private::EPropertyClass::Class, "Spectating", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0024080000010001, 1, nullptr, STRUCT_OFFSET(AFPSGameMode, Spectating), Z_Construct_UClass_AActor_NoRegister, Z_Construct_UClass_UClass, METADATA_PARAMS(Z_Construct_UClass_AFPSGameMode_Statics::NewProp_Spectating_MetaData, ARRAY_COUNT(Z_Construct_UClass_AFPSGameMode_Statics::NewProp_Spectating_MetaData)) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_AFPSGameMode_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AFPSGameMode_Statics::NewProp_Spectating,
	};
	const FCppClassTypeInfoStatic Z_Construct_UClass_AFPSGameMode_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<AFPSGameMode>::IsAbstract,
	};
	const UE4CodeGen_Private::FClassParams Z_Construct_UClass_AFPSGameMode_Statics::ClassParams = {
		&AFPSGameMode::StaticClass,
		DependentSingletons, ARRAY_COUNT(DependentSingletons),
		0x008002A8u,
		FuncInfo, ARRAY_COUNT(FuncInfo),
		Z_Construct_UClass_AFPSGameMode_Statics::PropPointers, ARRAY_COUNT(Z_Construct_UClass_AFPSGameMode_Statics::PropPointers),
		nullptr,
		&StaticCppClassTypeInfo,
		nullptr, 0,
		METADATA_PARAMS(Z_Construct_UClass_AFPSGameMode_Statics::Class_MetaDataParams, ARRAY_COUNT(Z_Construct_UClass_AFPSGameMode_Statics::Class_MetaDataParams))
	};
	UClass* Z_Construct_UClass_AFPSGameMode()
	{
		static UClass* OuterClass = nullptr;
		if (!OuterClass)
		{
			UE4CodeGen_Private::ConstructUClass(OuterClass, Z_Construct_UClass_AFPSGameMode_Statics::ClassParams);
		}
		return OuterClass;
	}
	IMPLEMENT_CLASS(AFPSGameMode, 294420128);
	static FCompiledInDefer Z_CompiledInDefer_UClass_AFPSGameMode(Z_Construct_UClass_AFPSGameMode, &AFPSGameMode::StaticClass, TEXT("/Script/FPSGame"), TEXT("AFPSGameMode"), false, nullptr, nullptr, nullptr);
	DEFINE_VTABLE_PTR_HELPER_CTOR(AFPSGameMode);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
#ifdef _MSC_VER
#pragma warning (pop)
#endif
