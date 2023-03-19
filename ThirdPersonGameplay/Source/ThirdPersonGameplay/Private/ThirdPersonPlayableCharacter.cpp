// Copyright (c) LASER-Yi


#include "ThirdPersonPlayableCharacter.h"

#include "EnhancedInputComponent.h"
#include "EnhancedInputSubsystems.h"
#include "EnhancedPlayerInput.h"
#include "Camera/CameraComponent.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "GameFramework/SpringArmComponent.h"

AThirdPersonPlayableCharacter::AThirdPersonPlayableCharacter()
{
	bUseControllerRotationPitch = false;
	bUseControllerRotationYaw = false;
	bUseControllerRotationRoll = false;

	GetCharacterMovement()->bOrientRotationToMovement = false; // Character moves in the direction of input...

	SpringArmComponent = CreateDefaultSubobject<USpringArmComponent>(TEXT("Spring Arm"));
	SpringArmComponent->SetupAttachment(RootComponent);
	SpringArmComponent->bUsePawnControlRotation = true;

	CameraComponent = CreateDefaultSubobject<UCameraComponent>(TEXT("Camera"));
	CameraComponent->SetupAttachment(SpringArmComponent, USpringArmComponent::SocketName);
}

void AThirdPersonPlayableCharacter::BeginPlay()
{
	Super::BeginPlay();

	if (const APlayerController* PC = Cast<APlayerController>(GetController()); PC && DefaultInputMapping)
	{
		if (auto* Subsystem = PC->GetLocalPlayer()->GetSubsystem<UEnhancedInputLocalPlayerSubsystem>())
		{
			Subsystem->AddMappingContext(DefaultInputMapping, 10);
		}
	}

	DefaultWalkVelocity = GetCharacterMovement()->MaxWalkSpeed;
}

void AThirdPersonPlayableCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);
	
	UEnhancedInputComponent* EIC = CastChecked<UEnhancedInputComponent>(PlayerInputComponent);

	if (MovementInput)
	{
		EIC->BindAction(MovementInput, ETriggerEvent::Triggered, this, &ThisClass::OnMove);
	}
	else
	{
		UE_LOG(LogInput, Error, TEXT("[%s] Error when binding movement input to the character, input action not found"), *GetNameSafe(this));
	}

	if (LookInput)
	{
		EIC->BindAction(LookInput, ETriggerEvent::Triggered, this, &ThisClass::OnLook);
	}
	else
	{
		UE_LOG(LogInput, Error, TEXT("[%s] Error when binding look input to the character, input action not found"), *GetNameSafe(this));
	}

	if (RunInput)
	{
		EIC->BindAction(RunInput, ETriggerEvent::Started, this, &ThisClass::OnRun, true);
		EIC->BindAction(RunInput, ETriggerEvent::Completed, this, &ThisClass::OnRun, false);
	}
	else
	{
		UE_LOG(LogInput, Warning, TEXT("[%s] Error when binding run input to the character, input action not found"), *GetNameSafe(this));
	}
}

void AThirdPersonPlayableCharacter::OnMove(const FInputActionValue& InputValue)
{
	if (!ensureMsgf(InputValue.GetValueType() == EInputActionValueType::Axis2D, TEXT("MovementInput should use Axis2D input type")))
	{
		return;
	}

	if (Controller == nullptr)
	{
		return;
	}

	const FRotator Rotation = Controller->GetControlRotation();
	const FRotator YawRotation(0, Rotation.Yaw, 0);

	const FVector ForwardDirection = FRotationMatrix(YawRotation).GetUnitAxis(EAxis::X);
	const FVector RightDirection = FRotationMatrix(YawRotation).GetUnitAxis(EAxis::Y);

	// add movement 
	const FVector Value = InputValue.Get<FVector>();
	
	AddMovementInput(ForwardDirection, Value.Y);
	AddMovementInput(RightDirection, Value.X);
}

void AThirdPersonPlayableCharacter::OnLook(const FInputActionValue& InputValue)
{
	if (!ensureMsgf(InputValue.GetValueType() == EInputActionValueType::Axis2D, TEXT("LookInput should use Axis2D input type")))
	{
		return;
	}

	if (Controller == nullptr)
	{
		return;
	}

	const FVector2D Value = InputValue.Get<FVector2D>();

	AddControllerYawInput(Value.X);
	AddControllerPitchInput(Value.Y);
}

void AThirdPersonPlayableCharacter::OnRun(bool bEnabled)
{
	UCharacterMovementComponent* CharacterMovement = GetCharacterMovement();
	check(CharacterMovement);
	
	if (bEnabled)
	{
		CharacterMovement->MaxWalkSpeed = DefaultWalkVelocity * RunSpeedModifier;
	}
	else
	{
		CharacterMovement->MaxWalkSpeed = DefaultWalkVelocity;
	}
}
