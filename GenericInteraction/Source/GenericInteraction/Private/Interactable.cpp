// Copyright (c) LASER-Yi


#include "Interactable.h"


bool IInteractable::CanInteract_Implementation() const
{
	return false;
}

bool IInteractable::Interact_Implementation()
{
	PURE_VIRTUAL(IInteractable::Interact_Implementation, return false;)
}


// bool IInteractable::Interactable::Interact_
