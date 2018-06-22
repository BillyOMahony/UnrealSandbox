// Fill out your copyright notice in the Description page of Project Settings.

#include "RemoteInteractableActor.h"


// Sets default values
ARemoteInteractableActor::ARemoteInteractableActor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void ARemoteInteractableActor::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ARemoteInteractableActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void ARemoteInteractableActor::Interact_Implementation(AActor* Caller)
{
	UE_LOG(LogTemp, Warning, TEXT("%s has been interacted with by %s"), *GetName());
}

