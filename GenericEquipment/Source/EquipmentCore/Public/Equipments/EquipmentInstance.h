// MIT License, Copyright (c) LASER-Yi

#pragma once

#include "CoreMinimal.h"
#include "UObject/Object.h"
#include "EquipmentInstance.generated.h"

/**
 * The instanced equipment object
 */
UCLASS(Blueprintable, BlueprintType)
class EQUIPMENTCORE_API UEquipmentInstance : public UObject
{
	GENERATED_BODY()

public:
	friend class UEquipmentComponent;

protected:

	virtual void OnEquipped();
	virtual void OnUnequipped();

	UFUNCTION(BlueprintImplementableEvent, Category="Equipment")
	void K2_OnEquipped();

	UFUNCTION(BlueprintImplementableEvent, Category="Equipment")
	void K2_OnUnequipped();
};
