// Copyright 2024 Josie Thompson, MIT License
#include "PawnData/SimplePawnDataBase.h"
#include "Experience/SimpleExperienceSettings.h"
#include "Misc/DataValidation.h"

#define LOCTEXT_NAMESPACE "SimplePawnDataBase"

USimplePawnDataBase::USimplePawnDataBase()
{
    if (!PawnClass) {
        PawnClass = USimpleExperienceSettings::GetOrLoadDefaultPawnClass();
    }
}

#if WITH_EDITOR
EDataValidationResult USimplePawnDataBase::IsDataValid(FDataValidationContext & Context) const
{
    auto IsValidResult = EDataValidationResult::Valid;
    if (!PawnClass) {
        Context.AddError(FText::Format(LOCTEXT("Invalid_PawnClass", "Invalid pawn class on [{0}]"),
                                       FText::FromString(GetNameSafe(this))));
        IsValidResult = EDataValidationResult::Invalid;
    }
    return CombineDataValidationResults(IsValidResult, Super::IsDataValid(Context));
}

#endif
#undef LOCTEXT_NAMESPACE