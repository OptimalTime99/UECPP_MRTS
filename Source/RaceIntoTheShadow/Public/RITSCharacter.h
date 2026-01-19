#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "RITSCharacter.generated.h"

class USpringArmComponent;
class UCameraComponent;

UCLASS()
class RACEINTOTHESHADOW_API ARITSCharacter : public ACharacter
{
	GENERATED_BODY()

public:
	ARITSCharacter();

protected:
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Camera")
	USpringArmComponent* SpringArmComp;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Camera")
	UCameraComponent* CameraComp;

	virtual void PostInitializeComponents() override;

	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;


};
