// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/StaticMeshComponent.h"
#include "TankTrack.generated.h"

/**
 * 
 */
UCLASS(ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))
class TANKDEMO_API UTankTrack : public UStaticMeshComponent
{
	GENERATED_BODY()

public:

	UFUNCTION(BlueprintCallable, Category = "Input")
		void SetThrottle(float Throttle);

	//Max Force
	UPROPERTY(EditDefaultsOnly)
		float TrackMaxDrivingForce = 40000000; //40 ton tank
private:
	UTankTrack();


	virtual void BeginPlay() override;

	virtual void TickComponent(float DeltaTime, enum ELevelTick TickType, FActorComponentTickFunction *ThisTickFunction) override;

	void ApplySidewaysForce();

	UFUNCTION()
	void OnHit(UPrimitiveComponent* HitComponent, AActor* OtherActor, UPrimitiveComponent* OtherComponent, FVector NormalImpulse, const FHitResult& Hit);

	void DriveTrack();

	float CurrentThrottle = 0;
};
