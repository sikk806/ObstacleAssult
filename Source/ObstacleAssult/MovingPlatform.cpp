// Fill out your copyright notice in the Description page of Project Settings.


#include "MovingPlatform.h"

// Sets default values
AMovingPlatform::AMovingPlatform()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AMovingPlatform::BeginPlay()
{
	Super::BeginPlay();
	SetActorLocation(movingVector);
	
}

// Called every frame
void AMovingPlatform::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	if(i >= 100) {
		a = true;
	}
	else if(i <= -100) {
		a = false;
	}
	if(!a) {
		i++;
	}
	else{
		i--;
	}
	SetActorLocation(FVector(movingVector.X, movingVector.Y + i, movingVector.Z));
	SetActorRotation(FRotator(-i*1.8, i*1.8, -i*1.8));
	

}

