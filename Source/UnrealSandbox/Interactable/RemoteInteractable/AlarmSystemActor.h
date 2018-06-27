// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "RemoteInteractableActor.h"
#include "AlarmIntercomActor.h"
#include "AlarmLightActor.h"
#include "AlarmSystemActor.generated.h"

UCLASS()
class UNREALSANDBOX_API AAlarmSystemActor : public ARemoteInteractableActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AAlarmSystemActor();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	virtual void Interact_Implementation(AActor* Caller) override;

private:
	UPROPERTY(EditAnywhere, Category = "Setup")
	TArray <AAlarmIntercomActor *> AlarmIntercoms;

	UPROPERTY(EditAnywhere, Category = "Setup")
	TArray <AAlarmLightActor *> AlarmLights;
};
