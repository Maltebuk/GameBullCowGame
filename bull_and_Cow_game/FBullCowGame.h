#pragma once
#include <string>

using int32 = int; 
using FString = std::string; 
// all values initialized to zero
struct FBullCowCount
{
	int32 Bulls = 0;
	int32 Cows = 0;
};

enum class EGuessStatus
{
	Ok,
	Not_Isogram,
	Wrong_Lenght,
	Not_Lowercase
	
};

class FBullCowGame
{
public:
	FBullCowGame(); // constructor

	int32 GetMaxTries() const;
	int32 GetCurrentTry() const;
	int32 GetHiddenWordLength() const;

	bool IsGameWon() const;
	EGuessStatus CheckGuessValidity(FString) const;
	
	void Reset(); //TODO make a more rich return value
	FBullCowCount SubmitGuess(FString);
	
private:
	//see constructor for values
	int32 MyCurrentTry;
	int32 MyMaxTries;
	FString MyHiddenWord; 

};