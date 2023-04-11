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
	if(i >= 200) {
		a = true;
	}
	else if(i <= -200) {
		a = false;
	}

	if(!a) {
		i++;
	}
	else{
		i--;
	}

	rot = checkRot(rot);

	rot += 0.5;
	SetActorLocation(FVector(movingVector.X, movingVector.Y + i, movingVector.Z));
	SetActorRotation(FRotator(rot));
	

}

float checkRot(float rot) {
	if(rot > 360) {
		rot = -rot;
	}

	return rot;
}
