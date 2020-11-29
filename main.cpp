#include<iostream>
#include<string>
#include "functions.h"

int main()
{
    std::string s[4];
    makeChord(s,"C ","maj7");
    drawNotesOnFret(s,4);

    //clearence
    printf("\n\n\n\n\n");
    return 0;
}
