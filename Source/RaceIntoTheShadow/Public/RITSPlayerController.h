#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "RITSPlayerController.generated.h"

class UInputMappingContext;
class UInputAction;

UCLASS()
class RACEINTOTHESHADOW_API ARITSPlayerController : public APlayerController
{
	GENERATED_BODY()

public:
    ARITSPlayerController();

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Input")
    UInputMappingContext* InputMappingContext;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Input")
    UInputAction* MoveAction;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Input")
    UInputAction* JumpAction;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Input")
    UInputAction* SprintAction;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Input")
    UInputAction* LookAction;

protected:
    virtual void BeginPlay() override;
};
