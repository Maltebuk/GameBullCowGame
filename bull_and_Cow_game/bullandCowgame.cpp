/*
This is the executable that makes use of the bull cow class 
THis acts as a view  in a  MVC pattern and is responsible for all 
user interactions
*/
// bullandCowgame.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <string>
#include "FBullCowGame.h"

using FText = std::string; 
using int32 = int;


void PrintIntro();
void PlayGame();
FText GetGuess();
bool AskToPlayAgain();

FBullCowGame BCGame; //instantiate a new game 


//the entry point for our application
int main()
{
	
	bool bPlayAgain = false;
	do 
	{
		PrintIntro();
		PlayGame();
		bPlayAgain = AskToPlayAgain();
	}
	while(bPlayAgain); 
	
    return 0;
}




//introduce the game
void PrintIntro()
{
	
	
	std::cout << "Welcome to bulls and cows game." << std::endl;
	std::cout << "Can you guess the " << BCGame.GetHiddenWordLength();
	std::cout << " letter isogram I am thinking of? \n\n";
	return;
}
void PlayGame()
{
	BCGame.Reset();
	int32 MaxTries = BCGame.GetMaxTries();
	
	//loop for the number of turns
	
	for (int32 count = 1; count <= MaxTries; count++)//TODO CHange from a for to a while once we can validate tries 
	{
		FText Guess = GetGuess();
		// Print out the guess

		EGuessStatus Status = BCGame.CheckGuessValidity(Guess);

 		FBullCowCount BullCowCount = BCGame.SubmitGuess(Guess);
		//print number of bulls and cows 
		std::cout << "Bulls =  " << BullCowCount.Bulls;
		std::cout << " Cows = " << BullCowCount.Cows <<std::endl;
		std::cout << "\n\n";
		
	}

	//TODO add a game summary
}

//get a guess from the player
FText GetGuess() //TODO change to GetValidGuess
{
	int32 CurrentTry = BCGame.GetCurrentTry();
	std::cout << "Try " << CurrentTry <<": Enter your guess : ";
	
	FText Guess = " ";
	std::cout << "";
	std::getline(std::cin, Guess);
	
	// repeat the guess to the player 
	
	return Guess;
}

bool AskToPlayAgain()
{
	std::cout << "Do you want to play again? (y/n) \n";
	FText Response = " ";
	std::getline(std::cin, Response);
	return (Response[0] == 'y' || Response[0] == 'Y');
	
}
