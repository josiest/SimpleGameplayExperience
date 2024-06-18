// Copyright 2024 Josie Thompson, MIT License
#pragma once
#include "Components/PlayerStateComponent.h"
#include "SimpleExperienceStateComponent.generated.h"


class USimplePawnDataBase;

/**
 * USimpleExperienceStateComponent
 *
 * A component to add to your custom player state.
 * Keeps track of PawnData used for creating the player.
 */
UCLASS()
class SIMPLEGAMEPLAYEXPERIENCE_API USimpleExperienceStateComponent : public UPlayerStateComponent {
    GENERATED_BODY()

public:
    USimpleExperienceStateComponent(const FObjectInitializer& ObjectInitializer);
    virtual void InitializeComponent() override;

    UPROPERTY()
    const USimplePawnDataBase* PawnData = nullptr;
};
