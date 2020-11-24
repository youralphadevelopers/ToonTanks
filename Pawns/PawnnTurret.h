// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "MyPawn.h"
#include "PawnnTurret.generated.h"

class APawnTank;

UCLASS()
class TOONTANKS_API APawnnTurret : public AMyPawn
{
	GENERATED_BODY()

private:

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Combat", meta = (AllowPrivateAccess = "true"))
	float FireRate = 1.5f;

	void checkFireCondition();

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Combat", meta = (AllowPrivateAccess = "true"))
	float FireRange = 830.0f;

	FTimerHandle FireRateTimerHandle;

	APawnTank* PlayerPawn;

	void CheckFireCondition();
	
	float ReturnDistanceToPlayer();



public:

	virtual void Tick(float DeltaTime) override;
	virtual void HandleDestruction() override; 

protected:

	virtual void BeginPlay() override;
	

	
};
