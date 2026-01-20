#include "RITS_Rotate_Actor.h"

ARITS_Rotate_Actor::ARITS_Rotate_Actor()
{
	PrimaryActorTick.bCanEverTick = true;

	SceneRoot = CreateDefaultSubobject<USceneComponent>(TEXT("SceneRoot"));
	SetRootComponent(SceneRoot);

	StaticMeshComp = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("StaticMesh"));
	StaticMeshComp->SetupAttachment(SceneRoot);
}

void ARITS_Rotate_Actor::BeginPlay()
{
	Super::BeginPlay();
	
}

void ARITS_Rotate_Actor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	float RotateValue = RotationSpeed * DeltaTime;

	if (bReverseRotation)
	{
		RotateValue *= -1.0f;
	}

	FRotator NewRotation = FRotator(0.0f, 0.0f, RotateValue);

	AddActorLocalRotation(NewRotation);
}

