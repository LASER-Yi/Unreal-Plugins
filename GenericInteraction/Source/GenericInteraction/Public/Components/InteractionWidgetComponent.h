// Copyright (c) LASER-Yi

#pragma once

#include "CoreMinimal.h"
#include "Components/WidgetComponent.h"
#include "InteractionWidgetComponent.generated.h"


class UInteractionWidgetBase;
class UInteractionViewModel;

UCLASS(Blueprintable, BlueprintType, ClassGroup=(Interaction), meta=(BlueprintSpawnableComponent))
class GENERICINTERACTION_API UInteractionWidgetComponent : public UWidgetComponent
{
	GENERATED_BODY()

public:
	UPROPERTY(BlueprintReadOnly, Category = "Interaction|Widget")
	TObjectPtr<UInteractionViewModel> InteractionViewModel;

protected:
	virtual void BeginPlay() override;
};
