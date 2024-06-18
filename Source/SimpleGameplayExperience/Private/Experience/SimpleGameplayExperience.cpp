// Copyright 2024 Josie Thompson, MIT License

#include "Experience/SimpleGameplayExperience.h"
#include "PawnData/SimplePawnDataBase.h"
#include "PawnData/SimplePawnData.h"

USimplePawnDataBase * USimpleGameplayExperience::GetPawnData() const
{
    return Cast<USimplePawnDataBase>(PawnData);
}
