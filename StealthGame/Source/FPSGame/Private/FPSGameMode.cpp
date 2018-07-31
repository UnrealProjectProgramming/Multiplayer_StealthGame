// Copyright 1998-2017 Epic Games, Inc. All Rights Reserved.

#include "FPSGameMode.h"
#include "FPSHUD.h"
#include "FPSCharacter.h"
#include "UObject/ConstructorHelpers.h"
#include "Kismet/GameplayStatics.h"

AFPSGameMode::AFPSGameMode()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnClassFinder(TEXT("/Game/Blueprints/BP_Player"));
	DefaultPawnClass = PlayerPawnClassFinder.Class;

	// use our custom HUD class
	HUDClass = AFPSHUD::StaticClass();
}

void AFPSGameMode::MissionComplete(APawn* InstigatorPawn)
{
	if (!InstigatorPawn) { return; }

	InstigatorPawn->DisableInput(nullptr);
	OnMissionCompleted(InstigatorPawn);

	APlayerController* MyPlayerController = Cast<APlayerController>(InstigatorPawn->GetController());
	if (!MyPlayerController) { return; }

	TArray<AActor*> FetchedActors;
	UGameplayStatics::GetAllActorsOfClass(this, Spectating, FetchedActors);
	AActor* NewSpectateView = nullptr;

	if (FetchedActors.Num() > 0)
	{
		NewSpectateView = FetchedActors[0];
		MyPlayerController->SetViewTargetWithBlend(NewSpectateView, 0.5f, EViewTargetBlendFunction::VTBlend_Cubic);
	}
	
}
