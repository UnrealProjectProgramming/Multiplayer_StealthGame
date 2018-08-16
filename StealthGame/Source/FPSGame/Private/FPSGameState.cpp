// Fill out your copyright notice in the Description page of Project Settings.

#include "FPSGameState.h"

#include "FPSPlayerController.h"



void AFPSGameState::MulticastOnMissionCompleted_Implementation(APawn* InestigatorPawn, bool bMissionSuccess)
{
// 	for (FConstPawnIterator it = GetWorld()->GetPawnIterator(); it; it++)
// 	{
// 		APawn* Pawn = it->Get();
// 		if (Pawn && Pawn->IsLocallyControlled())
// 		{
// 			Pawn->DisableInput(nullptr);
// 		}
// 	}

	for (FConstPlayerControllerIterator it = GetWorld()->GetPlayerControllerIterator(); it; it++)
	{
		AFPSPlayerController* PlayerController = Cast<AFPSPlayerController>(it->Get());
		if (PlayerController && PlayerController->IsLocalController())
		{
			PlayerController->OnMissionComplete(InestigatorPawn, bMissionSuccess);

			// Disable Input
			APawn* MyPawn = PlayerController->GetPawn();
			if (MyPawn)
			{
				MyPawn->DisableInput(PlayerController);
			}
		}
	}
}
