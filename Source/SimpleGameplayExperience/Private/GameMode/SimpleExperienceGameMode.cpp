// Copyright 2024 Josie Thompson, MIT License
#include "GameMode/SimpleExperienceGameMode.h"

#include "LogGameplayExperience.h"
#include "GameMode/SimpleExperienceGameState.h"
#include "GameMode/SimpleExperiencePlayerState.h"
#include "Components/SimpleExperienceGameModeComponent.h"
#include "Components/SimpleExperienceGameStateComponent.h"
#include "Examples/ExampleGameplayExperience.h"
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
    using UExperience = UExampleGameplayExperience;
    if (auto* ExperienceGameState = Cast<ASimpleExperienceGameState>(GameState)) {
        if (const auto * ExampleExperience = Cast<UExperience>(ExperienceManager->ChooseExperience())) {
            ExperienceGameState->ExperienceState->CurrentExperience = ExampleExperience;
        }
    }
    else if (auto* ExperienceComponent = GameState->FindComponentByClass<UExperienceComponent>()) {
        if (const auto * ExampleExperience = Cast<UExperience>(ExperienceManager->ChooseExperience())) {
            ExperienceComponent->CurrentExperience = ExampleExperience;
        }
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

