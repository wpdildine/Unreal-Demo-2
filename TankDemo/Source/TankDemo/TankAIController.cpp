// Fill out your copyright notice in the Description page of Project Settings.


#include "TankAIController.h"


void ATankAIController::BeginPlay()
{
	Super::BeginPlay();
	auto Tank = GetAITankController();
	auto Player = GetPlayerTank();
	if (!Tank || !Player) {

		if (!Tank)
			UE_LOG(LogTemp, Warning, TEXT("No Tank available to AIController"));
		if (!Player)
			UE_LOG(LogTemp, Warning, TEXT("No Player available to AI"));

	}
	else {

		UE_LOG(LogTemp, Warning, TEXT("AI Controller %s"), *Tank->GetName());
		UE_LOG(LogTemp, Warning, TEXT("AI Hunting Player %s"), *Player->GetName());
	}

}
void ATankAIController::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	
	if (GetPlayerTank()) {
		AimTowardsPlayer();
	}

}

bool ATankAIController::AimTowardsPlayer() const
{
	GetAITankController()->AimAt(GetPlayerTank()->GetActorLocation());
	return true;
}

 ATank* ATankAIController::GetAITankController() const
{
	return Cast<ATank>(GetPawn());
}

 ATank* ATankAIController::GetPlayerTank() const
 {
	 return Cast<ATank>(GetWorld()->GetFirstPlayerController()->GetPawn());
 }