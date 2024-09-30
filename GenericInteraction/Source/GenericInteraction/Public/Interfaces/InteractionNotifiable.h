// Copyright (c) LASER-Yi

#pragma once

#include "CoreMinimal.h"
#include "UObject/Interface.h"
#include "InteractionNotifiable.generated.h"

class UInteractionViewModel;

UINTERFACE(Blueprintable)
class UInteractionNotifiable : public UInterface
{
	GENERATED_BODY()
};

/**
 * The notification event for interaction system
 */
class GENERICINTERACTION_API IInteractionNotifiable
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintImplementableEvent, Category = "Interaction")
	UInteractionViewModel* GetViewModel() const;
};
