
#include "VirtuePlayerController.h"
#include "Blueprint/AIBlueprintHelperLibrary.h"
#include "Engine/World.h"
#include "EnhancedInputComponent.h"
#include "EnhancedInputSubsystems.h"
#include "GameFramework/Pawn.h"
#include "NiagaraFunctionLibrary.h"
#include "NiagaraSystem.h"
#include "VirtueCharacter.h"

AVirtuePlayerController::AVirtuePlayerController() {
  bShowMouseCursor = true;
  DefaultMouseCursor = EMouseCursor::Default;
}

void AVirtuePlayerController::BeginPlay() { Super::BeginPlay(); }

void AVirtuePlayerController::SetupInputComponent() {
  Super::SetupInputComponent();
}
