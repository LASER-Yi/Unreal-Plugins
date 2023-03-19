// Copyright (c) LASER-Yi

#pragma once

#include "CoreMinimal.h"
#include "UObject/Interface.h"
#include "Interactable.generated.h"

UINTERFACE(BlueprintType, Blueprintable)
class UInteractable : public UInterface
{
	GENERATED_BODY()
};

/**
 * Generic interface for all interactable objects
 */
class GENERICINTERACTION_API IInteractable
{
	GENERATED_BODY()

public:

	UFUNCTION(BlueprintCallable, BlueprintPure, BlueprintNativeEvent, Category = "Interaction")
	bool CanInteract() const;
	virtual bool CanInteract_Implementation() const;

	UFUNCTION(BlueprintCallable, BlueprintNativeEvent, Category = "Interaction")
	bool Interact();
	virtual bool Interact_Implementation();
};
