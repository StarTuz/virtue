
#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "VirtuePlayerController.generated.h"

class UInputMappingContext;

UCLASS()
class VIRTUE_API AVirtuePlayerController : public APlayerController {
  GENERATED_BODY()

public:
  AVirtuePlayerController();

protected:
  virtual void BeginPlay() override;
  virtual void SetupInputComponent() override;
};
