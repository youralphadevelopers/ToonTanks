// Fill out your copyright notice in the Description page of Project Settings.


#include "PawnnTurret.h"
#include "Kismet/GameplayStatics.h"
#include "PawnTank.h"


void APawnnTurret::BeginPlay()
{
    Super::BeginPlay();

    GetWorld()->GetTimerManager().SetTimer(FireRateTimerHandle, this, &APawnnTurret::checkFireCondition, FireRate, true);
    PlayerPawn = Cast<APawnTank>(UGameplayStatics::GetPlayerPawn(this, 0));
}

void APawnnTurret::HandleDestruction() 
{
    // Call base pawn class HandleDestruction to play effects. 
    Super::HandleDestruction();
    Destroy();    
}


void APawnnTurret::Tick(float DeltaTime)
{
    Super::Tick(DeltaTime);

    if(!PlayerPawn || ReturnDistanceToPlayer() > FireRange)
    {
        return;
    }

    RotateTurret(PlayerPawn->GetActorLocation());
}


void APawnnTurret::checkFireCondition()
{
    // If Player == null || is Dead THEN BAIL!!

    if(!PlayerPawn || !PlayerPawn->GetIsPlayerAlive())  { return; }

    // IF Player IS in range THEN FIRE!! 
    if(ReturnDistanceToPlayer() <= FireRange){

        Fire();

    }
}

float APawnnTurret::ReturnDistanceToPlayer()
{
    if(!PlayerPawn){ return 0.0f; }

    
    return FVector::Dist(PlayerPawn->GetActorLocation(), GetActorLocation());

}