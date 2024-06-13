// Copyright Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;

public class SimpleGameplayExperience : ModuleRules
{
    public SimpleGameplayExperience(ReadOnlyTargetRules Target) : base(Target)
    {
        PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;
        PublicDependencyModuleNames.AddRange(new [] {
            "Core",
            "CoreUObject",
            "Engine",
            "EnhancedInput",
            "DeveloperSettings",
            "ModularGameplay"
        });
    }
}
