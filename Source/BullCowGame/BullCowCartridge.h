// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "LetterSet.h"
#include "Console/Cartridge.h"
#include "BullCowCartridge.generated.h"


struct FBullCowCount {
	int32 Bulls;
	int32 Cows;
};

UCLASS(ClassGroup=(Custom), meta=(BlueprintSpawnableComponent))
class BULLCOWGAME_API UBullCowCartridge : public UCartridge
{
	GENERATED_BODY()

	public:
		virtual void BeginPlay() override;
		virtual void OnInput(const FString& Input) override;
		void InitGame();
		void EndGame();
		void ProcessGuess(const FString& Guess);
		bool isIsogram(const FString& Guess);
		FBullCowCount getBullCowCount(const FString& Guess);

	private:
		FString HiddenWord;
		int32 Lives, WordIndex;
		bool bGameOver;
		LetterSet Set;
};
