#include "LetterSet.h"
LetterSet::LetterSet() 
{
    Set = new bool[26];
    ResetSet();
}

LetterSet::~LetterSet()
{
    delete Set;
}

void LetterSet::AddLetter(char Letter) 
{
    int LetterIndex = 'a' - Letter;
    Set[LetterIndex] = true;
}

bool LetterSet::ContainsLetter(char Letter) 
{
    int LetterIndex = 'a' - Letter;
    return Set[LetterIndex];
}

void LetterSet::ResetSet() 
{
    for (int Index = 0; Index < 26; Index++)
        Set[Index] = false;
}
