// Copyright (c) LASER-Yi


#include "ViewModels/InteractionViewModel.h"

void UInteractionViewModel::SetCanInteract(bool NewValue)
{
	if (NewValue != bCanInteract)
	{
		UE_MVVM_SET_PROPERTY_VALUE(bCanInteract, NewValue);
	}
}

void UInteractionViewModel::SetInteractionText(const FText& NewText)
{
	if (NewText.EqualTo(InteractionText) == false)
	{
		InteractionText = NewText;
		UE_MVVM_BROADCAST_FIELD_VALUE_CHANGED(InteractionText);
	}
}
