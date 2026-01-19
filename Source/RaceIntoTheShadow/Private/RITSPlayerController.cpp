#include "RITSPlayerController.h"
#include "EnhancedInputSubsystems.h"

ARITSPlayerController::ARITSPlayerController() : 
    InputMappingContext(nullptr),
    MoveAction(nullptr),
    JumpAction(nullptr),
    SprintAction(nullptr),
    LookAction(nullptr) {}


void ARITSPlayerController::BeginPlay()
{
    Super::BeginPlay();

    if (ULocalPlayer* LocalPlayer = GetLocalPlayer())
    {
        if (UEnhancedInputLocalPlayerSubsystem* Subsystem =
            LocalPlayer->GetSubsystem<UEnhancedInputLocalPlayerSubsystem>())
        {
            if (InputMappingContext)
            {
                Subsystem->AddMappingContext(InputMappingContext, 0);

            }
        }
    }
}