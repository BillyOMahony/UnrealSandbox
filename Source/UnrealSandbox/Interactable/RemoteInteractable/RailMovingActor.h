// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "RemoteInteractableActor.h"
#include "RailMovingActor.generated.h"

UCLASS()
class UNREALSANDBOX_API ARailMovingActor : public ARemoteInteractableActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ARailMovingActor();
	void InitialisePositionArray();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	virtual void Interact_Implementation(AActor* Caller) override;

private:
	UPROPERTY(EditAnywhere, Category = "Setup")
	FVector ClosePosition;

	UPROPERTY(EditAnywhere, Category = "Setup")
	FVector FarPosition;

	UPROPERTY(VisibleAnywhere, Category = "Setup")
	TArray<FVector> Positions;

	UPROPERTY(EditAnywhere, Category = "Setup")
	int32 NumberOfStops;

	UPROPERTY(EditAnywhere, Category = "Setup")
	float TransitionTime = 3;

	float CurrentTime = 0;

	int32 CurrentIndex = 0;
	int32 NextIndex = 1;
	bool InProgress = false;
};
