// MIT License, Copyright (c) LASER-Yi

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "EquipmentComponent.generated.h"


class UEquipmentDefinition;
class UEquipmentInstance;

USTRUCT(BlueprintType)
struct FAppliedEquipment
{
	GENERATED_BODY()

	UPROPERTY(BlueprintReadOnly)
	TSubclassOf<UEquipmentDefinition> Definition;

	UPROPERTY(BlueprintReadOnly)
	TObjectPtr<UEquipmentInstance> Instance;
	
};

/*
 * The manager class for the equipment core, should be attached to the pawn (or character)
 */
UCLASS(Blueprintable, BlueprintType, ClassGroup=(Gameplay), meta=(BlueprintSpawnableComponent))
class EQUIPMENTCORE_API UEquipmentComponent : public UActorComponent
{
	GENERATED_BODY()

public:
	UEquipmentComponent(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get());

	static UEquipmentComponent* GetEquipmentComponent(const AActor* InActor);

	UFUNCTION(BlueprintCallable, Category="Equipment")
	void EquipItem(const TSubclassOf<UEquipmentDefinition> Definition);

	UFUNCTION(BlueprintCallable, Category="Equipment")
	void UnequipItem(UEquipmentInstance* Instance);

protected:
	UPROPERTY(BlueprintReadOnly)
	TArray<FAppliedEquipment> Equipments;
};
