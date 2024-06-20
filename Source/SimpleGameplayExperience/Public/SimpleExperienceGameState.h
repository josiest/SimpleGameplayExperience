// Copyright 2024 Josie Thompson, MIT License
#pragma once
#include "GameFramework/GameStateBase.h"
#include "SimpleExperienceGameState.generated.h"

class USimpleExperienceGameStateComponent;

/**
 * USimpleExperienceGameState
 *  A simple custom game state that sets up the experience manager component.
 *
 * This class is included to make this plugin easy to use out of the box. If you need your own custom game
 * state logic, it's recommended NOT to derive from this class. Instead you should:
 *  - Add the SimpleExperienceManagerComponent to your GameState class
 *  - Set the GameState class in your GameMode (which should derive from SimpleExperienceGameMode)
 */
UCLASS()
class SIMPLEGAMEPLAYEXPERIENCE_API ASimpleExperienceGameState : public AGameStateBase {
    GENERATED_BODY()

public:
    ASimpleExperienceGameState(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get());
    
    UPROPERTY()
    TObjectPtr<USimpleExperienceGameStateComponent> ExperienceState;
};
