// Copyright 2024 Josie Thompson, MIT License

#pragma once
#include "Engine/DataAsset.h"
#include "SimplePawnDataBase.generated.h"

/**
 * USimplePawnData
 *  The most basic PawnData type. Derive from this class to add more to your pawn data
 */
UCLASS(BlueprintType, Const)
class SIMPLEGAMEPLAYEXPERIENCE_API USimplePawnDataBase : public UPrimaryDataAsset {
    GENERATED_BODY()
public:

    UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="General")
    TSubclassOf<APawn> PawnClass = nullptr;
};
