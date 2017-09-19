// Fill out your copyright notice in the Description page of Project Settings.

#include "VrPawn.h"

#include "Engine.h"
#include "Runtime/CoreUObject/Public/UObject/ConstructorHelpers.h"

// Sets default values
AVrPawn::AVrPawn()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	static ConstructorHelpers::FObjectFinder<UBlueprint> SwordClass(TEXT("Blueprint'/Game/BP/SwordMotionController_BP.SwordMotionController_BP'"));
	if (SwordClass.Object) {
		SwordControllerClass = (UClass*)SwordClass.Object->GeneratedClass;
	}

	USceneComponent* RootSceneComponent = CreateDefaultSubobject<USceneComponent>(TEXT("RootComponent"));
	RootComponent = RootSceneComponent;

	//Left
	RightMotionController = CreateDefaultSubobject<UMotionControllerComponent>(TEXT("RightMotionController"));
	RightMotionController->Hand = EControllerHand::Right;
	RightMotionController->SetupAttachment(RootComponent);
}

// Called when the game starts or when spawned
void AVrPawn::BeginPlay()
{
	UWorld* const World = GetWorld();
	if (World) {

		if (SwordControllerClass != NULL)
		{
			SwordMotionController = (ASwordMotionController*)World->SpawnActor<AActor>(SwordControllerClass, FVector(0.0f, 0.0f, 0.0f), FRotator(0.0f, 0.0f, 0.0f));
			SwordMotionController->AttachToActor(this,FAttachmentTransformRules::KeepRelativeTransform);
			SwordMotionController->SetPlayerIndex(PlayerIndex);
		}
	}

	Super::BeginPlay();
}

// Called every frame
void AVrPawn::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void AVrPawn::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

