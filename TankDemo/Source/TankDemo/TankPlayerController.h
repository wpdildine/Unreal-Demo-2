// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Engine.h"
#include "GameFramework/PlayerController.h"
#include "TankPlayerController.generated.h"

/**
 * 
 */

class UTankAimingComponent;

UCLASS()
class TANKDEMO_API ATankPlayerController : public APlayerController
{
	GENERATED_BODY()


public:

	FVector HitLocation;

	UFUNCTION(BlueprintImplementableEvent, Category = "Setup")
		void FoundAimingComponent(UTankAimingComponent* AimCompRef);

protected:


private:
	virtual void BeginPlay() override;
	virtual void Tick(float DeltaTime) override;
	void AimTowardsCrossHair();
	bool GetSightRayHitLocation(FVector& HitLocation) const;

		UPROPERTY(EditDefaultsOnly)
			float CrossHairX = 0.5;

		UPROPERTY(EditDefaultsOnly)
			float CrossHairY = .33;

		UPROPERTY(EditDefaultsOnly)
			float LineTraceRange = 1000000;

	bool GetLookDirection(FVector2D ScreenLocation, FVector& LookDirection) const;
	bool GetLookVectorHitLocation(FVector LookDirection, FVector& HitLocation) const;

};
