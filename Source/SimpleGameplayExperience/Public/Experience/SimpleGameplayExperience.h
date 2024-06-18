// Copyright 2024 Josie Thompson, MIT License

#pragma once

#include "CoreMinimal.h"
#include "Experience/SimpleGameplayExperienceBase.h"
#include "SimpleGameplayExperience.generated.h"

class USimplePawnData;
/**
 * USimpleGameplayExperience
 */
UCLASS()
class SIMPLEGAMEPLAYEXPERIENCE_API USimpleGameplayExperience : public USimpleGameplayExperienceBase {
    GENERATED_BODY()
public:
    virtual USimplePawnDataBase * GetPawnData() const override;

    UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="General")
    USimplePawnData* PawnData;
};
