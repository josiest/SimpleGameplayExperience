// Copyright 2024 Josie Thompson, MIT License
#include "PawnData/SimplePawnData.h"
#include "Experience/SimpleExperienceSettings.h"
#include "Misc/DataValidation.h"

#define LOCTEXT_NAMESPACE "SimplePawnData"

USimplePawnData::USimplePawnData()
{
    if (!InputContext) {
        InputContext = USimpleExperienceSettings::GetOrLoadDefaultInputContext();
    }
}

#if WITH_EDITOR
EDataValidationResult USimplePawnData::IsDataValid(FDataValidationContext & Context) const
{
    auto Validity = EDataValidationResult::Valid;
    if (!InputContext) {
        Context.AddError(FText::Format(LOCTEXT("Invalid_InputContext", "Invalid input context on [{0}]"),
                                       FText::FromString(GetNameSafe(this))));
        Validity = EDataValidationResult::Invalid;
    }
    return CombineDataValidationResults(Validity, Super::IsDataValid(Context));
}

#endif
#undef LOCTEXT_NAMESPACE