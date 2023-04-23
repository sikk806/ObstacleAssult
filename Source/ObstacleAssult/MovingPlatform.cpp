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

	StartLocation = GetActorLocation();
	
}

// Called every frame
void AMovingPlatform::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	UE_LOG(LogTemp, Log, TEXT("%f"), DeltaTime);

	if(i >= 200.0f) {
		a = true;
	}
	else if(i <= -200.0f) {
		a = false;
	}

	if(!a) {
		i += 1.0f;
	}
	else{
		i -= 1.0f;
	}

	rot = checkRot(rot);

	rot += 0.5;
	SetActorLocation(FVector(movingVector.X, movingVector.Y + i, movingVector.Z));
	SetActorRotation(FRotator(rot));
	
	DistanceMoved = FVector::Dist(StartLocation, GetActorLocation());

}

float checkRot(float rot) {
	if(rot > 360) {
		rot = -rot;
	}

	return rot;
}
