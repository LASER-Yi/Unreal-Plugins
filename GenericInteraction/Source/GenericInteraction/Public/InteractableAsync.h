// Copyright (c) LASER-Yi

#pragma once

#include "CoreMinimal.h"
#include "UObject/Interface.h"
#include "InteractableAsync.generated.h"

UINTERFACE()
class UInteractableAsync : public UInterface
{
	GENERATED_BODY()
};

/**
 * Generic interface for all async Interactable objects
 */
class GENERICINTERACTION_API IInteractableAsync
{
	GENERATED_BODY()

	DECLARE_DYNAMIC_DELEGATE_OneParam(FOnInteractionEnded, UObject*, Object);

public:
	UFUNCTION(BlueprintCallable, BlueprintPure, BlueprintNativeEvent, Category = "Interaction")
	bool CanInteract() const;
	virtual bool CanInteract_Implementation() const;

	UFUNCTION(BlueprintCallable, BlueprintNativeEvent, Category = "Interaction")
	bool InteractAsync();
	virtual bool InteractAsync_Implementation();
};
