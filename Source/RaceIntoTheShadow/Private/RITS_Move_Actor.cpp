#include "RITS_Move_Actor.h"

ARITS_Move_Actor::ARITS_Move_Actor()
{
	PrimaryActorTick.bCanEverTick = true;

	SceneRoot = CreateDefaultSubobject<USceneComponent>(TEXT("SceneRoot"));
	SetRootComponent(SceneRoot);

	StaticMeshComp = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("StaticMesh"));
	StaticMeshComp->SetupAttachment(SceneRoot);

	MoveSpeed = 400.0f;
	MaxRange = 500.0f;
}

void ARITS_Move_Actor::BeginPlay()
{
	Super::BeginPlay();

	StartLocation = GetActorLocation();
	MoveDirection = GetActorForwardVector();
}

void ARITS_Move_Actor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	FVector CurrentLocation = GetActorLocation();
	FVector NewLocation = CurrentLocation + (MoveDirection * MoveSpeed * DeltaTime);

	SetActorLocation(NewLocation);

	Dist = FVector::Dist(StartLocation, NewLocation);

	if (Dist >= MaxRange)
	{
		MoveDirection = -MoveDirection;
	}
	

}

