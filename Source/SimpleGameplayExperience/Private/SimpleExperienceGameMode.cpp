// Copyright 2024 Josie Thompson, MIT License
#include "SimpleExperienceGameMode.h"

#include "LogGameplayExperience.h"
#include "SimpleExperienceGameState.h"
#include "Components/SimpleExperienceManagerComponent.h"
#include "Components/SimpleExperienceStateComponent.h"
#include "SimpleExperiencePlayerState.h"
#include "SimpleExperienceSettings.h"
#include "Experience/SimpleGameplayExperienceBase.h"
#include "PawnData/SimplePawnDataBase.h"
#include "GameFramework/GameStateBase.h"

ASimpleExperienceGameMode::ASimpleExperienceGameMode(const FObjectInitializer & ObjectInitializer)
    : Super{ ObjectInitializer }
{
    GameStateClass = ASimpleExperienceGameState::StaticClass();
    PlayerStateClass = ASimpleExperiencePlayerState::StaticClass();
}


void ASimpleExperienceGameMode::InitGameState()
{
    Super::InitGameState();
    const USimpleGameplayExperienceBase* CurrentExperience = nullptr;

    const auto* ExperienceSettings = GetDefault<USimpleExperienceSettings>();
    if (const auto* DefaultExperience = ExperienceSettings->DefaultGameplayExperience.LoadSynchronous()) {
        CurrentExperience = DefaultExperience;
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
    if (!CurrentExperience) { return; }

    if (!ensure(GameState)) {
        UE_LOG(LogGameplayExperience, Error, TEXT("GameState is invalid when trying to initialize "
                                                  "the Current Experience in InitGame!"))
        return;
    }
    using UExperienceManager = USimpleExperienceManagerComponent;
    if (auto* ExperienceManager = GameState->FindComponentByClass<UExperienceManager>()) {
        ExperienceManager->CurrentExperience = CurrentExperience;
    }
#if WITH_EDITOR
    else {
        UE_LOG(LogGameplayExperience, Error, TEXT("Unable to find Experience Manager component on Game State. "
                                                  "Please add the Experience Manager component to your "
                                                  "GameState class."))
    }
#endif
}

UClass * ASimpleExperienceGameMode::GetDefaultPawnClassForController_Implementation(AController * InController)
{
    if (const auto* PlayerState = InController->GetPlayerState<APlayerState>()) {
        using UExperienceComponent = USimpleExperienceStateComponent;
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

