// Copyright 1998-2017 Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "ObjectMacros.h"
#include "ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
#ifdef FPSGAME_FPSGameMode_generated_h
#error "FPSGameMode.generated.h already included, missing '#pragma once' in FPSGameMode.h"
#endif
#define FPSGAME_FPSGameMode_generated_h

#define StealthGame_Source_FPSGame_Public_FPSGameMode_h_12_RPC_WRAPPERS
#define StealthGame_Source_FPSGame_Public_FPSGameMode_h_12_RPC_WRAPPERS_NO_PURE_DECLS
#define StealthGame_Source_FPSGame_Public_FPSGameMode_h_12_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesAFPSGameMode(); \
	friend FPSGAME_API class UClass* Z_Construct_UClass_AFPSGameMode(); \
public: \
	DECLARE_CLASS(AFPSGameMode, AGameModeBase, COMPILED_IN_FLAGS(0 | CLASS_Transient), 0, TEXT("/Script/FPSGame"), NO_API) \
	DECLARE_SERIALIZER(AFPSGameMode) \
	enum {IsIntrinsic=COMPILED_IN_INTRINSIC};


#define StealthGame_Source_FPSGame_Public_FPSGameMode_h_12_INCLASS \
private: \
	static void StaticRegisterNativesAFPSGameMode(); \
	friend FPSGAME_API class UClass* Z_Construct_UClass_AFPSGameMode(); \
public: \
	DECLARE_CLASS(AFPSGameMode, AGameModeBase, COMPILED_IN_FLAGS(0 | CLASS_Transient), 0, TEXT("/Script/FPSGame"), NO_API) \
	DECLARE_SERIALIZER(AFPSGameMode) \
	enum {IsIntrinsic=COMPILED_IN_INTRINSIC};


#define StealthGame_Source_FPSGame_Public_FPSGameMode_h_12_STANDARD_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API AFPSGameMode(const FObjectInitializer& ObjectInitializer); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(AFPSGameMode) \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, AFPSGameMode); \
DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(AFPSGameMode); \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API AFPSGameMode(AFPSGameMode&&); \
	NO_API AFPSGameMode(const AFPSGameMode&); \
public:


#define StealthGame_Source_FPSGame_Public_FPSGameMode_h_12_ENHANCED_CONSTRUCTORS \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API AFPSGameMode(AFPSGameMode&&); \
	NO_API AFPSGameMode(const AFPSGameMode&); \
public: \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, AFPSGameMode); \
DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(AFPSGameMode); \
	DEFINE_DEFAULT_CONSTRUCTOR_CALL(AFPSGameMode)


#define StealthGame_Source_FPSGame_Public_FPSGameMode_h_12_PRIVATE_PROPERTY_OFFSET
#define StealthGame_Source_FPSGame_Public_FPSGameMode_h_9_PROLOG
#define StealthGame_Source_FPSGame_Public_FPSGameMode_h_12_GENERATED_BODY_LEGACY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	StealthGame_Source_FPSGame_Public_FPSGameMode_h_12_PRIVATE_PROPERTY_OFFSET \
	StealthGame_Source_FPSGame_Public_FPSGameMode_h_12_RPC_WRAPPERS \
	StealthGame_Source_FPSGame_Public_FPSGameMode_h_12_INCLASS \
	StealthGame_Source_FPSGame_Public_FPSGameMode_h_12_STANDARD_CONSTRUCTORS \
public: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


#define StealthGame_Source_FPSGame_Public_FPSGameMode_h_12_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	StealthGame_Source_FPSGame_Public_FPSGameMode_h_12_PRIVATE_PROPERTY_OFFSET \
	StealthGame_Source_FPSGame_Public_FPSGameMode_h_12_RPC_WRAPPERS_NO_PURE_DECLS \
	StealthGame_Source_FPSGame_Public_FPSGameMode_h_12_INCLASS_NO_PURE_DECLS \
	StealthGame_Source_FPSGame_Public_FPSGameMode_h_12_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID StealthGame_Source_FPSGame_Public_FPSGameMode_h


PRAGMA_ENABLE_DEPRECATION_WARNINGS
