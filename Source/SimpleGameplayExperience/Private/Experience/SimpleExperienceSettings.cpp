// Copyright 2024 Josie Thompson, MIT License
#include "Experience/SimpleExperienceSettings.h"

#include "InputMappingContext.h"
#include "LogGameplayExperience.h"
#include "Experience/SimpleGameplayExperienceBase.h"
#include "GameFramework/DefaultPawn.h"
#include "Experience/SimplePawnDataBase.h"

const FTopLevelAssetPath USimpleExperienceSettings::DefaultExampleExperiencePath{
    TEXT("/SimpleGameplayExperience/Examples/DefaultExperience/EXP_DefaultExperience")
};
const FTopLevelAssetPath USimpleExperienceSettings::DefaultExampleInputContextPath{
    TEXT("/SimpleGameplayExperience/Examples/Input/IMC_SimpleExperienceInput")
};

USimpleExperienceSettings::USimpleExperienceSettings()
{
    if (DefaultPawnClass.IsNull()) {
        DefaultPawnClass = ADefaultPawn::StaticClass();
    }

    using FInputContextReference = ConstructorHelpers::FObjectFinder<UInputMappingContext>;
    static FInputContextReference DefaultExampleInputContext{ *DefaultExampleInputContextPath.ToString() };
    if (DefaultExamplePawnDataInputContext.IsNull()) {
        DefaultExamplePawnDataInputContext = DefaultExampleInputContext.Object;
    }
}

TSubclassOf<APawn> USimpleExperienceSettings::GetOrLoadDefaultPawnClass()
{
    auto* Settings = GetMutableDefault<USimpleExperienceSettings>();
    if (Settings->DefaultPawnClass.IsNull()) {
        Settings->DefaultPawnClass = ADefaultPawn::StaticClass();
    }
    if (Settings->DefaultPawnClass.IsValid()) {
        return Settings->DefaultPawnClass.Get();
    }
    return Settings->DefaultPawnClass.LoadSynchronous();
}

const USimplePawnDataBase * USimpleExperienceSettings::GetOrLoadDefaultPawnData()
{
    const auto* Settings = GetDefault<USimpleExperienceSettings>();
    auto PawnDataToLoad = Settings->DefaultPawnData;
    if (PawnDataToLoad.IsNull()) {
#if !UE_BUILD_SHIPPING
        UE_LOG(LogGameplayExperience, Warning, TEXT("Default Pawn Data isn't set! "
                                                    "Creating the default object instead."));
        UE_LOG(LogGameplayExperience, Warning, TEXT("Please set the Default Pawn Data in "
                                                    "Project Settings > Game > Simple Experience Settings > "
                                                    "Pawn > Default Pawn Data"))
#endif
        PawnDataToLoad = NewObject<USimplePawnDataBase>();
    }
    if (PawnDataToLoad.IsValid()) {
        return PawnDataToLoad.Get();
    }
    return PawnDataToLoad.LoadSynchronous();
}


const USimpleGameplayExperienceBase * USimpleExperienceSettings::GetOrLoadDefaultGameplayExperience()
{
    const auto* Settings = GetDefault<USimpleExperienceSettings>();
    auto ExperienceToLoad = Settings->DefaultGameplayExperience;
    if (ExperienceToLoad.IsNull()) {
#if !UE_BUILD_SHIPPING
        UE_LOG(LogGameplayExperience, Warning, TEXT("Default Gameplay Experience isn't set! "
                                                    "Creating the default object instead."));
        UE_LOG(LogGameplayExperience, Warning, TEXT("Please set the default experience in "
                                                    "Project Settings > Game > Simple Experience Settings > "
                                                    "Experience > Default Gameplay Experience"))
#endif
        ExperienceToLoad = NewObject<USimpleGameplayExperienceBase>();
    }
    if (ExperienceToLoad.IsValid()) {
        return ExperienceToLoad.Get();
    }
    return ExperienceToLoad.LoadSynchronous();
}

const UInputMappingContext * USimpleExperienceSettings::GetOrLoadDefaultInputContext()
{
    auto* Settings = GetMutableDefault<USimpleExperienceSettings>();
    if (Settings->DefaultExamplePawnDataInputContext.IsNull()) {
#if !UE_BUILD_SHIPPING
        UE_LOG(LogGameplayExperience, Warning, TEXT("Default Example Input Context is invalid, "
                                                    "setting it to plugin default value. "));
        UE_LOG(LogGameplayExperience, Warning, TEXT("You can change Default Example Input Context in "
                                                    "Project Settings > Game > Gameplay Experience "
                                                    "Example > Default Example Pawn Data Input Context"))
#endif
        Settings->DefaultExamplePawnDataInputContext = FSoftObjectPath{ DefaultExampleInputContextPath };
    }
    TSoftObjectPtr<const UInputMappingContext> ContextToLoad = Settings->DefaultExamplePawnDataInputContext;
    if (ContextToLoad.IsNull()) {
#if !UE_BUILD_SHIPPING
        UE_LOG(LogGameplayExperience, Error, TEXT("Expecting a default input mapping context at [%s] but "
                                                  "there was none. Creating default object instead"),
                                             *DefaultExampleInputContextPath.ToString());
#endif
        ContextToLoad = NewObject<UInputMappingContext>();
    }
    if (ContextToLoad.IsValid()) {
        return ContextToLoad.Get();
    }
    return Settings->DefaultExamplePawnDataInputContext.LoadSynchronous();
}
