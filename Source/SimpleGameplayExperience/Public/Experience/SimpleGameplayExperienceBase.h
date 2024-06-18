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
    template<typename PawnDataType, TEMPLATE_REQUIRES(TIsDerivedFrom<PawnDataType, USimplePawnDataBase>::IsDerived)>
    PawnDataType* GetPawnDataAs() const { return Cast<PawnDataType>(GetPawnData()); }

    /** Get the pawn data this experience will set up. */
    virtual USimplePawnDataBase* GetPawnData() const { return nullptr; }
};
