// Copyright 2024 Josie Thompson, MIT License

#pragma once
#include "Engine/DataAsset.h"
#include "SimpleGameplayExperience.generated.h"

class UInputMappingContext;

/**
 * Customize how a game is initialized
 */
UCLASS(BlueprintType)
class SIMPLEGAMEPLAYEXPERIENCE_API USimpleGameplayExperience : public UPrimaryDataAsset {
	GENERATED_BODY()
public:
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="General")
	TSubclassOf<APawn> PawnClass;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Input")
	TObjectPtr<UInputMappingContext> InputContext;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Input")
	int ContextPriority;
};
