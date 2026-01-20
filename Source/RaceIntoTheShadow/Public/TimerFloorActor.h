#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "TimerFloorActor.generated.h"

class USceneComponent;
class UStaticMeshComponent;

UCLASS()
class RACEINTOTHESHADOW_API ATimerFloorActor : public AActor
{
	GENERATED_BODY()
	
public:	
	ATimerFloorActor();

protected:
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Component")
	USceneComponent* SceneRoot;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Component")
	UStaticMeshComponent* StaticMeshComp;

	virtual void BeginPlay() override;
	virtual void EndPlay(const EEndPlayReason::Type EndPlayReason) override;

private:
	UPROPERTY(EditAnywhere, Category = "Blinking")
	float VisibleDuration = 3.0f;

	UPROPERTY(EditAnywhere, Category = "Blinking")
	float HiddenDuration = 2.0f;

	FTimerHandle BlinkTimerHandle;

	void ScheduleStateChange(bool bShow);

};
