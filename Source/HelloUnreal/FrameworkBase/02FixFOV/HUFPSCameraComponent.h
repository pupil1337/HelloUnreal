// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Camera/CameraComponent.h"
#include "HUFPSCameraComponent.generated.h"

/**
 * 
 */
UCLASS()
class HELLOUNREAL_API UHUFPSCameraComponent : public UCameraComponent
{
	GENERATED_BODY()
	
public:
	UHUFPSCameraComponent();
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

private:
	float InitialFieldOfView = 90.0f;
};
