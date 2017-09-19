// Fill out your copyright notice in the Description page of Project Settings.

#include "Fencing_V2GameModeBase.h"

void AFencing_V2GameModeBase::ManageScore(int PlayerIndex, FString HitSide)
{
	if(HitSide == "Head")
	{
		TempScore = HeadScore;
	}
	else if(HitSide == "Body")
	{
		TempScore = BodyScore;
	}

	if (PlayerIndex == 0)
	{
		ScorePlayer1 += TempScore;
	}
	else if (PlayerIndex == 1)
	{
		ScorePlayer2 += TempScore;
	}
}


