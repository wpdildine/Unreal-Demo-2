// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Engine.h"
#include "GameFramework/PlayerController.h"
#include "TankPlayerController.generated.h"

/**
 * 
 */
class ATank;

UCLASS()
class TANKDEMO_API ATankPlayerController : public APlayerController
{
	GENERATED_BODY()


public:


	virtual void BeginPlay() override;

	virtual void Tick(float DeltaTime) override;

	void AimTowardsCrossHair();

	FVector HitLocation;

protected:
	UFUNCTION(BlueprintCallable, Category = "Setup")
		ATank * GetControlledTank() const;

private:

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
