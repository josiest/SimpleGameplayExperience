// Copyright 2024 Josie Thompson, MIT License
#pragma once
#include "Components/GameStateComponent.h"
#include "SimpleExperienceGameStateComponent.generated.h"

class USimpleGameplayExperienceBase;

UCLASS()
class SIMPLEGAMEPLAYEXPERIENCE_API USimpleExperienceGameStateComponent : public UGameStateComponent {
	GENERATED_BODY()

public:
	USimpleExperienceGameStateComponent(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get());

	UPROPERTY()
	const USimpleGameplayExperienceBase* CurrentExperience = nullptr;
};
