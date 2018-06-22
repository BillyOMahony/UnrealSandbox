// Fill out your copyright notice in the Description page of Project Settings.

#include "HoloTargetActor.h"


// Sets default values
AHoloTargetActor::AHoloTargetActor()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	USceneComponent * RootComponent = CreateDefaultSubobject<USceneComponent>(TEXT("Root"));
	SetRootComponent(RootComponent);

	HoloPointLight = CreateDefaultSubobject<UPointLightComponent>(TEXT("Holo Point Light"));
	TargetMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Target"));

	HoloPointLight->SetupAttachment(RootComponent);
	TargetMesh->SetupAttachment(RootComponent);

	HoloPointLight->AttachToComponent(RootComponent, FAttachmentTransformRules::KeepRelativeTransform, NAME_None);
	TargetMesh->AttachToComponent(RootComponent, FAttachmentTransformRules::KeepRelativeTransform, NAME_None);
}

// Called when the game starts or when spawned
void AHoloTargetActor::BeginPlay()
{
	Super::BeginPlay();
	/*
	
	*/
}

// Called every frame
void AHoloTargetActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void AHoloTargetActor::Interact_Implementation(AActor * Caller)
{
	ActorHidden = !ActorHidden;
	SetActorHiddenInGame(ActorHidden);
}

