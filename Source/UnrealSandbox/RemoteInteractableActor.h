// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "RemoteInteractable.h"
#include "RemoteInteractableActor.generated.h"

UCLASS()
class UNREALSANDBOX_API ARemoteInteractableActor : public AActor, public IRemoteInteractable
{
GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ARemoteInteractableActor();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "Interaction")
	void Interact(AActor* Caller);

	virtual void Interact_Implementation(AActor* Caller) override;
	
};
