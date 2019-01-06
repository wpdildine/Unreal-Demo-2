// Fill out your copyright notice in the Description page of Project Settings.


#include "TankAIController.h"
#include "TankAimingComponent.h"
#include "Tank.h"

//Depends on Movement component via pathfinding.
void ATankAIController::BeginPlay()
{
	Super::BeginPlay();


}
void ATankAIController::SetPawn(APawn * InPawn)
{

	Super::SetPawn(InPawn);
	if (InPawn)
	{
		auto PossessedTank = Cast<ATank>(InPawn);
		if (!ensure(PossessedTank)) { return; }
		//Subscribe to tanks death event
		PossessedTank->OnDeath.AddUniqueDynamic(this, &ATankAIController::OnPossessedTankDeath);
	}

}
void ATankAIController::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	auto PlayerTank = GetWorld()->GetFirstPlayerController()->GetPawn();
	auto ControlledTank = GetPawn();

	if (!ensure(PlayerTank && ControlledTank)) { return; }

	// Move towards the player
	MoveToActor(PlayerTank, AcceptanceRadius); // TODO check radius is in cm

	// Aim towards the player
	auto AimingComponent = ControlledTank->FindComponentByClass<UTankAimingComponent>();
	AimingComponent->AimAt(PlayerTank->GetActorLocation());

	if (AimingComponent->GetFiringState() == EFiringState::Locked || AimingComponent->GetFiringState() == EFiringState::Aiming)
	{
		AimingComponent->Fire(); // TODO limit firing rate
	}
}

void ATankAIController::OnPossessedTankDeath()
{

	UE_LOG(LogTemp, Warning, TEXT("TANK DEATH"))

}




