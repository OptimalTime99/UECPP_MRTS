#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "RITS_Move_Actor.generated.h"

class USceneComponent;
class UStaticMeshComponent;

UCLASS()
class RACEINTOTHESHADOW_API ARITS_Move_Actor : public AActor
{
	GENERATED_BODY()
	
public:	
	ARITS_Move_Actor();

protected:
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Component")
	USceneComponent* SceneRoot;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Component")
	UStaticMeshComponent* StaticMeshComp;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Move")
	float MoveSpeed;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Move")
	float MaxRange;

	virtual void BeginPlay() override;

	virtual void Tick(float DeltaTime) override;

private:
	float Dist;
	FVector StartLocation;
	FVector MoveDirection;

};
