// Copyright Virtue Project. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "VirtueTypes.generated.h"

/**
 * The Tenets of Veridia (Virtues).
 * Used to track the moral standing of the Paragon.
 */
UENUM(BlueprintType)
enum class EVirtueTenet : uint8 {
  Integrity UMETA(DisplayName = "Integrity"),       // Insight
  Compassion UMETA(DisplayName = "Compassion"),     // Sympathy
  Valor UMETA(DisplayName = "Valor"),               // Tenacity
  Justice UMETA(DisplayName = "Justice"),           // Insight + Sympathy
  Honor UMETA(DisplayName = "Honor"),               // Insight + Tenacity
  Sacrifice UMETA(DisplayName = "Sacrifice"),       // Sympathy + Tenacity
  Spirituality UMETA(DisplayName = "Spirituality"), // All Three
  Humility UMETA(DisplayName = "Humility")          // None / Root
};

/**
 * The Foundations of the player's soul.
 */
UENUM(BlueprintType)
enum class EPrincipleType : uint8 {
  Insight UMETA(DisplayName = "Insight"),
  Sympathy UMETA(DisplayName = "Sympathy"),
  Tenacity UMETA(DisplayName = "Tenacity")
};

USTRUCT(BlueprintType)
struct FVirtueStatus {
  GENERATED_BODY()

  UPROPERTY(EditAnywhere, BlueprintReadWrite)
  float CurrentValue;

  UPROPERTY(EditAnywhere, BlueprintReadWrite)
  int32 Rank; // 0-8 (Avatarhood)

  FVirtueStatus() {
    CurrentValue = 50.0f; // Neutral
    Rank = 0;
  }
};
