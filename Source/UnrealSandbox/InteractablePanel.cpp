// Fill out your copyright notice in the Description page of Project Settings.

#include "InteractablePanel.h"


// Sets default values
AInteractablePanel::AInteractablePanel()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	
	Panel = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Panel"));
	SetRootComponent(Panel);
}

// Called when the game starts or when spawned
void AInteractablePanel::BeginPlay()
{
	Super::BeginPlay();
	if(ensure(InteractText))
		InteractText->SetVisibility(false);
}

// Called every frame
void AInteractablePanel::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void AInteractablePanel::OnInteract_Implementation(AActor * Caller)
{
	
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

/*
 *	Called From Blueprint
 *	Sets the reference to the Interact Text
 */
void AInteractablePanel::SetInteractText(UChildActorComponent * InteractText)
{
	this->InteractText = InteractText;
}

