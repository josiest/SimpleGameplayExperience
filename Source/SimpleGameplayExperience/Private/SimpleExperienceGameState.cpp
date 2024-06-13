// Copyright 2024 Josie Thompson, MIT License
#include "SimpleExperienceGameState.h"

#include "SimpleExperienceManagerComponent.h"

ASimpleExperienceGameState::ASimpleExperienceGameState(const FObjectInitializer & ObjectInitializer)
    : Super{ ObjectInitializer }
{
    ExperienceManager = CreateDefaultSubobject<USimpleExperienceManagerComponent>(TEXT("ExperienceManager"));
}
