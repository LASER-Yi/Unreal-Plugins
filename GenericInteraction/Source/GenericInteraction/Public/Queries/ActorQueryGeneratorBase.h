// Copyright (c) LASER-Yi

#pragma once

#include "CoreMinimal.h"
#include "ActorQueryBase.h"
#include "ActorQueryGeneratorBase.generated.h"

/**
 * The base class for actor query that adds new actors from the environment
 */
UCLASS(Abstract)
class GENERICINTERACTION_API UActorQueryGeneratorBase : public UActorQueryBase
{
	GENERATED_BODY()
};
