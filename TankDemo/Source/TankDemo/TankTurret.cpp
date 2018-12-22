// Fill out your copyright notice in the Description page of Project Settings.

#include "TankTurret.h"

void UTankTurret::Rotate(float RotationSpeed) 
{
	UE_LOG(LogTemp, Warning, TEXT("Rotator: %f"), RotationSpeed);
	RotationSpeed = FMath::Clamp<float>(RotationSpeed, -1, 1);
	auto RotationChange = RotationSpeed * MaxDegreesPerSecond * GetWorld()->DeltaTimeSeconds;
	auto RawNewRotation = RelativeRotation.Yaw + RotationChange;

	SetRelativeRotation(FRotator(0, RawNewRotation, 0));
}