// Copyright 2024 Josie Thompson, MIT License
#include "Experience/SimpleGameplayExperienceBase.h"
#include "Experience/SimpleExperienceSettings.h"
#include "Misc/DataValidation.h"

#define LOCTEXT_NAMESPACE "SimpleGameplayExperienceBase"

USimpleGameplayExperienceBase::USimpleGameplayExperienceBase()
{
    if (!PawnData) {
        PawnData = USimpleExperienceSettings::GetOrLoadDefaultPawnData();
    }
}

#if WITH_EDITOR
EDataValidationResult USimpleGameplayExperienceBase::IsDataValid(FDataValidationContext & Context) const
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