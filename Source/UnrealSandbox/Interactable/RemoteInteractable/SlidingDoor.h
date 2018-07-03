// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "RemoteInteractableActor.h"
#include "AlarmLightActor.h"
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
	DOD_Right	UMETA(DisplayName = "Right"),
	DOD_Forward UMETA(DisplayName = "Forward"),
	DOD_Back	UMETA(DisplayName = "Back")
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
	void ActivateLights();
	void RotateCenter(float DeltaTime);

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	virtual void Interact_Implementation(AActor* Caller) override;

	UFUNCTION(BlueprintCallable)
	void SetDoorCenter(USceneComponent* doorCenter);

private:
	UPROPERTY(EditDefaultsOnly, Category = "Setup")
	float DoorMovementDistance = 150.f;

	UPROPERTY(EditAnywhere, Category = "Setup")
	EDoorOpenDirection DoorOpenDirection = EDoorOpenDirection::DOD_Left;

	UPROPERTY(EditAnywhere, Category = "Setup")
	float DoorOpenTime = 3.f;

	float CurrentTime = 0.f;

	FVector DoorClosedPosition;
	FVector DoorOpenPosition;

	bool ActionInProgress = false;
	bool DoorOpen = false;

	UPROPERTY(EditAnywhere)
	USceneComponent* DoorCenter = nullptr;

	FVector StartPos;
	FVector EndPos;

	// If Door Center
	FRotator OpenRotation;
	FRotator ClosedRotation;

	FRotator StartRotation;
	FRotator EndRotation;

	UPROPERTY(EditAnywhere, Category = "Setup Center")
	float DoorCenterRotationTime = 2.f;

	bool RotationInProgress = false;
	bool RotatingFirst = true;

	// Lights
	UPROPERTY(EditAnywhere, Category = "Setup")
	TArray<AAlarmLightActor *> DoorLights;

};
