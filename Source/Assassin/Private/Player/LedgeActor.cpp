// Fill out your copyright notice in the Description page of Project Settings.


#include "Player/LedgeActor.h"

// Sets default values
ALedgeActor::ALedgeActor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void ALedgeActor::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ALedgeActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

