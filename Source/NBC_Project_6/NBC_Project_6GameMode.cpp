// Copyright Epic Games, Inc. All Rights Reserved.

#include "NBC_Project_6GameMode.h"
#include "NBC_Project_6Character.h"
#include "UObject/ConstructorHelpers.h"

ANBC_Project_6GameMode::ANBC_Project_6GameMode()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/ThirdPerson/Blueprints/BP_ThirdPersonCharacter"));
	if (PlayerPawnBPClass.Class != NULL)
	{
		DefaultPawnClass = PlayerPawnBPClass.Class;
	}
}
