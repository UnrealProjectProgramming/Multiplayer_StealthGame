# Simple Stealth multiplayer game
#### Engine Version 4.21.0
### Where you basically distract the A.I guard to steal the objective and go to extraction zone.

## What I did in this Project
  * Simple A.I Guard State Machine that protects the objective 
  * Game logic ( Taking the objective, going to extraction point, ending the game, or get spotted and lose)
  * Multiplayer ready.
  * Some gameplay mechanics such as ( Blackhole that drains anything around, Launch pad that launches the character)
  
________________________________________________________________________________________________________________________________________

### Simple A.I State Machine consist of Idle, Suspecious, Patrolling, Aletrted.

```cpp
// This is the .h 

class UPawnSensingComponent;

UENUM(BlueprintType)
enum class AIState : uint8
{
	Idle,
	Suspecious,
	Alerted,
	Patroling
};

UCLASS()
class FPSGAME_API AFPSAIGuard : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	AFPSAIGuard();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	UFUNCTION()
	void OnPawnSeen(APawn* SeenPawn);

	UFUNCTION()
	void OnNoiseHeard(APawn* HeardInstigator, const FVector& Location, float Volume);

	UFUNCTION()
	void ResetOrientation();

	UFUNCTION()
	void OnRep_GuardState();

	UFUNCTION(BlueprintImplementableEvent, Category = "AI")
	void OnStateChanged(AIState NewState);

	void SetGuardState(AIState NewState);

	void MoveToNextPatrolPoint();


protected:

	UPROPERTY(VisibleAnywhere, Category = "Component")
	UPawnSensingComponent* SensingComponent = nullptr;

	UPROPERTY()
	FRotator OriginalRotation;

	UPROPERTY()
	FTimerHandle TimerHandle_ResetOrientation;

	UPROPERTY(ReplicatedUsing=OnRep_GuardState)
	AIState GuardState;

	///* Let the guard go on patrol */
	UPROPERTY(EditInstanceOnly, Category = "AI")
	bool bPatrol;
	///* First of two patrol points to patrol between */
	UPROPERTY(EditInstanceOnly, Category = "AI", meta = (EditCondition = "bPatrol"))
	AActor* FirstPatrolPoint;

	///* Second of two patrol points to patrol between */
	UPROPERTY(EditInstanceOnly, Category = "AI", meta = (EditCondition = "bPatrol"))
	AActor* SecondPatrolPoint = nullptr;

	//// The current point the actor is either moving to or standing at
	AActor* CurrentPatrolPoint;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;	
};

```

```cpp
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
```

________________________________________________________________________________________________________________________________________

### Game Logic using C++ and Blueprint Implementable Event
#### This drives the game logic so that when the player gets spotted, he loses and get a simple UI on screen that tells that he lost, opposite happens when he wins.



```cpp
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

	// Blueprint Implementable Event in ue4
	OnMissionCompleted(InstigatorPawn, bMissionSuccess);
}
```
### In this pic we use the on mission complete event from c++ in blueprint to manage the mission complete status whether the player won or lost.

![Alt Text](https://i.imgur.com/AHk8Ejw.png)

________________________________________________________________________________________________________________________________________

### We handle the mission state by using RPCs (Remote Procedure Calls) which basically uses NetMulticast which will apply the bahviour of call from the Server as well as executed on the server and all other connected Clients (Players) to make sure that to all the clinets the game has ended. and since we want this to be for all players, all this must be implemented in the GameState because in GameState as we know  it holds all of our replicated informaton about current game and taht is because we can not put that in GameMode because as we know game mode only Exist on the server, and clinets do NOT actually have a copy of the game mod, that means whenever we want to replicate something we have to put it in a seperate class which is game state.

### Game mode actually defines how the game is being played, it governs the game rules, scoring, what actors are allowed to exist in this game type, and who may enter the game ... etc, it is only instanced on the server and will never exist on the client coz ofc imagine a client being able to change game rules ? :D 

### for the PlayerState, that contains all the persistent infromation of a player and that is because the player controller also does not exist on the other clients it only exist on OUR Machine ( player machine only) and on the server, I believe that is why we need cheat protection as well ;) 

https://docs.unrealengine.com/en-us/Gameplay/Networking/Actors/RPCs

### So here is a code snippit on Using RPC NetMulticast in this game

```cpp
// THIS IS the Header file

UCLASS()
class FPSGAME_API AFPSGameState : public AGameStateBase
{
	GENERATED_BODY()
	
	
public:
  // To ensure that an RPC call is executed on the remote machine, you can specify the Reliable keyword
	UFUNCTION(NetMulticast, Reliable)
	void MulticastOnMissionCompleted(APawn* InestigatorPawn, bool bMissionSuccess);
	
};
```

```cpp
// CPP File
void AFPSGameState::MulticastOnMissionCompleted_Implementation(APawn* InestigatorPawn, bool bMissionSuccess)
{
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
```

________________________________________________________________________________________________________________________________________

### The Gameplay Things (Blackhole that pulls and the launchPad)


#### GIF and code snippit for the blackhole and the launch pad

![Alt Text](https://media.giphy.com/media/dgoGAAfuRAmyE1p4OG/giphy.gif)

![Alt Text](https://media.giphy.com/media/1yMuHuwi4j8zYITzgj/giphy.gif)

```

#### Code snippit for the blackhole

```cpp
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
```
#### Code snippit for the launchPad

```cpp
// Sets default values
AFPSLaunchPad::AFPSLaunchPad()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	BoxComp = CreateDefaultSubobject<UBoxComponent>(TEXT("Box Component"));
	StaticMeshComp = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Mesh Component"));
	RootComponent = StaticMeshComp;
	BoxComp->SetupAttachment(RootComponent);
	BoxComp->OnComponentBeginOverlap.AddDynamic(this, &AFPSLaunchPad::LaunchOverlapedObjects);

	LaunchPitchAngle = 35.5f;
	LaunchStrength = 1500.0f;

}

void AFPSLaunchPad::LaunchOverlapedObjects(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	FRotator LaunchDirection = GetActorRotation();
	LaunchDirection.Pitch += LaunchPitchAngle;
	FVector LaunchVelocity = LaunchDirection.Vector() * LaunchStrength;
	ACharacter* MyCharacter = Cast<ACharacter>(OtherActor);

	if (MyCharacter)
	{
		MyCharacter->LaunchCharacter(LaunchVelocity, true, true);
		//Spawn FX
		UGameplayStatics::SpawnEmitterAtLocation(GetWorld(), ActivateLaunchPadEmitter, GetActorLocation());
	}
	else if (OtherComp && OtherComp->IsSimulatingPhysics())
	{
		OtherComp->AddImpulse(LaunchVelocity, NAME_None, true);
		UGameplayStatics::SpawnEmitterAtLocation(GetWorld(), ActivateLaunchPadEmitter, GetActorLocation());
	}
}

```
________________________________________________________________________________________________________________________________________

### Handle Simple UI
![Alt Text](https://i.imgur.com/ZPdMi4J.png)

![Alt Text](https://i.imgur.com/gzqAZoQ.png)
