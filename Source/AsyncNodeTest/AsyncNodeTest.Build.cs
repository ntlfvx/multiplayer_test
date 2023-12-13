// Copyright Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;

public class AsyncNodeTest : ModuleRules
{
	public AsyncNodeTest(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;

		PublicDependencyModuleNames.AddRange(new string[] { "Core", "CoreUObject", "Engine", "InputCore", "EnhancedInput" });
	}
}
