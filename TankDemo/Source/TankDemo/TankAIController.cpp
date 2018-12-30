// Fill out your copyright notice in the Description page of Project Settings.


#include "TankAIController.h"
#include "TankAimingComponent.h"

//Depends on Movement component via pathfinding.
void ATankAIController::BeginPlay()
{
	Super::BeginPlay();


}
void ATankAIController::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	auto PlayerTank = GetWorld()->GetFirstPlayerController()->GetPawn();
	auto AimingComponent = GetPawn()->FindComponentByClass<UTankAimingComponent>();

	if (ensure(PlayerTank))
	{
		// Move towards the player
		MoveToActor(PlayerTank, AcceptanceRadius); // TODO check radius is in cm

		// Aim towards the player
		AimingComponent->AimAt(PlayerTank->GetActorLocation());

		//ControlledTank->Fire(); // TODO limit firing rate
	}

}




