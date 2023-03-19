// MIT License, Copyright (c) LASER-Yi


#include "Components/EquipmentComponent.h"

#include "Equipments/EquipmentInstance.h"


UEquipmentComponent::UEquipmentComponent(const FObjectInitializer& ObjectInitializer): Super()
{
	PrimaryComponentTick.bCanEverTick = false;

	SetIsReplicatedByDefault(true);
}

UEquipmentComponent* UEquipmentComponent::GetEquipmentComponent(const AActor* InActor)
{
	if (InActor)
	{
		return InActor->FindComponentByClass<UEquipmentComponent>();
	}

	return nullptr;
}

void UEquipmentComponent::EquipItem(const TSubclassOf<UEquipmentDefinition> Definition)
{
}

void UEquipmentComponent::UnequipItem(UEquipmentInstance* Instance)
{
	for (auto Iter = Equipments.CreateIterator(); Iter; ++Iter)
	{
		const FAppliedEquipment& EquippedItem = *Iter;
		if (EquippedItem.Instance == Instance)
		{
			EquippedItem.Instance->OnUnequipped();
			
			Iter.RemoveCurrent();
		}
	}
}
