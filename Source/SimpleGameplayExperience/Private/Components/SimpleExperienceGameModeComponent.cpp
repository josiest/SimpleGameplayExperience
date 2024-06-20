// Copyright 2024 Josie Thompson, MIT License

#include "Components/SimpleExperienceGameModeComponent.h"

#include "LogGameplayExperience.h"
#include "Components/SimpleExperiencePlayerStateComponent.h"
#include "Experience/SimpleExperienceSettings.h"
#include "Experience/SimpleExperienceWorldSettings.h"
#include "PawnData/SimplePawnDataBase.h"

USimpleExperienceGameModeComponent::USimpleExperienceGameModeComponent(const FObjectInitializer& ObjectInitializer)
    : Super{ ObjectInitializer }
{
}

const USimpleGameplayExperienceBase * USimpleExperienceGameModeComponent::ChooseExperience() const
{
    const USimpleGameplayExperienceBase* CurrentExperience = nullptr;
    if (!CurrentExperience) {
        if (const auto* WorldSettings = Cast<ASimpleExperienceWorldSettings>(GetOwner()->GetWorldSettings())) {
            if (const auto* DefaultExperience = WorldSettings->DefaultExperience.LoadSynchronous()) {
                CurrentExperience = DefaultExperience;
            }
        }
    }

    if (!CurrentExperience) {
        const auto* ExperienceSettings = GetDefault<USimpleExperienceSettings>();
        if (const auto* DefaultExperience = ExperienceSettings->DefaultGameplayExperience.LoadSynchronous()) {
            CurrentExperience = DefaultExperience;
        }
    }
#if WITH_EDITOR
    else if (!CurrentExperience) {
        UE_LOG(LogGameplayExperience, Error,TEXT("Unable to load any experience, please set the default "
                                                  "gameplay experience in gameplay settings"));
    }
    else {
        UE_LOG(LogGameplayExperience, Warning,
               TEXT("Default Experience is not set, please set it in gameplay settings"));
    }
#endif
    return CurrentExperience;
}

UClass * USimpleExperienceGameModeComponent::GetPawnClassForController(AController * Controller) const
{
    if (const auto* PlayerState = Controller->GetPlayerState<APlayerState>()) {
        using UExperienceComponent = USimpleExperiencePlayerStateComponent;
        if (const auto* ExperienceComponent = PlayerState->FindComponentByClass<UExperienceComponent>()) {
            if (ExperienceComponent->PawnData) {
                return ExperienceComponent->PawnData->PawnClass;
            }
#if WITH_EDITOR
            UE_LOG(LogGameplayExperience, Error,
                   TEXT("Pawn Data hasn't yet been set on the Experience State component! "
                        "The logic for when the Pawn Data is set likely needs to be changed. "
                        "It's possible that the Pawn Data is set before the Experience is set on the "
                        "GameState Experience Manager Component!"))
#endif
        }
#if WITH_EDITOR
        else {
            UE_LOG(LogGameplayExperience, Error,
                   TEXT("Unable to find Experience component on Controller. "
                        "Please add the Controller Experience component to your custom Controller class"))
        }
#endif
    }
    return nullptr;
}

