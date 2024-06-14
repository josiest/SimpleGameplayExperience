// Copyright 2024 Josie Thompson, MIT License

#pragma once
#include "Engine/DeveloperSettings.h"
#include "SimpleExperienceSettings.generated.h"

class USimpleGameplayExperience;
/**
 * Settings for the Gameplay Experience plugin
 */
UCLASS(Config=Game)
class SIMPLEGAMEPLAYEXPERIENCE_API USimpleExperienceSettings : public UDeveloperSettings {
	GENERATED_BODY()

public:
	UPROPERTY(Config, EditDefaultsOnly, BlueprintReadOnly)
	TSoftObjectPtr<USimpleGameplayExperience> DefaultGameplayExperience;
};
