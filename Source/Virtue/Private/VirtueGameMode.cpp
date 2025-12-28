
#include "VirtueGameMode.h"
#include "UObject/ConstructorHelpers.h"
#include "VirtueCharacter.h"
#include "VirtuePlayerController.h"

AVirtueGameMode::AVirtueGameMode() {
  // use our custom PlayerController class
  PlayerControllerClass = AVirtuePlayerController::StaticClass();

  // set default pawn class to our Blueprinted character
  // Note: We are setting it to the C++ class for now, but usually you want a
  // Blueprint derived from it
  DefaultPawnClass = AVirtueCharacter::StaticClass();
}
