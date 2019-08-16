


void majorChord(std::string note,std::string s[]);
void minorChord(std::string note,std::string s[]);

void majorChord(std::string note,std::string s[])
{
    int first = getPositionOfNote(note);
    s[0] = notes[first];
    s[1] = notes[first + majorScaleFormula[0] + majorScaleFormula[1]];
    s[2] = notes[first + majorScaleFormula[0] + majorScaleFormula[1] + majorScaleFormula[2] + majorScaleFormula[3]];
}

void minorChord(std::string note,std::string s[])
{
    int first = getPositionOfNote(note);
    s[0] = notes[first];
    s[1] = notes[(first + majorScaleFormula[0] + majorScaleFormula[1] - 1)%noOfNotes];
    s[2] = notes[(first + majorScaleFormula[0] + majorScaleFormula[1] + majorScaleFormula[2] + majorScaleFormula[3])%noOfNotes];
}


