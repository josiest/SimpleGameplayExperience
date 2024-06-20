// Copyright 2024 Josie Thompson, MIT License
#pragma once
#include "GameFramework/PlayerState.h"
#include "SimpleExperiencePlayerState.generated.h"

class USimpleExperiencePlayerStateComponent;

/**
 * ASimpleExperiencePlayerState
 *  A simple player state customization that sets up the Experience State component
 *
 * This class is included to make this plugin easy to use out of the box. If you need your own custom player
 * state logic, it's recommended NOT to derive from this class. Instead, you should:
 *  - Add the SimpleExperienceStateComponent to your PlayerState class
 *  - Set the PlayerState class in your GameMode (which should derive from SimpleExperienceGameMode)
 */
UCLASS()
class SIMPLEGAMEPLAYEXPERIENCE_API ASimpleExperiencePlayerState : public APlayerState {
    GENERATED_BODY()
public:
    ASimpleExperiencePlayerState(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get());

    UPROPERTY()
    TObjectPtr<USimpleExperiencePlayerStateComponent> ExperienceState;
};
