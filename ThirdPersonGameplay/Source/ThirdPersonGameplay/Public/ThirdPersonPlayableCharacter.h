// Copyright (c) LASER-Yi

#pragma once

#include "CoreMinimal.h"
#include "ModularCharacter.h"
#include "InputActionValue.h"
#include "ThirdPersonPlayableCharacter.generated.h"

class UCameraComponent;
class USpringArmComponent;
class UInputAction;
class UInputMappingContext;

/**
 * Modular Third-Person Playable Character
 */
UCLASS(Blueprintable, BlueprintType, ClassGroup = (Character))
class THIRDPERSONGAMEPLAY_API AThirdPersonPlayableCharacter : public AModularCharacter
{
	GENERATED_BODY()

	AThirdPersonPlayableCharacter();

public:
	UPROPERTY(EditDefaultsOnly, Category = "Playable|Input")
	TObjectPtr<UInputMappingContext> DefaultInputMapping;

	UPROPERTY(EditDefaultsOnly, Category = "Playable|Input")
	TObjectPtr<UInputAction> MovementInput;

	UPROPERTY(EditDefaultsOnly, Category = "Playable|Input")
	TObjectPtr<UInputAction> LookInput;

	UPROPERTY(EditDefaultsOnly, Category = "Playable|Input")
	TObjectPtr<UInputAction> RunInput;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly)
	TObjectPtr<USpringArmComponent> SpringArmComponent;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly)
	TObjectPtr<UCameraComponent> CameraComponent;

public:
	UPROPERTY(EditDefaultsOnly, Category = "Movement", meta = (ForceUnits = "x", ClampMin = 1.0f, ClampMax = 4.0f))
	float RunSpeedModifier = 1.2f;

protected:
	// Will be read from MovementComponent
	UPROPERTY(Transient)
	float DefaultWalkVelocity;

	virtual void BeginPlay() override;

	virtual void SetupPlayerInputComponent(UInputComponent* PlayerInputComponent) override;

	virtual void OnMove(const FInputActionValue& InputValue);

	virtual void OnLook(const FInputActionValue& InputValue);

	virtual void OnRun(bool bEnabled);
};
