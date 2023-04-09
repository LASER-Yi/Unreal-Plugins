// Copyright (c) LASER-Yi


#include "Queries/ActorQueryBase.h"

void UActorQueryBase::K2_ExecuteQuery_Implementation(TArray<AActor*>& InOutActors) const
{
	NativeExecute(InOutActors);
}
