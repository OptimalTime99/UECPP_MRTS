#include "RITSCharacter.h"

ARITSCharacter::ARITSCharacter()
{
	PrimaryActorTick.bCanEverTick = false;
}

void ARITSCharacter::PostInitializeComponents()
{
	Super::PostInitializeComponents();
}

void ARITSCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);
}

