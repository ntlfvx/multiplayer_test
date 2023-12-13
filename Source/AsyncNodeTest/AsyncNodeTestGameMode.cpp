// Copyright Epic Games, Inc. All Rights Reserved.

#include "AsyncNodeTestGameMode.h"
#include "AsyncNodeTestCharacter.h"
#include "UObject/ConstructorHelpers.h"

AAsyncNodeTestGameMode::AAsyncNodeTestGameMode()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/ThirdPerson/Blueprints/BP_ThirdPersonCharacter"));
	if (PlayerPawnBPClass.Class != NULL)
	{
		DefaultPawnClass = PlayerPawnBPClass.Class;
	}
}
