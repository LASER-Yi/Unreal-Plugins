// Copyright (c) LASER-Yi

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "InteractionComponent.generated.h"


class IInteractable;

/**
 * The interaction component used by character to interact something
 */
UCLASS(Blueprintable, BlueprintType, ClassGroup=(Interaction), meta=(BlueprintSpawnableComponent))
class GENERICINTERACTION_API UInteractionComponent : public UActorComponent
{
	GENERATED_BODY()

public:
	UInteractionComponent();

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Interaction")
	bool bShouldCheckEveryFrames = false;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Interaction",
		meta = (EditCondition = "!bShouldCheckEveryFrames", ClampMin = 5, ClampMax = 60))
	int SampleRate;

	UFUNCTION(BlueprintCallable, Category = "Interaction")
	void Interact();

protected:
	UPROPERTY(Transient, BlueprintReadOnly, Category = "Interaction", DisplayName = "Cached Interactable")
	TScriptInterface<IInteractable> CachedInteractableActor;
	
	virtual void BeginPlay() override;

	bool CanInteract(const AActor* Actor) const;
};
