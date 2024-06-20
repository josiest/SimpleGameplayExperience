// Copyright 2024 Josie Thompson, MIT License
#include "Components/SimpleExperiencePlayerStateComponent.h"
#include "Components/SimpleExperienceGameStateComponent.h"
#include "Experience/SimpleGameplayExperience.h"
#include "LogGameplayExperience.h"

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

	using UExperienceManager = USimpleExperienceGameStateComponent;
	if (const auto* ExperienceManager = GameState->FindComponentByClass<UExperienceManager>()) {
	    if (!ensure(ExperienceManager->CurrentExperience)) {
	        UE_LOG(LogGameplayExperience, Error,
	               TEXT("The Current Experience has not yet been Set on the Experience Manager Component"))
	    }
	    else {
		    PawnData = ExperienceManager->CurrentExperience->GetPawnData();
	    }
	}
#if WITH_EDITOR
	else {
		UE_LOG(LogGameplayExperience, Error,
		       TEXT("Unable to find Experience Manager component on Game State. "
					"Please add an Experience Manager component to your custom GameState class."))
	}
#endif
}
