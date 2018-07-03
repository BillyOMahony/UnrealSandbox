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

	case EDoorOpenDirection::DOD_Forward:
		DoorOpenPosition = DoorClosedPosition + GetActorForwardVector() * -DoorMovementDistance;
		break;

	case EDoorOpenDirection::DOD_Back:
		DoorOpenPosition = DoorClosedPosition + GetActorForwardVector() * DoorMovementDistance;
		break;
	}

	if (DoorCenter)
	{
		ClosedRotation = DoorCenter->GetComponentRotation();
		FString ClosedRotString = ClosedRotation.ToString();
		UE_LOG(LogTemp, Warning, TEXT("%s"), *ClosedRotString);
		OpenRotation = ClosedRotation + FRotator(180, 0, 0);
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

	if(RotationInProgress)
	{
		RotateCenter(DeltaTime);
	}

	// TODO Tidy this
	if(ActionInProgress && (!RotationInProgress || !RotatingFirst))
	{
		CurrentTime += DeltaTime;
		float alpha = CurrentTime / DoorOpenTime;

		if(alpha > 1)
		{
			alpha = 1;
			if(DoorCenter)
			{
				if(!RotatingFirst)
				{
					CurrentTime = 0;
					RotationInProgress = true;
				}
			}
			ActionInProgress = false;
			DoorOpen = !DoorOpen;
		}

		FVector DoorPos = FMath::Lerp(StartPos, EndPos, alpha);
		
		SetActorLocation(DoorPos);
	}

}

void ASlidingDoor::Interact_Implementation(AActor* Caller)
{
	if(!ActionInProgress && !RotationInProgress)
	{
		if(!DoorOpen)
		{
			if(DoorCenter)
			{
				StartRotation = ClosedRotation;
				EndRotation = OpenRotation;
				RotationInProgress = true;
				RotatingFirst = true;
			}
			StartPos = DoorClosedPosition;
			EndPos = DoorOpenPosition;
		}
		else
		{
			if (DoorCenter)
			{
				StartRotation = OpenRotation;
				EndRotation = ClosedRotation;
				RotationInProgress = false;
				RotatingFirst = false;
			}
			StartPos = DoorOpenPosition;
			EndPos = DoorClosedPosition;
		}
		ActionInProgress = true;
		CurrentTime = 0.f;

		UE_LOG(LogTemp, Warning, TEXT("DoorStatus: %i"), RotatingFirst);
	}
}

void ASlidingDoor::RotateCenter(float DeltaTime)
{
	CurrentTime += DeltaTime;
	float alpha = CurrentTime / DoorCenterRotationTime;

	if (alpha > 1)
	{
		alpha = 1;
		RotationInProgress = false;
		CurrentTime = 0;
	}

	FRotator DoorRotation = FMath::Lerp(StartRotation, EndRotation, alpha);

	DoorCenter->SetWorldRotation(DoorRotation);
}

void ASlidingDoor::SetDoorCenter(USceneComponent * doorCenter)
{
	DoorCenter = doorCenter;
}

