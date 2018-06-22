// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Interactable/RemoteInteractable/RemoteInteractableActor.h"
#include "SlidingDoor.generated.h"

/*
 *	The direction the door opens relative to its position
 */
UENUM(BlueprintType)		
enum class EDoorOpenDirection : uint8
{
	DOD_Up		UMETA(DisplayName = "Up"),
	DOD_Down	UMETA(DisplayName = "Down"),
	DOD_Left	UMETA(DisplayName = "Left"),
	DOD_Right	UMETA(DisplayName = "Right")
};

UCLASS()
class UNREALSANDBOX_API ASlidingDoor : public ARemoteInteractableActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ASlidingDoor();
	void Initialise();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	virtual void Interact_Implementation(AActor* Caller) override;

private:
	UPROPERTY(EditDefaultsOnly)
	float DoorMovementDistance = 150.f;

	UPROPERTY(EditAnywhere)
	EDoorOpenDirection DoorOpenDirection = EDoorOpenDirection::DOD_Left;

	UPROPERTY(EditAnywhere)
	float DoorOpenTime = 3.f;

	float CurrentTime = 0.f;

	FVector DoorClosedPosition;
	FVector DoorOpenPosition;

	bool ActionInProgress = false;
	bool DoorOpen = false;

	FVector StartPos;
	FVector EndPos;
};
