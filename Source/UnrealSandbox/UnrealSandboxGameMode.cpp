// Copyright 1998-2018 Epic Games, Inc. All Rights Reserved.

#include "UnrealSandboxGameMode.h"
#include "FirstPersonCharacter/UnrealSandboxHUD.h"
#include "FirstPersonCharacter/UnrealSandboxCharacter.h"
#include "UObject/ConstructorHelpers.h"

AUnrealSandboxGameMode::AUnrealSandboxGameMode()
	: Super()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnClassFinder(TEXT("/Game/FirstPersonCPP/Blueprints/FirstPersonCharacter"));
	DefaultPawnClass = PlayerPawnClassFinder.Class;

	// use our custom HUD class
	HUDClass = AUnrealSandboxHUD::StaticClass();
}
