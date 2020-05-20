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
    bool LetterNotInRange = Letter < 'a' || Letter > 'z';
    if (LetterNotInRange)
        return;
    int32 LetterIndex = 'a' - Letter;
    Set[LetterIndex] = true;
}

bool LetterSet::ContainsLetter(char Letter) 
{
    bool LetterNotInRange = Letter < 'a' || Letter > 'z';
    if (LetterNotInRange)
        return false;
    int32 LetterIndex = 'a' - Letter;
    return Set[LetterIndex];
}

void LetterSet::ResetSet() 
{
    for (int32 Index = 0; Index < 26; Index++)
        Set[Index] = false;
}
