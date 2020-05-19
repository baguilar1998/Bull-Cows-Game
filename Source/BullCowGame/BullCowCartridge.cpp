// Fill out your copyright notice in the Description page of Project Settings.
#include "BullCowCartridge.h"

void UBullCowCartridge::BeginPlay()
{
    Super::BeginPlay();
    InitGame();
}

void UBullCowCartridge::OnInput(const FString& Input) // When the player hits enter
{
    if(bGameOver) {
        ClearScreen();
        InitGame();
    } else {
        ProcessGuess(Input);
    }

}

void UBullCowCartridge::InitGame() 
{
    HiddenWord = TEXT("kenji");
    Lives = HiddenWord.Len(); 
    bGameOver = false;
    PrintLine(TEXT("Welcome to the Bull Cows game!"));
    PrintLine(TEXT("Guess the %i letter word!"), HiddenWord.Len()); 
    PrintLine(TEXT("You have %i Lives"), Lives);
    PrintLine(TEXT("Press enter to start..."));
}

void UBullCowCartridge::EndGame() 
{
    bGameOver = true;
    PrintLine(TEXT("Press Enter To Continue..."));
}

void UBullCowCartridge::ProcessGuess(const FString& Guess) 
{
    bool bGuessIsCorrect = Guess == HiddenWord;
    if (bGuessIsCorrect) { 
        PrintLine(TEXT("You have guessed the right word!"));
        EndGame();
    } else if(!isIsogram(Guess)){
        PrintLine(TEXT("No repeating letters, guess again!"));
        return;
    } else {
        Lives -= 1;
        bool bLengthEquals = HiddenWord.Len() == Guess.Len(), bNoLivesLeft = Lives == 0;
        if(bNoLivesLeft) {
            PrintLine(TEXT("You have lost the game."));
            EndGame();
            return;
        }
        PrintLine(TEXT("You have %i Lives Remaining"), Lives);
        if (!bLengthEquals) {
            PrintLine(TEXT("The Hidden Word is %i Characters long, try again!"), HiddenWord.Len());
        } else {
            PrintLine(TEXT("You have guessed the wrong word!"));
        }
    }
}

bool UBullCowCartridge::isIsogram(const FString& Guess) const 
{
    bool *LetterExists  = new bool[26];
    for (int index = 0; index < 26; index++)
        LetterExists[index] = false;
    for (int index = 0; index < Guess.Len(); index++) {
        int lIndex = Guess[index] - 'a';
        if (LetterExists[lIndex]){
            delete LetterExists;
            return false;
        }
        LetterExists[lIndex] = true;
    }
    delete LetterExists;
    return true;
}