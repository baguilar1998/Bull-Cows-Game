// Fill out your copyright notice in the Description page of Project Settings.
#include "BullCowCartridge.h"

void UBullCowCartridge::BeginPlay() // When the game starts
{
    Super::BeginPlay();
    PrintLine(TEXT("Welcome to the Bull Cows game!"));
    PrintLine(TEXT("Guess the 5 letter word!")); // Number might change for other words! Cannot be hard coded
    PrintLine(TEXT("Press enter to start..."));
    
    InitGame();

    // Prompt Player For Guess
}

void UBullCowCartridge::OnInput(const FString& Input) // When the player hits enter
{
    ClearScreen();

    // Checks whether the word the user inputted was the correct guess
    bool GuessIsCorrect = HiddenWord == Input;
    if (GuessIsCorrect) { 
        PrintLine(TEXT("You have guessed the right word!"));
    } else {
        bool LengthEquals = HiddenWord.Len() == Input.Len();
        if (!LengthEquals) {
            PrintLine(TEXT("The Hidden Word is 5 Characters long, try again!"));
        }
        PrintLine(TEXT("You have guessed the wrong word :("));
    }
    // Check if isogram
    // check right number of characters

    // remove life

    // check if lives > 0
    // if yes play again
    // if no show game over
    // prompt to play again
    // Check user input
    // play again or quit
}

void UBullCowCartridge::InitGame() {
    Lives = 5;
    HiddenWord = TEXT("kenji"); 
}