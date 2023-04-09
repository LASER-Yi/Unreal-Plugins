// Copyright (c) LASER-Yi


#include "Components/InteractionComponent.h"

#include "Interactable.h"


UInteractionComponent::UInteractionComponent()
{
	PrimaryComponentTick.bCanEverTick = false;
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
