// Copyright (c) LASER-Yi

#pragma once

#include "CoreMinimal.h"
#include "Queries/ActorQueryBase.h"
#include "ActorTypeQuery.generated.h"

/**
 * Query actors by types
 */
UCLASS()
class GENERICINTERACTION_API UActorTypeQuery final : public UActorQueryBase
{
	GENERATED_BODY()

	virtual void NativeExecute(TArray<AActor*>& InOutActors) const override;

private:
	UPROPERTY(EditInstanceOnly, Category = "Interaction|Query", meta = (AllowPrivateAccess="true"))
	TArray<TSubclassOf<AActor>> ActorTypes;

	UPROPERTY(EditInstanceOnly, Category = "Interaction|Query", meta = (AllowPrivateAccess="true"))
	bool bInvertCondition = false;

private:
	bool CanSelectActor(const AActor* Actor) const;
};
