// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Interactable.h"
#include "SlidingDoor.h"
#include "GameFramework/Actor.h"
#include "InteractablePanel.generated.h"

UCLASS()
class UNREALSANDBOX_API AInteractablePanel : public AActor, public IInteractable
{
	GENERATED_BODY()

public:
	// Sets default values for this actor's properties
	AInteractablePanel();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "Interaction")
		void OnInteract(AActor* Caller);
	virtual void OnInteract_Implementation(AActor* Caller) override;

	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "Interaction")
		void StartFocus();
	virtual void StartFocus_Implementation() override;

	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "Interaction")
		void EndFocus();
	virtual void EndFocus_Implementation() override;

	UFUNCTION(BlueprintCallable, Category = "Interaction")
		void SetInteractText(UChildActorComponent * InteractText);

private:
	UPROPERTY(EditAnywhere, Category = "Interaction")
		UChildActorComponent * InteractText = nullptr;

	UPROPERTY(EditAnywhere, Category = "Interaction")
		UStaticMeshComponent * Panel = nullptr;

	UPROPERTY(EditAnywhere, Category = "Interaction")
	ARemoteInteractableActor* ActorToInteractWith = nullptr;
};