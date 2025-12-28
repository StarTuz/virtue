using UnrealBuildTool;

public class Virtue : ModuleRules
{
	public Virtue(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;
	
		PublicDependencyModuleNames.AddRange(new string[] { "Core", "CoreUObject", "Engine", "InputCore", "EnhancedInput", "AIModule", "NavigationSystem", "Niagara" });

		PrivateDependencyModuleNames.AddRange(new string[] {  });
	}
}
