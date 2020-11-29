#include<stdio.h>
#include<string>

struct chord
{
    std::string name;
    int notes[9][2];
};

//Returns the index of a note in notes (string array)
int getPositionOfNote(std::string a);

//stores the notes of a scale/key in the variable s
void majorScale(std::string key,std::string s[]);

//stores the notes of a chord of the note in s
void makeChord(std::string s[],std::string key,std::string chord);

std::string getNoteAt(int fret,int string,std::string tuning[]);
std::string getNoteAt(int fret,int string);

//draws comlete fretboard
void drawFretBoard();
void drawFretBoard(std::string tuning[]);

// draws notes from notes to draw in the tuning of tuning[], n is the lenth of notes to draw
void drawNotesOnFret(std::string notesToDraw[],int no);
void drawNotesOnFret(std::string notesToDraw[],int no,std::string tuning[]);
void drawNotesOnFret(std::string notesToDraw[],int no,int startFret,int endFret);
void drawNotesOnFret(std::string notesToDraw[],int no,int startFret,int endFret,std::string tuning[]);

// draws notes in the given fret rannge
void printStringArray(std::string s[]);
void printCircleOfFifth(std::string s[]);

int getNoOfNotes(int a[][2]);


