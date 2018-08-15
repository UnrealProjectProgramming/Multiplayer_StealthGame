// Fill out your copyright notice in the Description page of Project Settings.

#include "FPSAIGuard.h"

#include "Perception/PawnSensingComponent.h"
#include "DrawDebugHelpers.h"
#include "FPSGameMode.h"
#include "AIModule/Classes/Blueprint/AIBlueprintHelperLibrary.h"
#include "Net/UnrealNetwork.h"


// Sets default values
AFPSAIGuard::AFPSAIGuard()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	SensingComponent = CreateDefaultSubobject<UPawnSensingComponent>(TEXT("Sensing Component"));

	SensingComponent->OnSeePawn.AddDynamic(this, &AFPSAIGuard::OnPawnSeen);
	SensingComponent->OnHearNoise.AddDynamic(this, &AFPSAIGuard::OnNoiseHeard);

	GuardState = AIState::Patroling;
}

void AFPSAIGuard::MoveToNextPatrolPoint()
{
	if (CurrentPatrolPoint == nullptr || CurrentPatrolPoint == SecondPatrolPoint )
	{
		CurrentPatrolPoint = FirstPatrolPoint;
	}
	else
	{
		CurrentPatrolPoint = SecondPatrolPoint;
	}
	UAIBlueprintHelperLibrary::SimpleMoveToActor(GetController(), CurrentPatrolPoint);
}

// Called when the game starts or when spawned
void AFPSAIGuard::BeginPlay()
{
	Super::BeginPlay();

	OriginalRotation = GetActorRotation();

	if (bPatrol)
	{
		MoveToNextPatrolPoint();
	}
}

void AFPSAIGuard::OnPawnSeen(APawn* SeenPawn)
{
	if (!SeenPawn) { return; }
	AFPSGameMode* MyGameMode = Cast<AFPSGameMode>(GetWorld()->GetAuthGameMode());
	if (!MyGameMode) { return; }

	MyGameMode->MissionComplete(SeenPawn, false);

	SetGuardState(AIState::Alerted);

	AController* MyController = GetController();
	if (MyController)
	{
		MyController->StopMovement();
	}
}

void AFPSAIGuard::OnNoiseHeard(APawn* HeardInstigator, const FVector& Location, float Volume)
{
	if (GuardState == AIState::Alerted)
	{
		return;
	}

	UE_LOG(LogTemp, Warning, TEXT("Hear Component:  %s"), *HeardInstigator->GetName());
	DrawDebugSphere(GetWorld(), Location, 34.0f, 12, FColor::Red, false, 10.0f);

	FVector Direction = Location - GetActorLocation();
	Direction.Normalize();
	FRotator NewLookAt = FRotationMatrix::MakeFromX(Direction).Rotator();
	NewLookAt.Pitch = 0.0f;
	NewLookAt.Roll = 0.0f;
	SetActorRotation(NewLookAt);

	GetWorldTimerManager().ClearTimer(TimerHandle_ResetOrientation);
	GetWorldTimerManager().SetTimer(TimerHandle_ResetOrientation, this, &AFPSAIGuard::ResetOrientation, 3.0f);

	SetGuardState(AIState::Suspecious);

	AController* MyController = GetController();
	if (MyController)
	{
		MyController->StopMovement();
	}
}



void AFPSAIGuard::ResetOrientation()
{
	SetActorRotation(OriginalRotation);
	SetGuardState(AIState::Patroling);

	if (bPatrol)
	{
		MoveToNextPatrolPoint();
	}
}

void AFPSAIGuard::OnRep_GuardState()
{
	OnStateChanged(GuardState);
}

void AFPSAIGuard::GetLifetimeReplicatedProps(TArray< FLifetimeProperty > & OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);

	DOREPLIFETIME(AFPSAIGuard, GuardState);
}


void AFPSAIGuard::SetGuardState(AIState NewState)
{
	if (GuardState != NewState)
	{
		GuardState = NewState;
	}
	OnRep_GuardState();
}


// Called every frame
void AFPSAIGuard::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	if (CurrentPatrolPoint)
	{
		FVector DeltaLocation = GetActorLocation() - CurrentPatrolPoint->GetActorLocation();
		float DistanceToGoal = DeltaLocation.Size();

		if (DistanceToGoal < 200)
		{
			MoveToNextPatrolPoint();
		}
	}

}



