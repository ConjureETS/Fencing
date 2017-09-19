// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "SwordMotionController.h"
#include "Runtime/HeadMountedDisplay/Public/HeadMountedDisplay.h"
#include "Runtime/HeadMountedDisplay/Public/MotionControllerComponent.h"
#include "VrPawn.generated.h"

UCLASS()
class FENCING_V2_API AVrPawn : public APawn
{
	GENERATED_BODY()

private:
	TSubclassOf<class AActor> SwordControllerClass;

	ASwordMotionController* SwordMotionController;

	UPROPERTY(EditAnywhere, Category = MotionController)
	UMotionControllerComponent* RightMotionController;

	int PlayerIndex = 0;

public:
	// Sets default values for this pawn's properties
	AVrPawn();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;
	
	UFUNCTION(BlueprintCallable, Category = SwordMotion)
	ASwordMotionController* GetSwordMotionController() { return SwordMotionController; }

	void SetPlayerIndex(int value) { PlayerIndex = value; }
	UFUNCTION(BlueprintCallable, Category = SwordMotion)
	int GetPlayerIndex() { return PlayerIndex; }
};
