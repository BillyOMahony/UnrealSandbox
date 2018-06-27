// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Interactable/RemoteInteractable/RemoteInteractableActor.h"
#include "Components/AudioComponent.h"
#include "AlarmIntercomActor.generated.h"

/**
 * 
 */
UCLASS()
class UNREALSANDBOX_API AAlarmIntercomActor : public ARemoteInteractableActor
{
	GENERATED_BODY()

public:
	// Sets default values for this actor's properties
	AAlarmIntercomActor();
	void SetupState();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	virtual void Interact_Implementation(AActor* Caller) override;
	
private:
	UPROPERTY(EditAnywhere)
	UAudioComponent * AudioComponent;

	bool Active = false;
};
