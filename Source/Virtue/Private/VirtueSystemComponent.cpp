// Copyright Virtue Project. All Rights Reserved.

#include "VirtueSystemComponent.h"

UVirtueSystemComponent::UVirtueSystemComponent() {
  PrimaryComponentTick.bCanEverTick = false;

  // Initialize all virtues to neutral
  for (uint8 i = 0; i < (uint8)EVirtueTenet::Humility + 1; ++i) {
    EVirtueTenet Tenet = (EVirtueTenet)i;
    VirtueMap.Add(Tenet, FVirtueStatus());
  }
}

void UVirtueSystemComponent::BeginPlay() { Super::BeginPlay(); }

void UVirtueSystemComponent::ModifyVirtue(EVirtueTenet Tenet, float Amount) {
  if (FVirtueStatus *Status = VirtueMap.Find(Tenet)) {
    Status->CurrentValue =
        FMath::Clamp(Status->CurrentValue + Amount, 0.0f, 100.0f);
    UE_LOG(LogTemp, Log, TEXT("Virtue %d modified by %f. New Value: %f"),
           (int32)Tenet, Amount, Status->CurrentValue);
    CheckRankUpdate(Tenet);
  }
}

bool UVirtueSystemComponent::IsParagonOf(EVirtueTenet Tenet) const {
  if (const FVirtueStatus *Status = VirtueMap.Find(Tenet)) {
    return Status->Rank >= 8;
  }
  return false;
}

void UVirtueSystemComponent::CheckRankUpdate(EVirtueTenet Tenet) {
  // Simple logic: Rank 8 requires 99+ Value.
  // In strict Ultima, this involved shrines/runes. This is a placeholder logic.
  if (FVirtueStatus *Status = VirtueMap.Find(Tenet)) {
    if (Status->CurrentValue >= 99.0f) {
      if (Status->Rank < 8) {
        // TODO: Trigger "Quest for Avatarhood" or Shrine unlocking?
        // For now, auto-rank up to indicate readiness
        // Status->Rank = 8;
        UE_LOG(
            LogTemp, Warning,
            TEXT("Paragon has achieved mastery of Virtue %d! Seek the Shrine!"),
            (int32)Tenet);
      }
    } else if (Status->CurrentValue < 50.0f) {
      // Karma loss
      Status->Rank = 0;
    }
  }
}

FString UVirtueSystemComponent::GetMantra(EVirtueTenet Tenet) const {
  switch (Tenet) {
  case EVirtueTenet::Integrity:
    return TEXT("Ahm");
  case EVirtueTenet::Compassion:
    return TEXT("Mu");
  case EVirtueTenet::Valor:
    return TEXT("Ra");
  case EVirtueTenet::Justice:
    return TEXT("Beh");
  case EVirtueTenet::Honor:
    return TEXT("Summ");
  case EVirtueTenet::Sacrifice:
    return TEXT("Cah");
  case EVirtueTenet::Spirituality:
    return TEXT("Om");
  case EVirtueTenet::Humility:
    return TEXT("Lum");
  default:
    return TEXT("...");
  }
}
