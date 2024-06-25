// Copyright 2024 Josie Thompson, MIT License

#pragma once
#include "Engine/DataAsset.h"
#include "SimplePawnDataBase.generated.h"

/**
 * USimplePawnDataBase
 *  The base class for all pawn data.
 */
UCLASS(Blueprintable)
class SIMPLEGAMEPLAYEXPERIENCE_API USimplePawnDataBase : public UPrimaryDataAsset {
    GENERATED_BODY()
public:
    USimplePawnDataBase();
#if WITH_EDITOR
    virtual EDataValidationResult IsDataValid(FDataValidationContext & Context) const override;
#endif

    UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="General")
    TSubclassOf<APawn> PawnClass = nullptr;
};
