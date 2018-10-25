#include "stdafx.h"
#include "FBullCowGame.h"

using FString = std::string;
using int32 = int; 



FBullCowGame::FBullCowGame()
{
	Reset();
}

int32 FBullCowGame::GetMaxTries() const { return MyMaxTries; }
int32 FBullCowGame::GetCurrentTry() const { return MyCurrentTry; }

int32 FBullCowGame::GetHiddenWordLength() const { return MyHiddenWord.length(); }



bool FBullCowGame::IsGameWon() const
{
	return false;
}


EGuessStatus FBullCowGame::CheckGuessValidity(FString) const
{
	if (false) //TODO Put in statement for invalid input
	{

		return EGuessStatus::Not_Isogram;
	}
	else if (false)
	{
		return EGuessStatus::Not_Lowercase;
	}
	else if (false)
	{
		return EGuessStatus::Wrong_Lenght;
	}
	// if the guess isn't an isogram return error
	//if the guess isn't all lower case return error
	return EGuessStatus::Ok; //TODO Make actual error
}


void FBullCowGame::Reset()
{
	constexpr int32 MAX_TRIES = 8;
	const FString Hidden_Word = "planet";
	
	
	MyMaxTries = MAX_TRIES;
	MyHiddenWord = Hidden_Word;
	MyCurrentTry = 1;
	
	return;
}
//provide a method for counting bulls and cows, and increasing turn number if valid
FBullCowCount FBullCowGame::SubmitGuess(FString Guess)
{
	//increment a return number
	MyCurrentTry++;

	//Setup a return value
	FBullCowCount BullCowCount;

	//loop through	all the letters in the guess
	int32  HiddenWordLenght = MyHiddenWord.length();
	for (int32 MHWChar = 0; MHWChar < HiddenWordLenght; MHWChar++)
	{
		//compare letters against in the hidden word 
		for (int32 GChar = 0; GChar < HiddenWordLenght; GChar++)
		{
			
			if (Guess[GChar] == MyHiddenWord[MHWChar])
			{
				if (MHWChar == GChar) //if they are in the same place
				{
					BullCowCount.Bulls++;
				}
				else
				{
					BullCowCount.Cows++;
				}
			}
				//incrimnent bulls
			//else
				//incriment cows
		}
	}

	return BullCowCount;
}
