// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "FPSExtractionZone.generated.h"

class UBoxComponent;
class UDecalComponent;

UCLASS()
class FPSGAME_API AFPSExtractionZone : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AFPSExtractionZone();

protected:
	
	UPROPERTY(VisibleAnywhere, Category = "Components")
	UBoxComponent* OverlapComp = nullptr;
	
	UPROPERTY(VisibleAnywhere, Category = "Components")
	UDecalComponent* DecalComp = nullptr;

	UPROPERTY(EditDefaultsOnly, Category = "Sounds")
	USoundBase* OverlapSound = nullptr;

protected:
	UFUNCTION()
	void HandleOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);
};
