// Copyright 1998-2018 Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "ObjectMacros.h"
#include "ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
#ifdef FPSGAME_FPSObjectiveActor_generated_h
#error "FPSObjectiveActor.generated.h already included, missing '#pragma once' in FPSObjectiveActor.h"
#endif
#define FPSGAME_FPSObjectiveActor_generated_h

#define StealthGame_Source_FPSGame_Public_FPSObjectiveActor_h_12_RPC_WRAPPERS
#define StealthGame_Source_FPSGame_Public_FPSObjectiveActor_h_12_RPC_WRAPPERS_NO_PURE_DECLS
#define StealthGame_Source_FPSGame_Public_FPSObjectiveActor_h_12_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesAFPSObjectiveActor(); \
	friend FPSGAME_API class UClass* Z_Construct_UClass_AFPSObjectiveActor(); \
public: \
	DECLARE_CLASS(AFPSObjectiveActor, AActor, COMPILED_IN_FLAGS(0), 0, TEXT("/Script/FPSGame"), NO_API) \
	DECLARE_SERIALIZER(AFPSObjectiveActor) \
	enum {IsIntrinsic=COMPILED_IN_INTRINSIC};


#define StealthGame_Source_FPSGame_Public_FPSObjectiveActor_h_12_INCLASS \
private: \
	static void StaticRegisterNativesAFPSObjectiveActor(); \
	friend FPSGAME_API class UClass* Z_Construct_UClass_AFPSObjectiveActor(); \
public: \
	DECLARE_CLASS(AFPSObjectiveActor, AActor, COMPILED_IN_FLAGS(0), 0, TEXT("/Script/FPSGame"), NO_API) \
	DECLARE_SERIALIZER(AFPSObjectiveActor) \
	enum {IsIntrinsic=COMPILED_IN_INTRINSIC};


#define StealthGame_Source_FPSGame_Public_FPSObjectiveActor_h_12_STANDARD_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API AFPSObjectiveActor(const FObjectInitializer& ObjectInitializer); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(AFPSObjectiveActor) \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, AFPSObjectiveActor); \
DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(AFPSObjectiveActor); \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API AFPSObjectiveActor(AFPSObjectiveActor&&); \
	NO_API AFPSObjectiveActor(const AFPSObjectiveActor&); \
public:


#define StealthGame_Source_FPSGame_Public_FPSObjectiveActor_h_12_ENHANCED_CONSTRUCTORS \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API AFPSObjectiveActor(AFPSObjectiveActor&&); \
	NO_API AFPSObjectiveActor(const AFPSObjectiveActor&); \
public: \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, AFPSObjectiveActor); \
DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(AFPSObjectiveActor); \
	DEFINE_DEFAULT_CONSTRUCTOR_CALL(AFPSObjectiveActor)


#define StealthGame_Source_FPSGame_Public_FPSObjectiveActor_h_12_PRIVATE_PROPERTY_OFFSET \
	FORCEINLINE static uint32 __PPO__MeshComponent() { return STRUCT_OFFSET(AFPSObjectiveActor, MeshComponent); } \
	FORCEINLINE static uint32 __PPO__SphereComponent() { return STRUCT_OFFSET(AFPSObjectiveActor, SphereComponent); } \
	FORCEINLINE static uint32 __PPO__PickupFX() { return STRUCT_OFFSET(AFPSObjectiveActor, PickupFX); }


#define StealthGame_Source_FPSGame_Public_FPSObjectiveActor_h_9_PROLOG
#define StealthGame_Source_FPSGame_Public_FPSObjectiveActor_h_12_GENERATED_BODY_LEGACY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	StealthGame_Source_FPSGame_Public_FPSObjectiveActor_h_12_PRIVATE_PROPERTY_OFFSET \
	StealthGame_Source_FPSGame_Public_FPSObjectiveActor_h_12_RPC_WRAPPERS \
	StealthGame_Source_FPSGame_Public_FPSObjectiveActor_h_12_INCLASS \
	StealthGame_Source_FPSGame_Public_FPSObjectiveActor_h_12_STANDARD_CONSTRUCTORS \
public: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


#define StealthGame_Source_FPSGame_Public_FPSObjectiveActor_h_12_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	StealthGame_Source_FPSGame_Public_FPSObjectiveActor_h_12_PRIVATE_PROPERTY_OFFSET \
	StealthGame_Source_FPSGame_Public_FPSObjectiveActor_h_12_RPC_WRAPPERS_NO_PURE_DECLS \
	StealthGame_Source_FPSGame_Public_FPSObjectiveActor_h_12_INCLASS_NO_PURE_DECLS \
	StealthGame_Source_FPSGame_Public_FPSObjectiveActor_h_12_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID StealthGame_Source_FPSGame_Public_FPSObjectiveActor_h


PRAGMA_ENABLE_DEPRECATION_WARNINGS
