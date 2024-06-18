// Copyright 2024 Josie Thompson, MIT License
#pragma once
#include "Components/GameStateComponent.h"
#include "SimpleExperienceManagerComponent.generated.h"

class USimpleGameplayExperienceBase;

UCLASS()
class SIMPLEGAMEPLAYEXPERIENCE_API USimpleExperienceManagerComponent : public UGameStateComponent {
	GENERATED_BODY()

public:
	USimpleExperienceManagerComponent(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get());

	UPROPERTY()
	const USimpleGameplayExperienceBase* CurrentExperience = nullptr;
};
