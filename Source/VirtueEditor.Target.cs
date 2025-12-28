using UnrealBuildTool;
using System.Collections.Generic;

public class VirtueEditorTarget : TargetRules
{
	public VirtueEditorTarget( TargetInfo Target) : base(Target)
	{
		Type = TargetType.Editor;
		DefaultBuildSettings = BuildSettingsVersion.Latest;
		IncludeOrderVersion = EngineIncludeOrderVersion.Latest;
		ExtraModuleNames.Add("Virtue");
	}
}
