// Copyright 2024 Josie Thompson, MIT License

#pragma once
#include "PawnData/SimplePawnDataBase.h"
#include "SimplePawnData.generated.h"

class UInputMappingContext;
/**
 * USimplePawnData
 *  Simple concrete data class for the most basic pawn setup.
 */
UCLASS(BlueprintType, Const)
class SIMPLEGAMEPLAYEXPERIENCE_API USimplePawnData : public USimplePawnDataBase {
    GENERATED_BODY()
public:
    USimplePawnData();
#if WITH_EDITOR
    virtual EDataValidationResult IsDataValid(FDataValidationContext & Context) const override;
#endif

    UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Input")
    TObjectPtr<const UInputMappingContext> InputContext;

    UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Input")
    int ContextPriority = 0;
};
