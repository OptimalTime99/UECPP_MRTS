#include "LumenGameMode.h"
#include "RITSCharacter.h"
#include "RITSPlayerController.h"

ALumenGameMode::ALumenGameMode()
{
    DefaultPawnClass = ARITSCharacter::StaticClass();

    PlayerControllerClass = ARITSPlayerController::StaticClass();
}