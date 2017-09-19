// Fill out your copyright notice in the Description page of Project Settings.

#include "Soul.h"

#include "Engine.h"
#include "VrPawn.h"
#include "SpawnPlayer.h"
#include "Runtime/CoreUObject/Public/UObject/ConstructorHelpers.h"

// Sets default values
ASoul::ASoul()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	static ConstructorHelpers::FObjectFinder<UBlueprint> VrClass(TEXT("Blueprint'/Game/BP/VrPawn_BP.VrPawn_BP'"));
	if (VrClass.Object) {
		VrPawnClass = (UClass*)VrClass.Object->GeneratedClass;
	}

	static ConstructorHelpers::FObjectFinder<UBlueprint> MannequinClass(TEXT("Blueprint'/Game/BP/Mannequin_BP.Mannequin_BP'"));
	if (MannequinClass.Object) {
		MannequinPawnClass = (UClass*)MannequinClass.Object->GeneratedClass;
	}
}

// Called when the game starts or when spawned
void ASoul::BeginPlay()
{
	Super::BeginPlay();
	
	TArray<AActor*> foundPlayers;
	UGameplayStatics::GetAllActorsOfClass(GetWorld(), AVrPawn::StaticClass(), foundPlayers);

	TArray<AActor*> foundSpawnPlayers;
	UGameplayStatics::GetAllActorsOfClass(GetWorld(), ASpawnPlayer::StaticClass(), foundSpawnPlayers);

	UWorld* const World = GetWorld();
	if (World) {
		
		if (VrPawnClass != NULL) {
			PossessedPawn = World->SpawnActor<APawn>(VrPawnClass, GetActorLocation(), GetActorRotation());
			AVrPawn* vrPawn = (AVrPawn*)PossessedPawn;
			vrPawn->SetPlayerIndex(foundPlayers.Num());
		}

		else if(MannequinPawnClass != NULL)
			PossessedPawn = World->SpawnActor<APawn>(MannequinPawnClass, GetActorLocation(), GetActorRotation());
	}

	if (PossessedPawn != nullptr)
	{
		AController* PlayerController = GetController();

		if (PlayerController != nullptr)
		{
			PlayerController->UnPossess();
			PlayerController->Possess(PossessedPawn);
		}
	}
}

// Called every frame
void ASoul::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void ASoul::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

