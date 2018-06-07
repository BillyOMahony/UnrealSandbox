// Fill out your copyright notice in the Description page of Project Settings.

#include "InteractablePanel.h"


// Sets default values
AInteractablePanel::AInteractablePanel()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AInteractablePanel::BeginPlay()
{
	Super::BeginPlay();
}

// Called every frame
void AInteractablePanel::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void AInteractablePanel::OnInteract_Implementation(AActor * Caller)
{
	UE_LOG(LogTemp, Warning, TEXT("INTERACTED"));
}

void AInteractablePanel::StartFocus_Implementation()
{
	UE_LOG(LogTemp, Warning, TEXT("SF: %s"), *(GetOwner()->GetName()));
}

void AInteractablePanel::EndFocus_Implementation()
{
	UE_LOG(LogTemp, Warning, TEXT("EF"));
}

