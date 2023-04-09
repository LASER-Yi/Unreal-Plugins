// Copyright (c) LASER-Yi


#include "Interactable.h"
#include "Components/InteractionComponent.h"


bool IInteractable::CanInteract_Implementation(const UInteractionComponent* Owner) const
{
	return false;
}

FText IInteractable::GetInteractionText_Implementation() const
{
	PURE_VIRTUAL(IInteractable::GetInteractionText_Implementation, return {};)
}

bool IInteractable::Interact_Implementation(UInteractionComponent* Owner)
{
	PURE_VIRTUAL(IInteractable::Interact_Implementation, return false;)
}


// bool IInteractable::Interactable::Interact_
