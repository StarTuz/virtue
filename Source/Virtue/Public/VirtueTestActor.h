
#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "VirtueSystemComponent.h"
#include "VirtueTestActor.generated.h"

UCLASS()
class VIRTUE_API AVirtueTestActor : public AActor {
  GENERATED_BODY()

public:
  AVirtueTestActor();

protected:
  virtual void BeginPlay() override;

public:
  virtual void Tick(float DeltaTime) override;

  UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Virtue")
  UVirtueSystemComponent *VirtueComponent;
};
