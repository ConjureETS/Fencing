// Fill out your copyright notice in the Description page of Project Settings.

#include "MannequinCharacter.h"


// Sets default values
AMannequinCharacter::AMannequinCharacter()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AMannequinCharacter::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AMannequinCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void AMannequinCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

