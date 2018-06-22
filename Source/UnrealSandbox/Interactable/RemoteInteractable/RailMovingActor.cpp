// Fill out your copyright notice in the Description page of Project Settings.

#include "RailMovingActor.h"


// Sets default values
ARailMovingActor::ARailMovingActor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
}

void ARailMovingActor::InitialisePositionArray()
{
	if (NumberOfStops<2) NumberOfStops = 2;

	FVector positionDifference = FarPosition - ClosePosition;

	UE_LOG(LogTemp, Warning, TEXT("PosDiff: %s"), *(positionDifference.ToString()));

	FVector stepDifference = positionDifference / (NumberOfStops - 1);

	UE_LOG(LogTemp, Warning, TEXT("StepDiff: %s"), *(stepDifference.ToString()));

	for(int i = 0; i < NumberOfStops; i++)
	{
		FVector newPosition = ClosePosition + (stepDifference * i);
		Positions.Emplace(newPosition);
	}
}

// Called when the game starts or when spawned
void ARailMovingActor::BeginPlay()
{
	Super::BeginPlay();

	InitialisePositionArray();

	SetActorLocation(Positions[CurrentIndex]);

}

// Called every frame
void ARailMovingActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	if(InProgress)
	{
		CurrentTime += DeltaTime;
		float alpha = CurrentTime / TransitionTime;

		if (alpha > 1)
		{
			alpha = 1;
			InProgress = false;
		}

		FVector DoorPos = FMath::Lerp(Positions[CurrentIndex], Positions[NextIndex], alpha);

		SetActorLocation(DoorPos);

		if(!InProgress)
		{
			CurrentIndex = NextIndex;
			NextIndex++;
			if(NextIndex >= Positions.Num())
			{
				NextIndex = 0;
			}
		}

	}

}

void ARailMovingActor::Interact_Implementation(AActor * Caller)
{
	InProgress = true;
	CurrentTime = 0.f;
}

