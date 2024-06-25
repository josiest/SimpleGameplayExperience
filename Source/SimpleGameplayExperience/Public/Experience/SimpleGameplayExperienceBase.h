// Copyright 2024 Josie Thompson, MIT License

#pragma once
#include "Engine/DataAsset.h"
#include "SimpleGameplayExperienceBase.generated.h"

class USimplePawnDataBase;

/**
 * USimpleGameplayExperienceBase
 *  Base Class for Gameplay Experiences.
 */
UCLASS(Blueprintable)
class SIMPLEGAMEPLAYEXPERIENCE_API USimpleGameplayExperienceBase : public UPrimaryDataAsset {
    GENERATED_BODY()
public:
    USimpleGameplayExperienceBase();
#if WITH_EDITOR
    virtual EDataValidationResult IsDataValid(FDataValidationContext & Context) const override;
#endif

    UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="General")
    TObjectPtr<const USimplePawnDataBase> PawnData;
};
