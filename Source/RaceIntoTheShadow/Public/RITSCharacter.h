#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "RITSCharacter.generated.h"

class USpringArmComponent;
class UCameraComponent;
struct FInputActionValue;

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

	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

    // 이동 입력 처리 함수
    UFUNCTION()
    void Move(const FInputActionValue& value);

    // 점프 입력 처리 함수
    UFUNCTION()
    void StartJump(const FInputActionValue& value);
    UFUNCTION()
    void StopJump(const FInputActionValue& value);

    // 달리기 입력 처리 함수
    UFUNCTION()
    void StartSprint(const FInputActionValue& value);
    UFUNCTION()
    void StopSprint(const FInputActionValue& value);

    // 시점 전환 입력 처리 함수
    UFUNCTION()
    void Look(const FInputActionValue& value);

private:
    float NormalSpeed;
    float SprintSpeedMultiplier;
    float SprintSpeed;
};
