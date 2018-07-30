// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "FPSBlackHole.generated.h"

class USphereComponent;
class UPrimitiveComponent;

UCLASS()
class FPSGAME_API AFPSBlackHole : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AFPSBlackHole();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

protected:
	UPROPERTY(BlueprintReadWrite, VisibleAnywhere, Category = "Components")
	USphereComponent * InnerSphereComponent;
	UPROPERTY(BlueprintReadWrite, VisibleAnywhere, Category = "Components")
	USphereComponent * OuterSphereComponent;
	UPROPERTY(VisibleAnywhere, Category = "Components")
	UStaticMeshComponent * MeshComp;
	UPROPERTY(VisibleAnywhere, Category = "Components")
	USceneComponent* SceneComponent;
public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

private:
	TArray<UPrimitiveComponent*> Boxes;
	
};
