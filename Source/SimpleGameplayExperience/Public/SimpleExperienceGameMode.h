// Copyright 2024 Josie Thompson, MIT License

#pragma once
#include "GameFramework/GameModeBase.h"
#include "SimpleExperienceGameMode.generated.h"

/**
 * Replaces GameMode functionality with Data-Oriented Experiences
 */
UCLASS()
class SIMPLEGAMEPLAYEXPERIENCE_API ASimpleExperienceGameMode : public AGameModeBase {
	GENERATED_BODY()
public:
    ASimpleExperienceGameMode(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get());
    virtual void InitGameState() override;
	virtual UClass* GetDefaultPawnClassForController_Implementation(AController * InController) override;
};
