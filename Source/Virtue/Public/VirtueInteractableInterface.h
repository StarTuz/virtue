
#pragma once

#include "CoreMinimal.h"
#include "UObject/Interface.h"
#include "VirtueInteractableInterface.generated.h"

// This class does not need to be modified.
UINTERFACE(MinimalAPI)
class UVirtueInteractableInterface : public UInterface {
  GENERATED_BODY()
};

/**
 * Interface for any actor that can be interacted with (Chests, NPCs, Levers,
 * etc.)
 */
class VIRTUE_API IVirtueInteractableInterface {
  GENERATED_BODY()

public:
  // Called when the player focuses on this object (e.g., hover)
  UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "Interaction")
  void OnFocus();

  // Called when the player looks away
  UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "Interaction")
  void OnEndFocus();

  // Called when the player presses the Interact button
  UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "Interaction")
  void OnInteract(class APawn *InstigatorPawn);
};
