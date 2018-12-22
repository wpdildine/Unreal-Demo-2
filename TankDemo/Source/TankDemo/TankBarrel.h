// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/StaticMeshComponent.h"
#include "TankBarrel.generated.h"

/**
 * 
 */
UCLASS(ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))
class TANKDEMO_API UTankBarrel : public UStaticMeshComponent
{
	GENERATED_BODY()

public :

	void Elevate(float RelativeSpeed);


private :
	UPROPERTY(EditDefaultsOnly)
		float MaxDegreesPerSecond = 5;
	UPROPERTY(EditDefaultsOnly)
		float MaxElevationDegrees = 30;
	UPROPERTY(EditDefaultsOnly)
		float MinElevationDegrees = 0;

	
};
