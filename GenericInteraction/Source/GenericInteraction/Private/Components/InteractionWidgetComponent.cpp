// Copyright (c) LASER-Yi


#include "Components/InteractionWidgetComponent.h"

#include "Interfaces/InteractionNotifiable.h"
#include "ViewModels/InteractionViewModel.h"


void UInteractionWidgetComponent::BeginPlay()
{
	Super::BeginPlay();

	if (const UUserWidget* UserWidget = GetWidget(); UserWidget && UserWidget->Implements<UInteractionNotifiable>())
	{
		InteractionViewModel = IInteractionNotifiable::Execute_GetViewModel(UserWidget);
	}

	if (InteractionViewModel)
	{
		InteractionViewModel->SetInteractionText(FText::FromString("[Interaction Test]"));
	}
}
