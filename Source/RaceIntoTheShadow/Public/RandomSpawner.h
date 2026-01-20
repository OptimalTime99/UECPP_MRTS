#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Components/BoxComponent.h"
#include "RandomSpawner.generated.h"

UCLASS()
class RACEINTOTHESHADOW_API ARandomSpawner : public AActor
{
	GENERATED_BODY()
	
public:	
	ARandomSpawner();

protected:
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Spawner")
	UBoxComponent* SpawnVolume;

	UPROPERTY(EditAnywhere, Category = "Spawner")
	TArray<TSubclassOf<AActor>> SpawnableClasses;

	UPROPERTY(EditAnywhere, Category = "Spawner", meta = (ClampMin = "1"))
	int32 SpawnCount = 10;

	UPROPERTY(EditAnywhere, Category = "Spawner")
	int32 MaxSpawnAttempts = 10;

	virtual void BeginPlay() override;

private:
	FVector GetRandomPointInVolume();
	bool IsLocationEmpty(FVector Location, FVector BoxExtent, FRotator Rotation);
};
