// Fill out your copyright notice in the Description page of Project Settings.

#include "SlidingDoor.h"
#include "Runtime/Engine/Classes/Components/StaticMeshComponent.h"


// Sets default values
ASlidingDoor::ASlidingDoor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

void ASlidingDoor::Initialise()
{
	DoorClosedPosition = GetActorLocation();
	switch(DoorOpenDirection)
	{
	case EDoorOpenDirection::DOD_Down:
		DoorOpenPosition = DoorClosedPosition + GetActorUpVector() * -DoorMovementDistance;
		break;

	case EDoorOpenDirection::DOD_Up:
		DoorOpenPosition = DoorClosedPosition + GetActorUpVector() * DoorMovementDistance;
		break;

	case EDoorOpenDirection::DOD_Left:
		DoorOpenPosition = DoorClosedPosition + GetActorRightVector() * -DoorMovementDistance;
		break;

	case EDoorOpenDirection::DOD_Right:
		DoorOpenPosition = DoorClosedPosition + GetActorRightVector() * DoorMovementDistance;
		break;
	}
}

// Called when the game starts or when spawned
void ASlidingDoor::BeginPlay()
{
	Super::BeginPlay();
	Initialise();
}

// Called every frame
void ASlidingDoor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	if(ActionInProgress)
	{
		CurrentTime += DeltaTime;
		float alpha = CurrentTime / DoorOpenTime;

		if(alpha > 1)
		{
			alpha = 1;
			ActionInProgress = false;
			DoorOpen = !DoorOpen;
		}

		FVector DoorPos = FMath::Lerp(StartPos, EndPos, alpha);
		
		SetActorLocation(DoorPos);
	}

}

void ASlidingDoor::Interact_Implementation(AActor* Caller)
{
	if(!ActionInProgress)
	{
		if(!DoorOpen)
		{
			StartPos = DoorClosedPosition;
			EndPos = DoorOpenPosition;
		}
		else
		{
			StartPos = DoorOpenPosition;
			EndPos = DoorClosedPosition;
		}
		ActionInProgress = true;
		CurrentTime = 0.f;
	}
}

