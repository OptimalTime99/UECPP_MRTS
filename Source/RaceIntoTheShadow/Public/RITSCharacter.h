#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "RITSCharacter.generated.h"

UCLASS()
class RACEINTOTHESHADOW_API ARITSCharacter : public ACharacter
{
	GENERATED_BODY()

public:
	ARITSCharacter();

protected:
	virtual void PostInitializeComponents() override;

	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;
};
