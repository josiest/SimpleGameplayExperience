// Copyright 2024 Josie Thompson, MIT License
#include "Examples/ExperienceExamplePawnData.h"
#include "Experience/SimpleExperienceSettings.h"
#include "Misc/DataValidation.h"

#define LOCTEXT_NAMESPACE "SimplePawnData"

UExperienceExamplePawnData::UExperienceExamplePawnData()
{
    if (!InputContext) {
        InputContext = USimpleExperienceSettings::GetOrLoadDefaultInputContext();
    }
}

#if WITH_EDITOR
EDataValidationResult UExperienceExamplePawnData::IsDataValid(FDataValidationContext & Context) const
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