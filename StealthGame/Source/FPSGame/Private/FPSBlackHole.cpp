// Fill out your copyright notice in the Description page of Project Settings.

#include "FPSBlackHole.h"

#include "Components/SphereComponent.h"
#include "Engine/StaticMeshActor.h"
#include "Components/StaticMeshComponent.h"

// Sets default values
AFPSBlackHole::AFPSBlackHole()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	SceneComponent = CreateDefaultSubobject<USceneComponent>(TEXT("SceneComponent"));
	RootComponent = SceneComponent;
	MeshComp = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("MeshComp"));
	MeshComp->SetCollisionEnabled(ECollisionEnabled::NoCollision);

	InnerSphereComponent = CreateDefaultSubobject<USphereComponent>(TEXT("InnerSphereComp"));
	InnerSphereComponent->SetSphereRadius(100);

	// Bind to Event
	OuterSphereComponent = CreateDefaultSubobject<USphereComponent>(TEXT("OuterSphereComp"));
	OuterSphereComponent->SetSphereRadius(3000);

	// Setting Up Attachment
	MeshComp->SetupAttachment(SceneComponent);
	InnerSphereComponent->SetupAttachment(SceneComponent);
	OuterSphereComponent->SetupAttachment(SceneComponent);
}




// Called when the game starts or when spawned
void AFPSBlackHole::BeginPlay()
{
	Super::BeginPlay();
}


// Called every frame
void AFPSBlackHole::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);


	OuterSphereComponent->GetOverlappingComponents(Boxes);
	for (UPrimitiveComponent* Box : Boxes)
	{
		Box->AddRadialForce(GetActorLocation(), OuterSphereComponent->GetScaledSphereRadius(), -2000.0f, ERadialImpulseFalloff::RIF_Constant, true);
	}

}

