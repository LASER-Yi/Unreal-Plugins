// Copyright (c) LASER-Yi

#pragma once

#include "CoreMinimal.h"
#include "MVVMViewModelBase.h"
#include "InteractionViewModel.generated.h"

/**
 * The view model of generic interact operation
 */
UCLASS()
class GENERICINTERACTION_API UInteractionViewModel : public UMVVMViewModelBase
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable, Category = "Interaction")
	void SetCanInteract(bool NewValue);

	UFUNCTION(BlueprintCallable, Category = "Interaction")
	void SetInteractionText(const FText& NewText);
	
private:
	UPROPERTY(BlueprintReadOnly, FieldNotify, Category = "Slate", meta = (AllowPrivateAccess = "true"))
	ESlateVisibility Visibility;
	
	UPROPERTY(BlueprintReadOnly, FieldNotify, Setter="SetCanInteract", Category = "Interaction", meta = (AllowPrivateAccess = "true"))
	bool bCanInteract;

	UPROPERTY(BlueprintReadOnly, FieldNotify, Category = "Interaction", meta = (AllowPrivateAccess = "true"))
	FText InteractionText;
};
