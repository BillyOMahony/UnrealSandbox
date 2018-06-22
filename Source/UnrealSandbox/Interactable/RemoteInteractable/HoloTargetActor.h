// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "RemoteInteractableActor.h"
#include "GameFramework/Actor.h"
#include "Components/PointLightComponent.h"
#include "HoloTargetActor.generated.h"

UCLASS()
class UNREALSANDBOX_API AHoloTargetActor : public ARemoteInteractableActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AHoloTargetActor();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	virtual void Interact_Implementation(AActor* Caller) override;

private:
	UPROPERTY(EditAnywhere, Category = "Setup")
		UPointLightComponent * HoloPointLight;

	UPROPERTY(EditAnywhere, Category = "Setup")
		UStaticMeshComponent * TargetMesh;

	bool ActorHidden = false;
};
