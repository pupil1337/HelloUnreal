// Copyright Epic Games, Inc. All Rights Reserved.

#include "HUGameModeBase.h"
#include "HUHUDBase.h"
#include "HUCharacterBase.h"
#include "UObject/ConstructorHelpers.h"

AHUGameModeBase::AHUGameModeBase()
	: Super()
{
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnClassFinder(TEXT("/Game/FirstPerson/BP_HUCharacterBase"));
	DefaultPawnClass = PlayerPawnClassFinder.Class;

	HUDClass = AHUHUDBase::StaticClass();
}
