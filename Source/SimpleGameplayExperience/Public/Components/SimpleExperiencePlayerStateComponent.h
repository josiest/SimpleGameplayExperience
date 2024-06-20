// Copyright 2024 Josie Thompson, MIT License
#pragma once
#include "Components/PlayerStateComponent.h"
#include "SimpleExperiencePlayerStateComponent.generated.h"


class USimplePawnDataBase;

/**
 * USimpleExperienceStateComponent
 *
 * A component to add to your custom player state.
 * Keeps track of PawnData used for creating the player.
 */
UCLASS()
class SIMPLEGAMEPLAYEXPERIENCE_API USimpleExperiencePlayerStateComponent : public UPlayerStateComponent {
    GENERATED_BODY()

public:
    USimpleExperiencePlayerStateComponent(const FObjectInitializer& ObjectInitializer);
    virtual void InitializeComponent() override;

    UPROPERTY()
    const USimplePawnDataBase* PawnData = nullptr;
};
