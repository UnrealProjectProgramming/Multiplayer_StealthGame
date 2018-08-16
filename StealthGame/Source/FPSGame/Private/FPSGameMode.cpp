// Copyright 1998-2017 Epic Games, Inc. All Rights Reserved.

#include "FPSGameMode.h"
#include "FPSHUD.h"
#include "FPSCharacter.h"
#include "UObject/ConstructorHelpers.h"
#include "Kismet/GameplayStatics.h"
#include "FPSGameState.h"

AFPSGameMode::AFPSGameMode()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnClassFinder(TEXT("/Game/Blueprints/BP_Player"));
	DefaultPawnClass = PlayerPawnClassFinder.Class;

	// use our custom HUD class
	HUDClass = AFPSHUD::StaticClass();

	// Setting Game State
	GameStateClass = AFPSGameState::StaticClass();
}

void AFPSGameMode::MissionComplete(APawn* InstigatorPawn, bool bMissionSuccess)
{
	if (!InstigatorPawn) { return; }



	TArray<AActor*> FetchedActors;
	UGameplayStatics::GetAllActorsOfClass(this, Spectating, FetchedActors);

	if (FetchedActors.Num() > 0)
	{
		AActor* NewSpectateView = nullptr;
		NewSpectateView = FetchedActors[0];
		for (FConstPlayerControllerIterator it = GetWorld()->GetPlayerControllerIterator(); it; it++)
		{
			APlayerController* PC = it->Get();
			if (PC)
			{
				PC->SetViewTargetWithBlend(NewSpectateView, 0.5f, EViewTargetBlendFunction::VTBlend_Cubic);
			}
		}
	}

	AFPSGameState* GS = GetGameState<AFPSGameState>();
	if (GS)
	{
		GS->MulticastOnMissionCompleted(InstigatorPawn, bMissionSuccess);
	}

	OnMissionCompleted(InstigatorPawn, bMissionSuccess);
}
