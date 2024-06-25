// Copyright 2024 Josie Thompson, MIT License

#pragma once
#include "Engine/DeveloperSettings.h"
#include "SimpleExperienceSettings.generated.h"

class UInputMappingContext;
class USimplePawnData;
class USimpleGameplayExperience;
/**
 * Settings for the Gameplay Experience plugin
 */
UCLASS(Config=Game)
class SIMPLEGAMEPLAYEXPERIENCE_API USimpleExperienceSettings : public UDeveloperSettings {
	GENERATED_BODY()

public:
    USimpleExperienceSettings();
    static const FTopLevelAssetPath DefaultExampleExperiencePath;
    static const FTopLevelAssetPath DefaultExampleInputContextPath;

    // Pawn Data utilities
    static TSubclassOf<APawn> GetOrLoadDefaultPawnClass();
    static const USimplePawnData* GetOrLoadDefaultPawnData();

    // Experience utilities
    static const USimpleGameplayExperience* GetOrLoadDefaultGameplayExperience();

    // Example utilities
    static const UInputMappingContext* GetOrLoadDefaultInputContext();

    UPROPERTY(Config, EditDefaultsOnly, Category="Pawn")
    TSoftClassPtr<APawn> DefaultPawnClass;

    UPROPERTY(Config, EditDefaultsOnly, Category="Pawn")
    TSoftObjectPtr<const USimplePawnData> DefaultPawnData;

	UPROPERTY(Config, EditDefaultsOnly, Category="Experience")
	TSoftObjectPtr<const USimpleGameplayExperience> DefaultGameplayExperience;

    UPROPERTY(Config, EditDefaultsOnly, Category="Example")
    TSoftObjectPtr<const UInputMappingContext> DefaultExamplePawnDataInputContext;
};
