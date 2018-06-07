// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Door.h"
#include "SlidingDoor.generated.h"

UCLASS()
class UNREALSANDBOX_API ASlidingDoor : public AActor, public IDoor
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

	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "Interaction")
	void InteractWithDoor();
	virtual void InteractWithDoor_Implementation() override;

private:
	UPROPERTY(EditDefaultsOnly)
	float DoorMovementDistance = 150.f;

	UPROPERTY(EditAnywhere)
	bool DoorOpensLeft = true;

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
