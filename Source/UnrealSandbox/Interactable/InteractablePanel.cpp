// Fill out your copyright notice in the Description page of Project Settings.

#include "InteractablePanel.h"
#include "RemoteInteractable/RemoteInteractableActor.h"

// Sets default values
AInteractablePanel::AInteractablePanel()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	
	Panel = CreateDefaultSubobject<UStaticMeshComponent>(FName("Panel"));
	SetRootComponent(Panel);

	InteractText = CreateDefaultSubobject<UChildActorComponent>(FName("InteractText"));
	InteractText->AttachToComponent(Panel, FAttachmentTransformRules::KeepRelativeTransform);
	InteractText->SetupAttachment(Panel);
}

// Called when the game starts or when spawned
void AInteractablePanel::BeginPlay()
{
	Super::BeginPlay();
	if (ensure(InteractText)) {
		InteractText->SetVisibility(false);
	}
	ensure(ActorToInteractWith);
}

// Called every frame
void AInteractablePanel::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void AInteractablePanel::OnInteract_Implementation(AActor * Caller)
{
	if (!ActorToInteractWith)return;
	ActorToInteractWith->Execute_Interact(ActorToInteractWith, this);
}


/*
 *	Sets InteractText visible whne in focus
 */
void AInteractablePanel::StartFocus_Implementation()
{
	if (!ensure(InteractText)) return;
	InteractText->SetVisibility(true);

}

/*
 *	Sets InteractText invisible when no longer in focus
 */
void AInteractablePanel::EndFocus_Implementation()
{
	if (!ensure(InteractText)) return;
	InteractText->SetVisibility(false);
}