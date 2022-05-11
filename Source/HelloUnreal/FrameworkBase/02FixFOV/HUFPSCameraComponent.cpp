// Fill out your copyright notice in the Description page of Project Settings.


#include "HUFPSCameraComponent.h"
#include "DarkMagic.h"

UHUFPSCameraComponent::UHUFPSCameraComponent()
{
	PrimaryComponentTick.bCanEverTick = true;
}

void UHUFPSCameraComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	if (APlayerController* PlayerController = GetWorld()->GetFirstPlayerController())
	{
		ULocalPlayer* LocalPlayer = Cast<ULocalPlayer>(PlayerController->Player);

		if (LocalPlayer && LocalPlayer->ViewportClient && LocalPlayer->ViewportClient->Viewport)
		{
			const auto ViewportSize = LocalPlayer->ViewportClient->Viewport->GetSizeXY();
			const auto MaxFit = DarkMagic::GetMaxFittingResolution(1920.0f, 1080.f, ViewportSize.X, ViewportSize.Y);

			if (MaxFit.AspectCorrection == DarkMagic::ResolutionInformation::EAspectCorrection::PILLAR_BOX)
			{
				SetAspectRatio(static_cast<float>(ViewportSize.X) / static_cast<float>(ViewportSize.Y));

				const float HorPlusFov = DarkMagic::HorFovToHorPlus(InitialFieldOfView, 1920.0f, 1080.f, ViewportSize.X, ViewportSize.Y);
				SetFieldOfView(HorPlusFov);
				SetConstraintAspectRatio(false);
			}
			else
			{
				SetAspectRatio(1920.0f / 1080.f);
				SetFieldOfView(InitialFieldOfView);
				SetConstraintAspectRatio(true);
			}
		}
	}
}
