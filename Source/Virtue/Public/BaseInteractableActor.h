#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "VirtueInteractableInterface.h"
#include "BaseInteractableActor.generated.h"

UCLASS()
class VIRTUE_API ABaseInteractableActor : public AActor, public IVirtueInteractableInterface
{
GENERATED_BODY()

public:
ABaseInteractableActor();

protected:
virtual void BeginPlay() override;

public:
virtual void Tick(float DeltaTime) override;

    // Interface Implementation
    virtual void OnFocus_Implementation() override;
    virtual void OnEndFocus_Implementation() override;
    virtual void OnInteract_Implementation(APawn* InstigatorPawn) override;

    UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Visual")
    class UStaticMeshComponent* MeshComp;
};
