// Fill out your copyright notice in the Description page of Project Settings.

#include "FPSAIGuard.h"

#include "Perception/PawnSensingComponent.h"
#include "DrawDebugHelpers.h"

// Sets default values
AFPSAIGuard::AFPSAIGuard()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	SensingComponent = CreateDefaultSubobject<UPawnSensingComponent>(TEXT("Sensing Component"));

	SensingComponent->OnSeePawn.AddDynamic(this, &AFPSAIGuard::OnPawnSeen);
	SensingComponent->OnHearNoise.AddDynamic(this, &AFPSAIGuard::OnNoiseHeard);
}

void AFPSAIGuard::OnPawnSeen(APawn* SeenPawn)
{
	if (SeenPawn)
	{
		UE_LOG(LogTemp, Warning, TEXT("Seen Component:  %s"), *SeenPawn->GetName());

		DrawDebugSphere(GetWorld(), SeenPawn->GetActorLocation(), 34.0f, 12, FColor::Yellow, false, 10.0f);
	}
}

void AFPSAIGuard::OnNoiseHeard(APawn* HeardInstigator, const FVector& Location, float Volume)
{

	UE_LOG(LogTemp, Warning, TEXT("Hear Component:  %s"), *HeardInstigator->GetName());

	DrawDebugSphere(GetWorld(), Location, 34.0f, 12, FColor::Red, false, 10.0f);


}


// Called when the game starts or when spawned
void AFPSAIGuard::BeginPlay()
{
	Super::BeginPlay();
	
}




// Called every frame
void AFPSAIGuard::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}



