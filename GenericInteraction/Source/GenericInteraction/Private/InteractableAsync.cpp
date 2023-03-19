// Copyright (c) LASER-Yi


#include "InteractableAsync.h"


bool IInteractableAsync::CanInteract_Implementation() const
{
	return false;
}

bool IInteractableAsync::InteractAsync_Implementation()
{
	PURE_VIRTUAL(IInteractableAsync::InteractAsync_Implementation, return false;)
}
