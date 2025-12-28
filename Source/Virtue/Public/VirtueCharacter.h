
#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "InputActionValue.h"
#include "VirtueCharacter.generated.h"

class UVirtueSystemComponent;
class UInputMappingContext;
class UInputAction;

UCLASS(Blueprintable)
class VIRTUE_API AVirtueCharacter : public ACharacter {
  GENERATED_BODY()

public:
  AVirtueCharacter();

protected:
  virtual void BeginPlay() override;

public:
  virtual void Tick(float DeltaTime) override;
  virtual void SetupPlayerInputComponent(
      class UInputComponent *PlayerInputComponent) override;

  /** Top down camera boom */
  UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Camera,
            meta = (AllowPrivateAccess = "true"))
  class USpringArmComponent *CameraBoom;

  /** Top down follow camera */
  UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Camera,
            meta = (AllowPrivateAccess = "true"))
  class UCameraComponent *TopDownCameraComponent;

  /** Virtue System for this character */
  UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Virtue,
            meta = (AllowPrivateAccess = "true"))
  UVirtueSystemComponent *VirtueComponent;

  /** Visual Representation for prototyping */
  UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Visual,
            meta = (AllowPrivateAccess = "true"))
  class UStaticMeshComponent *VisualMesh;

  /** Enhanced Input: Mapping Context */
  UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Input,
            meta = (AllowPrivateAccess = "true"))
  UInputMappingContext *DefaultMappingContext;

  /** Enhanced Input: Move Action */
  UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Input,
            meta = (AllowPrivateAccess = "true"))
  UInputAction *MoveAction;

  /** Enhanced Input: Interact Action */
  UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Input,
            meta = (AllowPrivateAccess = "true"))
  UInputAction *InteractAction;

  /** Enhanced Input Handler */
  void Move(const FInputActionValue &Value);

  /** Interaction */
  void Interact();
  void PerformInteractionCheck();

  UPROPERTY()
  AActor *FocusedActor;

  FORCEINLINE class UCameraComponent *GetTopDownCameraComponent() const {
    return TopDownCameraComponent;
  }
  FORCEINLINE class USpringArmComponent *GetCameraBoom() const {
    return CameraBoom;
  }
};
