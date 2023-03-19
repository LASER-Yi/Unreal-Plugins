// MIT License, Copyright (c) LASER-Yi

#pragma once

#include "CoreMinimal.h"
#include "Modules/ModuleManager.h"

class FEquipmentCoreModule : public IModuleInterface
{
public:

	/** IModuleInterface implementation */
	virtual void StartupModule() override;
	virtual void ShutdownModule() override;
};

DECLARE_LOG_CATEGORY_EXTERN(LogEquipmentCore, Log, All)