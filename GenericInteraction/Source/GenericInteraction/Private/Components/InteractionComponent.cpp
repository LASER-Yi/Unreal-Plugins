// Copyright (c) LASER-Yi


#include "Components/InteractionComponent.h"

#include "Interfaces/Interactable.h"


UInteractionComponent::UInteractionComponent()
{
	PrimaryComponentTick.bCanEverTick = false;
}


void UInteractionComponent::Interact()
{
	if (CachedInteractableActor)
	{
		CachedInteractableActor->Interact(this);
	}
}

void UInteractionComponent::BeginPlay()
{
	Super::BeginPlay();
}

bool UInteractionComponent::CanInteract(const AActor* Actor) const
{
	if (Actor->Implements<UInteractable>() == false)
	{
		return false;
	}

	return IInteractable::Execute_CanInteract(Actor, this);
}
