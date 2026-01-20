#include "LumenGameMode.h"
#include "RITSCharacter.h"
#include "RITSPlayerController.h"

ALumenGameMode::ALumenGameMode()
{
    DefaultPawnClass = ARITSCharacter::StaticClass();

    PlayerControllerClass = ARITSPlayerController::StaticClass();
}

void ALumenGameMode::RequestRespawn(ARITSPlayerController* Controller)
{
	if (!Controller) return;

	APawn* ControlledPawn = Controller->GetPawn();
	if (ControlledPawn)
	{
		ControlledPawn->Destroy();
	}

	Controller->UnPossess();

	FTimerHandle RespawnTimerHandle;
	FTimerDelegate RespawnDelegate;
	RespawnDelegate.BindUObject(this, &ALumenGameMode::OnRespawnTimerElapsed, Controller);

	GetWorldTimerManager().SetTimer(RespawnTimerHandle, RespawnDelegate, 2.0f, false);
}

void ALumenGameMode::OnRespawnTimerElapsed(ARITSPlayerController* Controller)
{
	if (Controller)
	{
		RestartPlayer(Controller);
	}
}
