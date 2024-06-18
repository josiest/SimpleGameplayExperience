// Copyright 2024 Josie Thompson, MIT License
#include "SimpleExperiencePlayerState.h"
#include "Components/SimpleExperienceStateComponent.h"

ASimpleExperiencePlayerState::ASimpleExperiencePlayerState(const FObjectInitializer & ObjectInitializer)
    : Super{ ObjectInitializer }
{
    ExperienceState = CreateDefaultSubobject<USimpleExperienceStateComponent>(TEXT("ExperienceState"));
}
