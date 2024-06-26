// Copyright 2024 Josie Thompson, MIT License
#include "Components/SimpleExperiencePlayerStateComponent.h"
#include "Components/SimpleExperienceGameStateComponent.h"
#include "LogGameplayExperience.h"
#include "Examples/ExampleGameplayExperience.h"

USimpleExperiencePlayerStateComponent::USimpleExperiencePlayerStateComponent(const FObjectInitializer& ObjectInitializer)
    : Super{ ObjectInitializer }
{
    bWantsInitializeComponent = true;
}

void USimpleExperiencePlayerStateComponent::InitializeComponent()
{
    Super::InitializeComponent();
	const auto* GameState = GetWorld()->GetGameState();
    if (!ensure(GameState)) {
        UE_LOG(LogGameplayExperience, Error,
               TEXT("GameState has not yet been initialized when the "
                    "Experience State component is initialized on the player state"))
    }

	using UExperienceState = USimpleExperienceGameStateComponent;
	if (const auto* ExperienceState = GameState->FindComponentByClass<UExperienceState>()) {
	    if (!ensure(ExperienceState->CurrentExperience)) {
	        UE_LOG(LogGameplayExperience, Error,
	               TEXT("The Current Experience has not yet been Set on the Experience GameState Component"))
	    }
	    else {
		    PawnData = ExperienceState->CurrentExperience->PawnData;
	    }
	}
#if !UE_BUILD_SHIPPING
	else {
		UE_LOG(LogGameplayExperience, Error,
		       TEXT("Unable to find Experience GameState component on Game State. "
					"Please add an Experience GameState component to your custom GameState class."))
	}
#endif
}
