﻿// Copyright 2024 Josie Thompson, MIT License
#include "SimpleExperienceGameMode.h"

#include "LogGameplayExperience.h"
#include "SimpleExperienceGameState.h"
#include "SimpleExperiencePlayerState.h"
#include "Components/SimpleExperienceGameModeComponent.h"
#include "Components/SimpleExperienceGameStateComponent.h"
#include "GameFramework/GameStateBase.h"

ASimpleExperienceGameMode::ASimpleExperienceGameMode(const FObjectInitializer & ObjectInitializer)
    : Super{ ObjectInitializer }
{
    GameStateClass = ASimpleExperienceGameState::StaticClass();
    PlayerStateClass = ASimpleExperiencePlayerState::StaticClass();

    using UExperienceManager = USimpleExperienceGameModeComponent;
    ExperienceManager = CreateDefaultSubobject<UExperienceManager>(TEXT("ExperienceManager"));
}

void ASimpleExperienceGameMode::InitGameState()
{
    Super::InitGameState();
    
    using UExperienceComponent = USimpleExperienceGameStateComponent;
    if (auto* ExperienceGameState = Cast<ASimpleExperienceGameState>(GameState)) {
        ExperienceGameState->ExperienceState->CurrentExperience = ExperienceManager->ChooseExperience();
    }
    else if (auto* ExperienceComponent = GameState->FindComponentByClass<UExperienceComponent>()) {
        ExperienceComponent->CurrentExperience = ExperienceManager->ChooseExperience();
    }
#if WITH_EDITOR
    else {
        UE_LOG(LogGameplayExperience, Error, TEXT("Unable to find Experience GameState component on Game State. "
                                                  "Please add the Experience GameState component to your "
                                                  "GameState class."))
    }
#endif
}

UClass * ASimpleExperienceGameMode::GetDefaultPawnClassForController_Implementation(AController * InController)
{
    return ExperienceManager->GetPawnClassForController(InController);

}

