#include "RandomSpawner.h"
#include "Kismet/KismetMathLibrary.h"
#include "Engine/World.h"

ARandomSpawner::ARandomSpawner()
{
	PrimaryActorTick.bCanEverTick = false;

	SpawnVolume = CreateDefaultSubobject<UBoxComponent>(TEXT("SpawnVolume"));
	SetRootComponent(SpawnVolume);
	SpawnVolume->SetBoxExtent(FVector(1000.0f, 1000.0f, 100.0f));

}

void ARandomSpawner::BeginPlay()
{
	Super::BeginPlay();

	if (SpawnableClasses.Num() == 0)
	{
		UE_LOG(LogTemp, Warning, TEXT("SpawnableClasses 배열이 비어있습니다!"));
		return;
	}

	int32 SpawnedCount = 0;

	for (int32 i = 0; i < SpawnCount; i++)
	{
		int32 RandomIndex = FMath::RandRange(0, SpawnableClasses.Num() - 1);
		TSubclassOf<AActor> SelectedClass = SpawnableClasses[RandomIndex];

		if (!SelectedClass) continue;

		AActor* CDO = SelectedClass->GetDefaultObject<AActor>();
		if (!CDO) continue;

		FVector Origin, BoxExtent;
		CDO->GetActorBounds(true, Origin, BoxExtent);
		BoxExtent *= 1.1f;

		for (int32 Attempt = 0; Attempt < MaxSpawnAttempts; Attempt++)
		{
			FVector RandomLoc = GetRandomPointInVolume();

			FRotator RandomRot = FRotator(0.0f, FMath::RandRange(0.0f, 360.0f), 0.0f);

			if (IsLocationEmpty(RandomLoc, BoxExtent, RandomRot))
			{
				FActorSpawnParameters SpawnParams;
				SpawnParams.SpawnCollisionHandlingOverride = ESpawnActorCollisionHandlingMethod::AlwaysSpawn;

				GetWorld()->SpawnActor<AActor>(SelectedClass, RandomLoc, RandomRot, SpawnParams);

				SpawnedCount++;
				break;
			}
		}
	}
	
}

FVector ARandomSpawner::GetRandomPointInVolume()
{
	FVector Origin = SpawnVolume->GetComponentLocation();
	FVector BoxExtent = SpawnVolume->GetScaledBoxExtent();
	return UKismetMathLibrary::RandomPointInBoundingBox(Origin, BoxExtent);
}

bool ARandomSpawner::IsLocationEmpty(FVector Location, FVector BoxExtent, FRotator Rotation)
{
	FCollisionQueryParams Params;
	Params.bTraceComplex = false;

	return !GetWorld()->OverlapBlockingTestByChannel(
		Location,
		Rotation.Quaternion(),
		ECC_WorldStatic,
		FCollisionShape::MakeBox(BoxExtent),
		Params
	);
}

