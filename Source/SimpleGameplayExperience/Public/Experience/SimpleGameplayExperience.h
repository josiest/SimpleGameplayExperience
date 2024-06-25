// Copyright 2024 Josie Thompson, MIT License

#pragma once
#include "Engine/DataAsset.h"
#include "SimpleGameplayExperience.generated.h"

class USimplePawnData;

/**
 * USimpleGameplayExperienceBase
 *  Base Class for Gameplay Experiences.
 */
UCLASS(Blueprintable)
class SIMPLEGAMEPLAYEXPERIENCE_API USimpleGameplayExperience : public UPrimaryDataAsset {
    GENERATED_BODY()
public:
    USimpleGameplayExperience();
#if WITH_EDITOR
    virtual EDataValidationResult IsDataValid(FDataValidationContext & Context) const override;
#endif

    UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="General")
    TObjectPtr<const USimplePawnData> PawnData;
};
