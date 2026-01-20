#include "TimerFloorActor.h"

ATimerFloorActor::ATimerFloorActor()
{
	PrimaryActorTick.bCanEverTick = false;

	SceneRoot = CreateDefaultSubobject<USceneComponent>(TEXT("SceneRoot"));
	SetRootComponent(SceneRoot);

	StaticMeshComp = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("StaticMesh"));
	StaticMeshComp->SetupAttachment(SceneRoot);
}

void ATimerFloorActor::BeginPlay()
{
	Super::BeginPlay();

	ScheduleStateChange(false);
}

void ATimerFloorActor::EndPlay(const EEndPlayReason::Type EndPlayReason)
{
	Super::EndPlay(EndPlayReason);

	GetWorld()->GetTimerManager().ClearTimer(BlinkTimerHandle);
}

void ATimerFloorActor::ScheduleStateChange(bool bShow)
{
	float WaitTime = bShow ? HiddenDuration : VisibleDuration;

	FTimerManager& TimerManager = GetWorld()->GetTimerManager();

	TWeakObjectPtr<ATimerFloorActor> WeakThis(this);

	TimerManager.SetTimer(BlinkTimerHandle, [WeakThis, bShow]()
		{
			if (ATimerFloorActor* StrongThis = WeakThis.Get())
			{
				StrongThis->SetActorHiddenInGame(!bShow);
				StrongThis->SetActorEnableCollision(bShow);
				StrongThis->ScheduleStateChange(!bShow);
			}
		}, WaitTime, false);
}

