// Fill out your copyright notice in the Description page of Project Settings.
#include "BullCowCartridge.h"
#include "HiddenWordList.h"
#include "LetterSet.h"


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
    WordIndex = FMath::RandRange(0,Words.Num()-1);
    HiddenWord = Words[WordIndex];
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
        FBullCowCount Count = getBullCowCount(Guess);
        PrintLine(TEXT("You have %i Bulls and %i Cows"), Count.Bulls,Count.Cows);
        if (!bLengthEquals) {
            PrintLine(TEXT("The Hidden Word is %i Characters long, try again!"), HiddenWord.Len());
        } else {
            PrintLine(TEXT("You have guessed the wrong word!"));
        }
    }
}

bool UBullCowCartridge::isIsogram(const FString& Guess)
{
    LetterSet *Set = new LetterSet();
    bool bHasRepeatingLetter = false;
    for (int32 Index = 0; Index < Guess.Len(); Index++) {
        char Letter = Guess[Index];
        bHasRepeatingLetter = Set->ContainsLetter(Letter);
        if (bHasRepeatingLetter){
            break;
        }
        Set->AddLetter(Letter);
    }
    delete Set;
    Set=NULL;
    return !bHasRepeatingLetter;
}

FBullCowCount UBullCowCartridge::getBullCowCount(const FString& Guess) 
{
    LetterSet *Set = new LetterSet();
    FBullCowCount Count = {0,0};
    for (int32 Index = 0; Index < HiddenWord.Len();Index++) {
        char Letter = HiddenWord[Index];
        Set->AddLetter(Letter);
    }
    
    for (int32 Index = 0; Index < Guess.Len() && Index < HiddenWord.Len(); Index++) {
        char Letter = Guess[Index];
        bool bSameLetter = Letter == HiddenWord[Index];
        if(bSameLetter) {
            Count.Bulls++;
        } else if (Set->ContainsLetter(Letter)) {
            Count.Cows++;
        }
    }

    delete Set;
    Set = NULL;
    return Count;
}
