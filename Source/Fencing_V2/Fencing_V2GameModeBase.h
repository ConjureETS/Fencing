// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "Fencing_V2GameModeBase.generated.h"

/**
 * 
 */
UCLASS()
class FENCING_V2_API AFencing_V2GameModeBase : public AGameModeBase
{
	GENERATED_BODY()
	
public:
	UPROPERTY(EditAnywhere, Category = StartMatch)
	bool IsPlayerAreReady;

	int ScorePlayer1;
	int ScorePlayer2;

	int TempScore;

	UPROPERTY(BlueprintReadWrite, Category = Score)
	int HeadScore = 3;
	UPROPERTY(BlueprintReadWrite, Category = Score)
	int BodyScore = 1;

public:
	UFUNCTION(BlueprintCallable, Category = Score)
	void ManageScore(int PlayerIndex, FString HitSide);
	
};
