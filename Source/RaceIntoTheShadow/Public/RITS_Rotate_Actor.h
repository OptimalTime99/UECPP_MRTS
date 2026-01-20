#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "RITS_Rotate_Actor.generated.h"

class USceneComponent;
class UStaticMeshComponent;

UCLASS()
class RACEINTOTHESHADOW_API ARITS_Rotate_Actor : public AActor
{
	GENERATED_BODY()
	
public:	
	ARITS_Rotate_Actor();

protected:
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Component")
	USceneComponent* SceneRoot;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Component")
	UStaticMeshComponent* StaticMeshComp;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Rotation")
	float RotationSpeed = 60.0f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Rotation")
	bool bReverseRotation = false;

	virtual void BeginPlay() override;

	virtual void Tick(float DeltaTime) override;


public:	
	

};
