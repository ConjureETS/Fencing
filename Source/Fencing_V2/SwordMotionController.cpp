// Fill out your copyright notice in the Description page of Project Settings.

#include "SwordMotionController.h"

#include "Runtime/HeadMountedDisplay/Public/HeadMountedDisplay.h"
#include "Runtime/HeadMountedDisplay/Public/MotionControllerComponent.h"

// Sets default values
ASwordMotionController::ASwordMotionController()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	//Left
	LeftMotionController = CreateDefaultSubobject<UMotionControllerComponent>(TEXT("LeftMotionController"));
	LeftMotionController->Hand = EControllerHand::Left;
	LeftMotionController->SetupAttachment(RootComponent);

	SwordMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("SwordMesh"));
	SwordMesh->SetupAttachment(LeftMotionController);

	SwordAudioComponent = CreateDefaultSubobject<UAudioComponent>(TEXT("SwordAudioComp"));
	SwordAudioComponent->bAutoActivate = false;
	SwordAudioComponent->SetupAttachment(LeftMotionController);
}

// Called when the game starts or when spawned
void ASwordMotionController::BeginPlay()
{
	Super::BeginPlay();
}

// Called every frame
void ASwordMotionController::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	if (!IsAttacking && !CanceledAttack)
	{
		FVector swordVelocity = SwordMesh->GetPhysicsLinearVelocity().GetSafeNormal();
		float dotProduct = FVector::DotProduct(SwordMesh->GetForwardVector(), swordVelocity);
		if (dotProduct >= 0.3)
			Attack();
	}
}

void ASwordMotionController::Attack()
{
	IsAttacking = true;
	SwordAudioComponent->Play();

	if (GEngine)
		GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Yellow, TEXT("Some debug message!"));
}

void ASwordMotionController::CancelAttack()
{
	CanceledAttack = true;
}

void ASwordMotionController::ReadyToAttack()
{
	IsAttacking = false;
	CanceledAttack = false;
}

