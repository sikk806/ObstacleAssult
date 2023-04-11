// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "MovingPlatform.generated.h"

float checkRot(float rot);
UCLASS()
class OBSTACLEASSULT_API AMovingPlatform : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AMovingPlatform();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	UPROPERTY(EditAnywhere); 
	FVector movingVector = FVector(-13580.0, -2370.0, 4080.0);

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UPROPERTY(EditAnywhere);
	int32 i = 1;
	UPROPERTY(EditAnywhere);
	float rot = 10;
	UPROPERTY(EditAnywhere);
	bool a = false;
};
