// Copyright 2024 Josie Thompson, MIT License
#pragma once
#include "Experience/SimpleGameplayExperience.h"
#include "ExampleGameplayExperience.generated.h"
class USimplePawnData;

/**
 * UExampleGameplayExperience
 *  Example gameplay experience that uses pawn data
 */
UCLASS(Blueprintable)
class SIMPLEGAMEPLAYEXPERIENCE_API UExampleGameplayExperience : public USimpleGameplayExperience {
    GENERATED_BODY()
public:
    UExampleGameplayExperience();
#if WITH_EDITOR
    virtual EDataValidationResult IsDataValid(FDataValidationContext & Context) const override;
#endif

    UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="General")
    TObjectPtr<const USimplePawnData> PawnData;
};
