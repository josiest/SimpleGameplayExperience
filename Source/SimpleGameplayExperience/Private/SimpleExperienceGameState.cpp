// Copyright 2024 Josie Thompson, MIT License
#include "SimpleExperienceGameState.h"
#include "Components/SimpleExperienceGameStateComponent.h"

ASimpleExperienceGameState::ASimpleExperienceGameState(const FObjectInitializer & ObjectInitializer)
    : Super{ ObjectInitializer }
{
    ExperienceManager = CreateDefaultSubobject<USimpleExperienceGameStateComponent>(TEXT("ExperienceManager"));
}
