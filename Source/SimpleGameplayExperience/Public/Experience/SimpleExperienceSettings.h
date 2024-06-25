// Copyright 2024 Josie Thompson, MIT License

#pragma once
#include "Engine/DeveloperSettings.h"
#include "SimpleExperienceSettings.generated.h"

class USimpleGameplayExperience;
class UInputMappingContext;
class USimplePawnDataBase;
class USimpleGameplayExperienceBase;
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
    static const USimplePawnDataBase* GetOrLoadDefaultPawnData();

    // Experience utilities
    static const USimpleGameplayExperienceBase* GetOrLoadDefaultGameplayExperience();

    // Example utilities
    static const UInputMappingContext* GetOrLoadDefaultInputContext();

    UPROPERTY(Config, EditDefaultsOnly, Category="Pawn")
    TSoftClassPtr<APawn> DefaultPawnClass;

    UPROPERTY(Config, EditDefaultsOnly, Category="Pawn")
    TSoftObjectPtr<const USimplePawnDataBase> DefaultPawnData;

	UPROPERTY(Config, EditDefaultsOnly, Category="Experience")
	TSoftObjectPtr<const USimpleGameplayExperienceBase> DefaultGameplayExperience;

    UPROPERTY(Config, EditDefaultsOnly, Category="Example")
    TSoftObjectPtr<const UInputMappingContext> DefaultExamplePawnDataInputContext;
};
