// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Runtime/HeadMountedDisplay/Public/HeadMountedDisplay.h"
#include "Runtime/HeadMountedDisplay/Public/MotionControllerComponent.h"
#include "Runtime/Engine/Classes/Sound/SoundCue.h"
#include "Runtime/Engine/Classes/Components/AudioComponent.h"
#include "SwordMotionController.generated.h"

UCLASS()
class FENCING_V2_API ASwordMotionController : public AActor
{
	GENERATED_BODY()
	
public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = MotionController)
	class UMotionControllerComponent* LeftMotionController;
	
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = Physic)
	UStaticMeshComponent* SwordMesh;

	bool IsAttacking = false;
	bool CanceledAttack = false;

	USoundCue* SwordAudioCue;
	
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = Sound)
	UAudioComponent* SwordAudioComponent;

	int PlayerIndex = 0;

public:	
	// Sets default values for this actor's properties
	ASwordMotionController();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;
	void Attack();
	UFUNCTION(BlueprintCallable, Category = "SwordAttack")
	void ReadyToAttack();
	void CancelAttack();
	
	void SetPlayerIndex(int value) { PlayerIndex = value; }
	UFUNCTION(BlueprintCallable, Category = SwordMotion)
	int GetPlayerIndex() { return PlayerIndex; }
};
