
#include "BaseInteractableActor.h"
#include "Components/StaticMeshComponent.h"
#include "UObject/ConstructorHelpers.h"

ABaseInteractableActor::ABaseInteractableActor() {
  PrimaryActorTick.bCanEverTick = true;

  MeshComp = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("MeshComp"));
  RootComponent = MeshComp;

  // Default visual: A Cone to distinguish from the Player Cube
  static ConstructorHelpers::FObjectFinder<UStaticMesh> ConeMeshAsset(
      TEXT("/Engine/BasicShapes/Cone.Cone"));
  if (ConeMeshAsset.Succeeded()) {
    MeshComp->SetStaticMesh(ConeMeshAsset.Object);
    MeshComp->SetRelativeScale3D(FVector(0.5f));
  }
}

void ABaseInteractableActor::BeginPlay() { Super::BeginPlay(); }

void ABaseInteractableActor::Tick(float DeltaTime) { Super::Tick(DeltaTime); }

void ABaseInteractableActor::OnFocus_Implementation() {
  // Highlight effect (e.g., turning gold)
  if (MeshComp) {
    MeshComp->SetRenderCustomDepth(true);
    UE_LOG(LogTemp, Log, TEXT("Interactable Focused: %s"), *GetName());
  }
}

void ABaseInteractableActor::OnEndFocus_Implementation() {
  // Remove highlight
  if (MeshComp) {
    MeshComp->SetRenderCustomDepth(false);
    UE_LOG(LogTemp, Log, TEXT("Interactable Unfocused: %s"), *GetName());
  }
}

void ABaseInteractableActor::OnInteract_Implementation(APawn *InstigatorPawn) {
  UE_LOG(LogTemp, Warning, TEXT("INTERACTED with %s by %s"), *GetName(),
         *InstigatorPawn->GetName());

  // Simple visual feedback: Jump up slightly
  AddActorLocalOffset(FVector(0, 0, 50.0f));
}
