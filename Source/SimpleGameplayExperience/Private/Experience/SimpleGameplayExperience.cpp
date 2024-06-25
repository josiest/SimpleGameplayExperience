// Copyright 2024 Josie Thompson, MIT License
#include "Experience/SimpleGameplayExperience.h"
#include "Experience/SimpleExperienceSettings.h"
#include "Misc/DataValidation.h"

#define LOCTEXT_NAMESPACE "SimpleGameplayExperienceBase"

USimpleGameplayExperience::USimpleGameplayExperience()
{
    if (!PawnData) {
        PawnData = USimpleExperienceSettings::GetOrLoadDefaultPawnData();
    }
}

#if WITH_EDITOR
EDataValidationResult USimpleGameplayExperience::IsDataValid(FDataValidationContext & Context) const
{
    auto Validity = EDataValidationResult::Valid;
    if (!PawnData) {
        Context.AddError(FText::Format(LOCTEXT("Invalid_PawnData", "Invalid Pawn Data on [{0}]"),
                                       FText::FromString(GetNameSafe(this))));
        Validity = EDataValidationResult::Invalid;
    }
    return CombineDataValidationResults(Validity, Super::IsDataValid(Context));
}

#endif
#undef LOCTEXT_NAMESPACE