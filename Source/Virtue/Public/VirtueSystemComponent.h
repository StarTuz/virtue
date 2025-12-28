// Copyright Virtue Project. All Rights Reserved.
// FIXED ORDER CLANG OFF

#pragma once

// clang-format off
#include "Components/ActorComponent.h"
#include "CoreMinimal.h"
#include "VirtueTypes.h"
#include "VirtueSystemComponent.generated.h"
// clang-format on

UCLASS(ClassGroup = (Virtue), meta = (BlueprintSpawnableComponent))
class VIRTUE_API UVirtueSystemComponent : public UActorComponent {
  GENERATED_BODY()

public:
  UVirtueSystemComponent();

protected:
  virtual void BeginPlay() override;

public:
  // Map of Virtues to their current status
  UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Virtue System")
  TMap<EVirtueTenet, FVirtueStatus> VirtueMap;

  // Modify a specific Virtue value (e.g., +5 Integrity for telling truth)
  UFUNCTION(BlueprintCallable, Category = "Virtue System")
  void ModifyVirtue(EVirtueTenet Tenet, float Amount);

  // Check if player has achieved "Avatarhood" (Rank 8) in a Virtue
  UFUNCTION(BlueprintCallable, Category = "Virtue System")
  bool IsParagonOf(EVirtueTenet Tenet) const;

  // Get the textual mantra for a virtue (for UI/Dialogue)
  UFUNCTION(BlueprintPure, Category = "Virtue System")
  FString GetMantra(EVirtueTenet Tenet) const;

private:
  void CheckRankUpdate(EVirtueTenet Tenet);
};
