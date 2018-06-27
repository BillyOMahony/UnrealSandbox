// Fill out your copyright notice in the Description page of Project Settings.

#include "AlarmLightActor.h"


// Sets default values
AAlarmLightActor::AAlarmLightActor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AAlarmLightActor::BeginPlay()
{
	Super::BeginPlay();

	if (!SpotLight) return;

	SetState();

}

// Called every frame
void AAlarmLightActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	if(Active)
	{
		if (!SpotLight)return;

		UE_LOG(LogTemp, Warning, TEXT("LIGHT IS ACTIVE"));

		SpotLight->AddLocalRotation(FRotator(0, DeltaTime * RotationDegPerSec, 0));
	}
}

/*
 *	Sets state of the light when active state changes
 */
void AAlarmLightActor::SetState()
{
	if(Active)
	{
		SpotLight->SetIntensity(Intensity);
	}
	else
	{
		SpotLight->SetIntensity(0);
	}
}

void AAlarmLightActor::Interact_Implementation(AActor * Caller)
{
	if (!SpotLight) return;

	Active = !Active;

	SetState();
}

void AAlarmLightActor::SetLight(ULightComponent * Light)
{
	SpotLight = Light;
}

