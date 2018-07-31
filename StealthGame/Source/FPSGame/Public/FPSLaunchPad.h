// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "FPSLaunchPad.generated.h"

class UBoxComponent;
class UStaticMeshComponent;
class UParticleSystem;

UCLASS()
class FPSGAME_API AFPSLaunchPad : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AFPSLaunchPad();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

protected:

	UPROPERTY(VisibleAnywhere, Category = "Component")
	UBoxComponent* BoxComp = nullptr;

	UPROPERTY(VisibleAnywhere, Category = "Component")
	UStaticMeshComponent* StaticMeshComp = nullptr;

	UPROPERTY(VisibleAnywhere, Category = "Launch")
	float LaunchPitchAngle;

	UPROPERTY(VisibleAnywhere, Category = "Launch")
	float LaunchStrength;

	UPROPERTY(EditDefaultsOnly, Category = "FX")
	UParticleSystem* ActivateLaunchPadEmitter = nullptr;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UFUNCTION()
	void LaunchOverlapedObjects(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);

	
};
