#include "LumenGameMode.h"
#include "RITSCharacter.h"

ALumenGameMode::ALumenGameMode()
{
    DefaultPawnClass = ARITSCharacter::StaticClass();
}