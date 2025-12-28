
#include "VirtueTestActor.h"

AVirtueTestActor::AVirtueTestActor() {
  PrimaryActorTick.bCanEverTick = true;

  // Create the Virtue System Component
  VirtueComponent =
      CreateDefaultSubobject<UVirtueSystemComponent>(TEXT("VirtueSystem"));
}

void AVirtueTestActor::BeginPlay() {
  Super::BeginPlay();

  if (VirtueComponent) {
    UE_LOG(LogTemp, Warning, TEXT("VirtueTestActor: Starting Virtue Test..."));

    // Test 1: Modify a Virtue
    UE_LOG(LogTemp, Warning,
           TEXT("VirtueTestActor: Adding 10 points to Compassion..."));
    VirtueComponent->ModifyVirtue(EVirtueTenet::Compassion, 10.0f);

    // Test 2: Check Status
    if (VirtueComponent->VirtueMap.Contains(EVirtueTenet::Compassion)) {
      float CurrentVal =
          VirtueComponent->VirtueMap[EVirtueTenet::Compassion].CurrentValue;
      UE_LOG(LogTemp, Warning, TEXT("VirtueTestActor: Compassion is now: %f"),
             CurrentVal);
    }

    // Test 3: Check Mantra
    FString Mantra = VirtueComponent->GetMantra(EVirtueTenet::Compassion);
    UE_LOG(LogTemp, Warning,
           TEXT("VirtueTestActor: Mantra for Compassion is: %s"), *Mantra);
  }
}

void AVirtueTestActor::Tick(float DeltaTime) { Super::Tick(DeltaTime); }
