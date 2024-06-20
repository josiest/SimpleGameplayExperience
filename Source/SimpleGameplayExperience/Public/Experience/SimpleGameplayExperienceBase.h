// Copyright 2024 Josie Thompson, MIT License

#pragma once
#include "Engine/DataAsset.h"
#include "SimpleGameplayExperienceBase.generated.h"

class USimplePawnDataBase;

/**
 * USimpleGameplayExperienceBase
 *  Base Class for Gameplay Experiences.
 */
UCLASS(Abstract)
class SIMPLEGAMEPLAYEXPERIENCE_API USimpleGameplayExperienceBase : public UPrimaryDataAsset {
    GENERATED_BODY()
public:
    UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="General")
    TObjectPtr<USimplePawnDataBase> PawnData;
};
