// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once 

#include "CoreMinimal.h"
#include "GameFramework/HUD.h"
#include "HUHUDBase.generated.h"

UCLASS()
class AHUHUDBase : public AHUD
{
	GENERATED_BODY()

public:
	AHUHUDBase();

	/** Primary draw call for the HUD */
	virtual void DrawHUD() override;

private:
	/** Crosshair asset pointer */
	class UTexture2D* CrosshairTex;

};

