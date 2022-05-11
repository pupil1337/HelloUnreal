// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/SkeletalMeshComponent.h"
#include "HUFPSSkeletalMeshComponent.generated.h"

struct FMatrices
{
	FMatrix ViewMatrix;
	FMatrix InverseViewMatrix;
	FMatrix ProjectionMatrix;
	FMatrix InverseProjectionMatrix;
	FMatrix InverseViewProjectionMatrix;
	float NearClippingPlaneDistance;
};

/**
 * 
 */
UCLASS()
class HELLOUNREAL_API UHUFPSSkeletalMeshComponent : public USkeletalMeshComponent
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, Category=Mesh)
	float DesiredHorizontalFov = 90.0f;

	virtual FMatrix GetRenderMatrix() const  override;

	FMatrices GetMatrices(UWorld& World) const;
	
};
