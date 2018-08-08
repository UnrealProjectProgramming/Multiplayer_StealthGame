// Fill out your copyright notice in the Description page of Project Settings.

#include "FPSExtractionZone.h"

#include "Components/BoxComponent.h"
#include "Components/DecalComponent.h"
#include "FPSCharacter.h"
#include "FPSGameMode.h"
#include "GameFramework/Actor.h"
#include "Kismet/GameplayStatics.h"


// Sets default values
AFPSExtractionZone::AFPSExtractionZone()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;

	OverlapComp = CreateDefaultSubobject<UBoxComponent>(TEXT("Overlap Component"));
	OverlapComp->SetCollisionEnabled(ECollisionEnabled::QueryOnly);
	OverlapComp->SetCollisionResponseToChannels(ECR_Ignore);
	OverlapComp->SetCollisionResponseToChannel(ECC_Pawn, ECR_Overlap);
	OverlapComp->SetBoxExtent(FVector(200));
	RootComponent = OverlapComp;

	// Bind Event
	OverlapComp->OnComponentBeginOverlap.AddDynamic(this, &AFPSExtractionZone::HandleOverlap);

	DecalComp = CreateDefaultSubobject<UDecalComponent>(TEXT("Decal Component"));
	DecalComp->DecalSize = FVector(200.0f);
	DecalComp->SetupAttachment(RootComponent);
}

void AFPSExtractionZone::HandleOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	UE_LOG(LogTemp, Warning, TEXT("Overlaping with extraction zone"));
	AFPSCharacter* MyPawn = Cast<AFPSCharacter>(OtherActor);
	if (!MyPawn) { return; }

	AFPSGameMode* MyGameMode = Cast<AFPSGameMode>(GetWorld()->GetAuthGameMode());
	if (!MyGameMode) { return; }

	if (MyPawn->bIsCarryingObjective)
	{
		MyGameMode->MissionComplete(MyPawn, true);
	}
	else
	{
		UGameplayStatics::PlaySound2D(this, OverlapSound);
	}



}


