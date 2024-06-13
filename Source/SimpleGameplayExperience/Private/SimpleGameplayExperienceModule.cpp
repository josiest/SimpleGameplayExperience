// Copyright Epic Games, Inc. All Rights Reserved.

#include "Modules/ModuleManager.h"
#define LOCTEXT_NAMESPACE "FSimpleGameplayExperienceModule"

class FSimpleGameplayExperienceModule : public IModuleInterface
{
public:

	/** IModuleInterface implementation */
	virtual void StartupModule() override;
	virtual void ShutdownModule() override;
};

void FSimpleGameplayExperienceModule::StartupModule()
{
}

void FSimpleGameplayExperienceModule::ShutdownModule()
{
}

#undef LOCTEXT_NAMESPACE
	
IMPLEMENT_MODULE(FSimpleGameplayExperienceModule, SimpleGameplayExperience)