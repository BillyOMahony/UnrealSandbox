// Fill out your copyright notice in the Description page of Project Settings.

#include "DetectInteractable.h"
#include "Runtime/Engine/Classes/GameFramework/Actor.h"
#include "Interactable.h"
#include "Runtime/Engine/Public/DrawDebugHelpers.h"


// Sets default values for this component's properties
UDetectInteractable::UDetectInteractable()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;


	TraceParams = FCollisionQueryParams(FName(TEXT("Trace")), false, GetOwner());
	// ...
}


// Called when the game starts
void UDetectInteractable::BeginPlay()
{
	Super::BeginPlay();

	OwnerActor = GetOwner();
	
}


// Called every frame
void UDetectInteractable::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	FocusedActor = FindActorInLineOfSight();
	
}

void UDetectInteractable::Interact()
{
	UE_LOG(LogTemp, Warning, TEXT("Interact Called"));
	FString ActorName = FocusedActor->GetName();
	UE_LOG(LogTemp, Warning, TEXT("shite %s"), *ActorName);

	if(FocusedActor)
	{
		FString ActorName = FocusedActor->GetName();
		UE_LOG(LogTemp, Warning, TEXT("%s"), *ActorName);
		IInteractable * InteractableActor = Cast<IInteractable>(FocusedActor);
		if(InteractableActor)
		{
			InteractableActor->Execute_OnInteract(FocusedActor, OwnerActor);
		}
	}

}

void UDetectInteractable::HandleFocus()
{
}

AActor * UDetectInteractable::FindActorInLineOfSight()
{
	FHitResult HitResult;

	FVector PlayerViewPointLocation;
	FRotator PlayerViewPointRotation;
	GetWorld()->GetFirstPlayerController()->GetPlayerViewPoint(PlayerViewPointLocation, PlayerViewPointRotation);
	FVector RaycastLineEnd = PlayerViewPointLocation + PlayerViewPointRotation.Vector() * InteractionDistance;

	GetWorld()->LineTraceSingleByChannel(
		HitResult,
		PlayerViewPointLocation,
		RaycastLineEnd,
		ECC_Visibility,
		TraceParams
	);

	/* DRAW DEBUG LINE */
	DrawDebugLine(GetWorld(), PlayerViewPointLocation, RaycastLineEnd, FColor::Blue, false);

	return HitResult.GetActor();
}

