// Fill out your copyright notice in the Description page of Project Settings.

#include "AlarmSystemActor.h"


// Sets default values
AAlarmSystemActor::AAlarmSystemActor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AAlarmSystemActor::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AAlarmSystemActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void AAlarmSystemActor::Interact_Implementation(AActor * Caller)
{
	for (int i = 0; i < AlarmIntercoms.Num(); i++)
	{
		AlarmIntercoms[i]->Execute_Interact(AlarmIntercoms[i], this);
	}

	for (int i = 0; i < AlarmLights.Num(); i++)
	{
		AlarmLights[i]->Execute_Interact(AlarmLights[i], this);
	}

}

