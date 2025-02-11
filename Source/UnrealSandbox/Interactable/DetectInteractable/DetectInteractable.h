// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "CollisionQueryParams.h"
#include "DetectInteractable.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class UNREALSANDBOX_API UDetectInteractable : public UActorComponent
{
GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UDetectInteractable();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

	/*
	 *	Calls Execute_Interact() on the FocusedActor if not null
	 */
	UFUNCTION(BlueprintCallable, Category = "Interaction")
	void Interact();

	/*
	 *	Starts and Ends focus of interactable actors when in view
	 */
	void HandleFocus();

	/*
	 *	Raycasts ahead of camera and returns the first actor found.
	 */
	AActor* FindActorInLineOfSight();

private:
	AActor* FocusedActor = nullptr;
	AActor* OwnerActor = nullptr;
	float InteractionDistance = 300.f;
	FCollisionQueryParams TraceParams;
	
};
