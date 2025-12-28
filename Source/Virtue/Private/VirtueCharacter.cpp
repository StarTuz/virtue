
#include "VirtueCharacter.h"
#include "Camera/CameraComponent.h"
#include "Components/CapsuleComponent.h"
#include "Components/StaticMeshComponent.h"
#include "Engine/World.h"
#include "EnhancedInputComponent.h"
#include "EnhancedInputSubsystems.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "GameFramework/PlayerController.h"
#include "GameFramework/SpringArmComponent.h"
#include "InputAction.h"
#include "InputMappingContext.h"
#include "Materials/Material.h"
#include "UObject/ConstructorHelpers.h"
#include "VirtueInteractableInterface.h"
#include "VirtueSystemComponent.h"

AVirtueCharacter::AVirtueCharacter() {
  // Set size for player capsule
  GetCapsuleComponent()->InitCapsuleSize(42.f, 96.0f);

  // Don't rotate character to camera direction
  bUseControllerRotationPitch = false;
  bUseControllerRotationYaw = false;
  bUseControllerRotationRoll = false;

  // Configure character movement
  GetCharacterMovement()->bOrientRotationToMovement =
      true; // Rotate character to moving direction
  GetCharacterMovement()->RotationRate = FRotator(0.f, 640.f, 0.f);
  GetCharacterMovement()->bConstrainToPlane = true;
  GetCharacterMovement()->bSnapToPlaneAtStart = true;

  // Create a mesh for visualization (Prototyping)
  VisualMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("VisualMesh"));
  VisualMesh->SetupAttachment(RootComponent);

  static ConstructorHelpers::FObjectFinder<UStaticMesh> CubeMeshAsset(
      TEXT("/Engine/BasicShapes/Cube.Cube"));
  if (CubeMeshAsset.Succeeded()) {
    VisualMesh->SetStaticMesh(CubeMeshAsset.Object);
    VisualMesh->SetRelativeLocation(FVector(0.0f, 0.0f, -96.0f));
    VisualMesh->SetRelativeScale3D(FVector(0.5f, 0.5f, 2.0f));
  }

  // Create a camera boom...
  CameraBoom = CreateDefaultSubobject<USpringArmComponent>(TEXT("CameraBoom"));
  CameraBoom->SetupAttachment(RootComponent);
  CameraBoom->SetUsingAbsoluteRotation(
      true); // Don't want arm to rotate when character does
  CameraBoom->TargetArmLength = 800.f;
  CameraBoom->SetRelativeRotation(FRotator(-60.f, 0.f, 0.f));
  CameraBoom->bDoCollisionTest =
      false; // Don't want to pull camera in when it collides with level

  // Create a camera...
  TopDownCameraComponent =
      CreateDefaultSubobject<UCameraComponent>(TEXT("TopDownCamera"));
  TopDownCameraComponent->SetupAttachment(CameraBoom,
                                          USpringArmComponent::SocketName);
  TopDownCameraComponent->bUsePawnControlRotation =
      false; // Camera does not rotate relative to arm

  // Create the Virtue System Component
  VirtueComponent =
      CreateDefaultSubobject<UVirtueSystemComponent>(TEXT("VirtueSystem"));

  // Activate ticking in order to update the cursor every frame.
  PrimaryActorTick.bCanEverTick = true;
  PrimaryActorTick.bStartWithTickEnabled = true;
}

void AVirtueCharacter::BeginPlay() {
  Super::BeginPlay();
  UE_LOG(LogTemp, Warning, TEXT("VirtueCharacter ALIVE and Possessed!"));

  // Add Input Mapping Context
  if (APlayerController *PC = Cast<APlayerController>(Controller)) {
    if (UEnhancedInputLocalPlayerSubsystem *Subsystem =
            ULocalPlayer::GetSubsystem<UEnhancedInputLocalPlayerSubsystem>(
                PC->GetLocalPlayer())) {
      if (DefaultMappingContext) {
        Subsystem->AddMappingContext(DefaultMappingContext, 0);
      } else {
        UE_LOG(LogTemp, Error,
               TEXT("DefaultMappingContext is MISSING on VirtueCharacter! "
                    "Please assign in Blueprint."));
      }
    }
  }
}

void AVirtueCharacter::Tick(float DeltaTime) {
  Super::Tick(DeltaTime);
  if (GetWorld()) {
    PerformInteractionCheck();
  }
}

void AVirtueCharacter::SetupPlayerInputComponent(
    UInputComponent *PlayerInputComponent) {
  Super::SetupPlayerInputComponent(PlayerInputComponent);

  if (UEnhancedInputComponent *EnhancedInputComponent =
          CastChecked<UEnhancedInputComponent>(PlayerInputComponent)) {
    // Moving
    if (MoveAction) {
      EnhancedInputComponent->BindAction(MoveAction, ETriggerEvent::Triggered,
                                         this, &AVirtueCharacter::Move);
    }

    // Interacting
    if (InteractAction) {
      EnhancedInputComponent->BindAction(InteractAction, ETriggerEvent::Started,
                                         this, &AVirtueCharacter::Interact);
    }
  }
}

void AVirtueCharacter::Move(const FInputActionValue &Value) {
  // input is a Vector2D
  FVector2D MovementVector = Value.Get<FVector2D>();

  if (Controller != nullptr) {
    // find out which way is forward
    const FRotator Rotation = Controller->GetControlRotation();
    const FRotator YawRotation(0, Rotation.Yaw, 0);

    // get forward vector
    const FVector ForwardDirection =
        FRotationMatrix(YawRotation).GetUnitAxis(EAxis::X);

    // get right vector
    const FVector RightDirection =
        FRotationMatrix(YawRotation).GetUnitAxis(EAxis::Y);

    // add movement
    AddMovementInput(ForwardDirection, MovementVector.Y);
    AddMovementInput(RightDirection, MovementVector.X);
  }
}

void AVirtueCharacter::PerformInteractionCheck() {
  if (APlayerController *PC = Cast<APlayerController>(GetController())) {
    FHitResult HitResult;
    // Check what is under the mouse cursor
    if (PC->GetHitResultUnderCursor(ECC_Visibility, false, HitResult)) {
      AActor *HitActor = HitResult.GetActor();

      if (HitActor != FocusedActor) {
        // If we were looking at something else, tell it we stopped
        if (FocusedActor &&
            FocusedActor->Implements<UVirtueInteractableInterface>()) {
          IVirtueInteractableInterface::Execute_OnEndFocus(FocusedActor);
        }

        // Check if new object is interactable
        if (HitActor && HitActor->Implements<UVirtueInteractableInterface>()) {
          FocusedActor = HitActor;
          IVirtueInteractableInterface::Execute_OnFocus(FocusedActor);
          UE_LOG(LogTemp, Warning, TEXT("New Focus: %s"),
                 *FocusedActor->GetName());
        } else {
          FocusedActor = nullptr;
        }
      }
    } else {
      // Mouse is floating over nothing
      if (FocusedActor) {
        if (FocusedActor->Implements<UVirtueInteractableInterface>()) {
          IVirtueInteractableInterface::Execute_OnEndFocus(FocusedActor);
        }
        FocusedActor = nullptr;
      }
    }
  }
}

void AVirtueCharacter::Interact() {
  UE_LOG(LogTemp, Warning,
         TEXT("Interact Input PRESSED")); // Check Action Binding

  if (FocusedActor) {
    UE_LOG(LogTemp, Warning, TEXT("Attempting to Interact with: %s"),
           *FocusedActor->GetName());
    if (FocusedActor->Implements<UVirtueInteractableInterface>()) {
      IVirtueInteractableInterface::Execute_OnInteract(FocusedActor, this);
    }
  } else {
    UE_LOG(LogTemp, Warning, TEXT("Interact Failed: No Focused Actor"));
  }
}
