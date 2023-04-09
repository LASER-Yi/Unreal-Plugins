// Copyright (c) LASER-Yi


#include "ActorTypeQuery.h"

void UActorTypeQuery::NativeExecute(TArray<AActor*>& InOutActors) const
{
	Super::NativeExecute(InOutActors);

	for (auto ActorIterator = InOutActors.CreateIterator(); ActorIterator; ++ActorIterator)
	{
		if (CanSelectActor(*ActorIterator) == false)
		{
			ActorIterator.RemoveCurrent();
		}
	}
}

bool UActorTypeQuery::CanSelectActor(const AActor* Actor) const
{
	if (IsValid(Actor) == false)
	{
		return false;
	}
		
	for (const auto& TypeClass : ActorTypes)
	{
		if (Actor->IsA(TypeClass))
		{
			return bInvertCondition == false;
		}
	}

	return false;
}
