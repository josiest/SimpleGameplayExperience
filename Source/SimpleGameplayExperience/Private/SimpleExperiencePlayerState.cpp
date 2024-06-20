// Copyright 2024 Josie Thompson, MIT License
#include "SimpleExperiencePlayerState.h"
#include "Components/SimpleExperiencePlayerStateComponent.h"

ASimpleExperiencePlayerState::ASimpleExperiencePlayerState(const FObjectInitializer & ObjectInitializer)
    : Super{ ObjectInitializer }
{
    using UPawnDataState = USimpleExperiencePlayerStateComponent;
    PawnDataState = CreateDefaultSubobject<UPawnDataState>(TEXT("PawnDataState"));
}
