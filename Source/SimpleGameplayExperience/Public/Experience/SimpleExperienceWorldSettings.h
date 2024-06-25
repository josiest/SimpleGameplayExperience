// Copyright 2024 Josie Thompson, MIT License

#pragma once
#include "GameFramework/WorldSettings.h"
#include "SimpleExperienceWorldSettings.generated.h"

class USimpleGameplayExperience;
/**
 * ASimpleExperienceWorldSettings
 *  World settings for the simple gameplay experience plugin.
 */
UCLASS()
class SIMPLEGAMEPLAYEXPERIENCE_API ASimpleExperienceWorldSettings : public AWorldSettings {
    GENERATED_BODY()
public:
    ASimpleExperienceWorldSettings(const FObjectInitializer& ObjectInitializer);

    UPROPERTY(EditDefaultsOnly, Category=GameMode)
    TSoftObjectPtr<const USimpleGameplayExperience> DefaultExperience;
};
