#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "RITSPlayerController.h"
#include "LumenGameMode.generated.h"

UCLASS()
class RACEINTOTHESHADOW_API ALumenGameMode : public AGameModeBase
{
	GENERATED_BODY()

public:
	ALumenGameMode();

	void RequestRespawn(ARITSPlayerController* Controller);

	void OnRespawnTimerElapsed(ARITSPlayerController* Controller);
	
};
