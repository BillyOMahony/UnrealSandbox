// Fill out your copyright notice in the Description page of Project Settings.

#include "AlarmIntercomActor.h"


AAlarmIntercomActor::AAlarmIntercomActor()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	AudioComponent = CreateDefaultSubobject<UAudioComponent>(FName(TEXT("Audio Component")));
}

void AAlarmIntercomActor::SetupState()
{
	if (Active)
	{
		AudioComponent->Play();
	}
	else
	{
		AudioComponent->Stop();
	}
}

void AAlarmIntercomActor::BeginPlay()
{
	Super::BeginPlay();

	SetupState();
}

void AAlarmIntercomActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

void AAlarmIntercomActor::Interact_Implementation(AActor * Caller)
{
	Active = !Active;

	SetupState();
}
