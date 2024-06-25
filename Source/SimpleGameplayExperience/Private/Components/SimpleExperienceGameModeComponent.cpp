// Copyright 2024 Josie Thompson, MIT License

#include "Components/SimpleExperienceGameModeComponent.h"

#include "LogGameplayExperience.h"
#include "GameMode/SimpleExperiencePlayerState.h"
#include "Components/SimpleExperiencePlayerStateComponent.h"
#include "Experience/SimpleExperienceSettings.h"
#include "Experience/SimpleExperienceWorldSettings.h"
#include "Experience/SimplePawnData.h"

USimpleExperienceGameModeComponent::USimpleExperienceGameModeComponent(const FObjectInitializer& ObjectInitializer)
    : Super{ ObjectInitializer }
{
}

const USimpleGameplayExperience * USimpleExperienceGameModeComponent::ChooseExperience() const
{
    if (const auto* WorldSettings = Cast<ASimpleExperienceWorldSettings>(GetOwner()->GetWorldSettings())) {
        if (const auto* DefaultExperience = WorldSettings->DefaultExperience.LoadSynchronous()) {
            return DefaultExperience;
        }
    }
    return USimpleExperienceSettings::GetOrLoadDefaultGameplayExperience();
}

UClass * USimpleExperienceGameModeComponent::GetPawnClassForController(AController * Controller) const
{
    const auto* PlayerState = Controller->GetPlayerState<APlayerState>();
    if (!PlayerState) { return nullptr; }

    // If the player state is a subclass of SimpleExperiencePlayerState,
    // it _should_ be faster to directly reference the component member
    if (const auto* ExperiencePlayerState = Cast<ASimpleExperiencePlayerState>(PlayerState)) {
        return ExperiencePlayerState->PawnDataState->PawnData->PawnClass;
    }
    // However, the plugin doesn't require that you derive from SimpleExperiencePlayerState.
    // To support a composition-oriented approach, find the component among the other actor components
    //
    // Note: if the actor doesn't have many components, this shouldn't be _too_ much slower
    //       than the inheritance approach.
    using UPawnDataState = USimpleExperiencePlayerStateComponent;
    if (const auto* PawnDataState = PlayerState->FindComponentByClass<UPawnDataState>()) {
        return PawnDataState->PawnData->PawnClass;
    }
#if !UE_BUILD_SHIPPING
    UE_LOG(LogGameplayExperience, Error,
           TEXT("Unable to find Experience component on Controller. "
                "Please add the Controller Experience component to your custom Controller class"))
#endif
    return nullptr;
}

