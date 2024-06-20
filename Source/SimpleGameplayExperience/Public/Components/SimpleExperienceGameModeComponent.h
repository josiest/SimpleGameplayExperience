// Copyright 2024 Josie Thompson, MIT License

#pragma once
#include "Components/ActorComponent.h"
#include "SimpleExperienceGameModeComponent.generated.h"


class USimpleGameplayExperienceBase;

UCLASS()
class SIMPLEGAMEPLAYEXPERIENCE_API USimpleExperienceGameModeComponent : public UActorComponent {
    GENERATED_BODY()

public:
    USimpleExperienceGameModeComponent(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get());
    virtual const USimpleGameplayExperienceBase* ChooseExperience() const;
    virtual UClass* GetPawnClassForController(AController* Controller) const;
};
