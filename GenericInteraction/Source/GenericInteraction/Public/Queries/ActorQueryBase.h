// Copyright (c) LASER-Yi

#pragma once

#include "CoreMinimal.h"
#include "UObject/Object.h"
#include "ActorQueryBase.generated.h"

/**
 * The base class of actor query. Used by interaction system to generate candidates
 */
UCLASS(Abstract, Blueprintable, EditInlineNew)
class GENERICINTERACTION_API UActorQueryBase : public UObject
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintNativeEvent, DisplayName = "Execute Query")
	void K2_ExecuteQuery(TArray<AActor*>& InOutActors) const;

protected:
	virtual void NativeExecute(TArray<AActor*>& InOutActors) const PURE_VIRTUAL(UActorQueryBase::NativeExecute);
};
