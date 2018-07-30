// Copyright 1998-2017 Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "ObjectMacros.h"
#include "ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
#ifdef FPSGAME_FPSHUD_generated_h
#error "FPSHUD.generated.h already included, missing '#pragma once' in FPSHUD.h"
#endif
#define FPSGAME_FPSHUD_generated_h

#define StealthGame_Source_FPSGame_Public_FPSHUD_h_14_RPC_WRAPPERS
#define StealthGame_Source_FPSGame_Public_FPSHUD_h_14_RPC_WRAPPERS_NO_PURE_DECLS
#define StealthGame_Source_FPSGame_Public_FPSHUD_h_14_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesAFPSHUD(); \
	friend FPSGAME_API class UClass* Z_Construct_UClass_AFPSHUD(); \
public: \
	DECLARE_CLASS(AFPSHUD, AHUD, COMPILED_IN_FLAGS(0 | CLASS_Transient | CLASS_Config), 0, TEXT("/Script/FPSGame"), NO_API) \
	DECLARE_SERIALIZER(AFPSHUD) \
	enum {IsIntrinsic=COMPILED_IN_INTRINSIC};


#define StealthGame_Source_FPSGame_Public_FPSHUD_h_14_INCLASS \
private: \
	static void StaticRegisterNativesAFPSHUD(); \
	friend FPSGAME_API class UClass* Z_Construct_UClass_AFPSHUD(); \
public: \
	DECLARE_CLASS(AFPSHUD, AHUD, COMPILED_IN_FLAGS(0 | CLASS_Transient | CLASS_Config), 0, TEXT("/Script/FPSGame"), NO_API) \
	DECLARE_SERIALIZER(AFPSHUD) \
	enum {IsIntrinsic=COMPILED_IN_INTRINSIC};


#define StealthGame_Source_FPSGame_Public_FPSHUD_h_14_STANDARD_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API AFPSHUD(const FObjectInitializer& ObjectInitializer); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(AFPSHUD) \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, AFPSHUD); \
DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(AFPSHUD); \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API AFPSHUD(AFPSHUD&&); \
	NO_API AFPSHUD(const AFPSHUD&); \
public:


#define StealthGame_Source_FPSGame_Public_FPSHUD_h_14_ENHANCED_CONSTRUCTORS \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API AFPSHUD(AFPSHUD&&); \
	NO_API AFPSHUD(const AFPSHUD&); \
public: \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, AFPSHUD); \
DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(AFPSHUD); \
	DEFINE_DEFAULT_CONSTRUCTOR_CALL(AFPSHUD)


#define StealthGame_Source_FPSGame_Public_FPSHUD_h_14_PRIVATE_PROPERTY_OFFSET
#define StealthGame_Source_FPSGame_Public_FPSHUD_h_11_PROLOG
#define StealthGame_Source_FPSGame_Public_FPSHUD_h_14_GENERATED_BODY_LEGACY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	StealthGame_Source_FPSGame_Public_FPSHUD_h_14_PRIVATE_PROPERTY_OFFSET \
	StealthGame_Source_FPSGame_Public_FPSHUD_h_14_RPC_WRAPPERS \
	StealthGame_Source_FPSGame_Public_FPSHUD_h_14_INCLASS \
	StealthGame_Source_FPSGame_Public_FPSHUD_h_14_STANDARD_CONSTRUCTORS \
public: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


#define StealthGame_Source_FPSGame_Public_FPSHUD_h_14_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	StealthGame_Source_FPSGame_Public_FPSHUD_h_14_PRIVATE_PROPERTY_OFFSET \
	StealthGame_Source_FPSGame_Public_FPSHUD_h_14_RPC_WRAPPERS_NO_PURE_DECLS \
	StealthGame_Source_FPSGame_Public_FPSHUD_h_14_INCLASS_NO_PURE_DECLS \
	StealthGame_Source_FPSGame_Public_FPSHUD_h_14_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID StealthGame_Source_FPSGame_Public_FPSHUD_h


PRAGMA_ENABLE_DEPRECATION_WARNINGS
