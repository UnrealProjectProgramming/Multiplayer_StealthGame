// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "FPSAIGuard.generated.h"

class UPawnSensingComponent;

UENUM(BlueprintType)
enum class AIState : uint8
{
	Idle,
	Suspecious,
	Alerted
};

UCLASS()
class FPSGAME_API AFPSAIGuard : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	AFPSAIGuard();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	UFUNCTION()
	void OnPawnSeen(APawn* SeenPawn);

	UFUNCTION()
	void OnNoiseHeard(APawn* HeardInstigator, const FVector& Location, float Volume);

	UFUNCTION()
	void ResetOrientation();

	UFUNCTION(BlueprintImplementableEvent, Category = "AI")
	void OnStateChanged(AIState NewState);


	void SetGuardState(AIState NewState);


protected:

	UPROPERTY(VisibleAnywhere, Category = "Component")
	UPawnSensingComponent* SensingComponent = nullptr;

	UPROPERTY()
	FRotator OriginalRotation;

	UPROPERTY()
	FTimerHandle TimerHandle_ResetOrientation;

	AIState GuardState;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	
};
