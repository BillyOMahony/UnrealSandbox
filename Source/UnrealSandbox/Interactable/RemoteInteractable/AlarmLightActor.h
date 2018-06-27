// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "RemoteInteractableActor.h"
#include "Components/LightComponent.h"
#include "AlarmLightActor.generated.h"

UCLASS()
class UNREALSANDBOX_API AAlarmLightActor : public ARemoteInteractableActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AAlarmLightActor();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;
	void SetState();

	virtual void Interact_Implementation(AActor* Caller) override;

	UFUNCTION(BlueprintCallable)
	void SetLight(ULightComponent * Light);

private:
	UPROPERTY(EditAnywhere, Category = "Alarm")
	bool Active = true;

	UPROPERTY(EditAnywhere, Category = "Alarm")
	ULightComponent * SpotLight;

	UPROPERTY(EditAnywhere, Category = "Alarm")
	float Intensity = 500000;

	UPROPERTY(EditAnywhere, Category = "Alarm")
	float RotationDegPerSec = 720;

};
