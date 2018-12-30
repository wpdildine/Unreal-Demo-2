// Fill out your copyright notice in the Description page of Project Settings.

#include "Tank.h"
#include "TankBarrel.h"
#include "Projectile.h"
#include "TankAimingComponent.h"


// Sets default values
ATank::ATank()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;
}

// Called when the game starts or when spawned
void ATank::BeginPlay()
{
	Super::BeginPlay(); //Need it for BP to Run
	TankAimingComponent = FindComponentByClass<UTankAimingComponent>();

}

// Called every frame
void ATank::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void ATank::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}


void ATank::AimAt(FVector HitLocation)
{
	
	if (!ensure(TankAimingComponent)) { return; };
	UE_LOG(LogTemp, Warning, TEXT("Aiming Component Present"))
	TankAimingComponent->AimAt(HitLocation, LaunchSpeed);

}



void ATank::Fire()
{
	bool isReloaded = (FPlatformTime::Seconds() - LastFireTime) > ReloadTimeInSeconds;
	if (!ensure(TankAimingComponent)) { return; };
	if (!ensure(TankAimingComponent->Barrel)) { return; }
	//Spawn A Project at Socket location

	if (isReloaded){}
	if (TankAimingComponent->Barrel && isReloaded) {
		auto Projectile = GetWorld()->SpawnActor<AProjectile>(
			ProjectileBlueprint,
			TankAimingComponent->Barrel->GetSocketLocation(FName("Projectile")),
			TankAimingComponent->Barrel->GetSocketRotation(FName("Projectile"))
			);


		Projectile->LaunchProjectile(LaunchSpeed);
		LastFireTime = FPlatformTime::Seconds();
	}

}