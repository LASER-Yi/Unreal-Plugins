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
	UFUNCTION(BlueprintCallable, BlueprintNativeEvent, Category = "Interaction")
	bool CanInteract(const UInteractionComponent* Owner) const;
	virtual bool CanInteract_Implementation(const UInteractionComponent* Owner) const;

	UFUNCTION(BlueprintCallable, BlueprintNativeEvent, Category = "Interaction")
	FText GetInteractionText() const;
	virtual FText GetInteractionText_Implementation() const;

	UFUNCTION(BlueprintCallable, BlueprintNativeEvent, Category = "Interaction")
	bool Interact(UInteractionComponent* Owner);
	virtual bool Interact_Implementation(UInteractionComponent* Owner);
};
