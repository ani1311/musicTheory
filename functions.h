#include<stdio.h>
#include<string.h>

//Total no of notes
const int noOfNotes = 12;

//List of notes
std::string notes[noOfNotes] = {"A ","A#","B ","C ","C#","D ","D#","E ","F ","F#","G ","G#"};

//Scale formulas
int majorScaleFormula[7] = {0,2,4,5,7,9,11};
int majorPentatonicScaleFormula[5] = {0,2,4,7,9};
int minorPentatonicScaleFormula[5] = {0,3,5,7,10};

//chord formulas

struct chord
{
    std::string name;
    int notes[8];
}

int maj[3] = {0,4,7};
int min[3] = {0,3,7};
int dim[3] = {0,3,6};
int maj7[4] = {0,4,7,11};
int min7[4] = {0,3,7,10};
int dom7[4] = {0,4,7,10};
int sus2[3] = {0,2,7};
int sus4[3] = {0,5,7};
int aug[3] = {0,4,8};


//no of frets
int noOfFrets = 30;
int noOfString = 6;

//tunings
std::string standardTuning[6] = {"E ","B ","G ","D ","A ","E "};

//Returns the index of a note in notes (string array)
int getPositionOfNote(std::string a);

//stores the notes of a scale/key in the variable s
void majorScale(std::string key,std::string s[]);
void majorPentatonic(std::string key,std::string s[]);
void minorPentatonic(std::string key,std::string s[]); 

//stores the notes of a chord of the note in s
void makeChord(std::string s[],int n,std::string chord);
    

//draws comlete fretboard
void drawFretBoard(std::string tuning[]);

// draws notes from notes to draw in the tuning of tuning[], n is the lenth of notes to draw
void drawNotesOnFret(std::string tuning[],std::string notesToDraw[],int no);

// draws notes in the given fret rannge
void drawNotesOnFret(std::string tuning[],std::string notesToDraw[],int no,int startFret,int endFret);
void printStringArray(std::string s[]);
void printCircleOfFifth();





























// function implimentation

void majorScale(std::string key,std::string s[]) 
{
    int first = getPositionOfNote(key);
    for(int i = 0 ; i < 7 ; i++)
    {
        s[i] = notes[(first + majorScaleFormula[i])%noOfNotes];
    }
}

void majorPentatonic(std::string key,std::string s[])
{
    int first = getPositionOfNote(key);
    for(int i = 0 ; i < 5 ; i++)
    {
        s[i] = notes[(first + majorPentatonicScaleFormula[i])%noOfNotes];
    }
}

void minorPentatonic(std::string key,std::string s[])
{
    int first = getPositionOfNote(key);
    for(int i = 0 ; i < 5 ; i++)
    {
        s[i] = notes[(first + minorPentatonicScaleFormula[i])%noOfNotes];
    }
}

void makeChord(std::string s[],int n,std::string chord)
{
    if(chord)
}

void printStringArray(std::string s[],int n)
{
    for(int i = 0; i < n ; i++)
    {
        printf("%s ",s[i].c_str());
    }
    printf("\n");
}

int getPositionOfNote(std::string a)
{
    for(int i = 0 ; i < noOfNotes ; i++)
    {
        if(notes[i] == a)
        {
            return i;
        }
    }
    return -1;
}

std::string getNoteAt(int fret,int string,std::string tuning[])
{
    int s = string - 1;
    int note = getPositionOfNote(tuning[s]);
    note = (note + fret)%noOfNotes;
    return notes[note];
}

void drawFretBoard(std::string tuning[])
{
    printf("    ");
    for(int i = 0 ; i < noOfFrets ; i++)
    {
        printf("|%2d   ",i);
    }
    printf("\n");
    for(int j = 0 ; j < noOfFrets ; j++)
    {
        printf("------");
    }
    printf("\n");

    for(int i = 0 ; i < noOfString ; i++)
    {
        int note = getPositionOfNote(tuning[i]);
        printf("%d   ",i);
        for(int j = 0 ; j < noOfFrets ; j++)
        {
            printf("|%2s   ",notes[(note + j)%noOfNotes].c_str());
        }
        printf("\n");
        for(int j = 0 ; j < noOfFrets ; j++)
        {
            printf("------");
        }
        printf("\n");
    }
}


void drawNotesOnFret(std::string tuning[],std::string notesToDraw[],int no)
{
    printf("    ");
    for(int i = 0 ; i < noOfFrets ; i++)
    {
        printf("|%2d   ",i);
    }
    printf("\n");
    for(int j = 0 ; j < noOfFrets ; j++)
    {
        printf("------");
    }
    printf("\n");

    for(int i = 0 ; i < noOfString ; i++)
    {
        int note = getPositionOfNote(tuning[i]);
        printf("%d   ",i);
        
        for(int j = 0 ; j < noOfFrets ; j++)
        {
            bool f1 = true;
            for(int p = 0 ; p < no ; p++)
            {
                if(notes[(note + j)%noOfNotes] == notesToDraw[p])
                {
                    printf("|%2s %2d",notes[(note + j)%noOfNotes].c_str(),p+1);
                    f1 = false;
                    break;
                }
            }
            if(f1)
            {
                printf("|     ");
            }
        }

        printf("\n");
        for(int j = 0 ; j < noOfFrets ; j++)
        {
            printf("------");
        }
        printf("\n");
    }
}

void drawNotesOnFret(std::string tuning[],std::string notesToDraw[],int no,int startFret,int endFret)
{
    printf("    ");
    for(int i = 0 ; i < noOfFrets ; i++)
    {
        printf("|%2d   ",i);
    }
    printf("\n");
    for(int j = 0 ; j < noOfFrets ; j++)
    {
        printf("------");
    }
    printf("\n");

    for(int i = 0 ; i < noOfString ; i++)
    {
        int note = getPositionOfNote(tuning[i]);
        printf("%d   ",i);
        
        for(int j = 0 ; j < noOfFrets ; j++)
        {
            bool f1 = true;
            if(j >= startFret && j <= endFret)
            {
                for(int p = 0 ; p < no ; p++)
                {
                    if(notes[(note + j)%noOfNotes] == notesToDraw[p])
                    {
                        printf("|%2s %2d",notes[(note + j)%noOfNotes].c_str(),p+1);
                        f1 = false;
                        break;
                    }
                }
            
                if(f1)
                {
                    printf("|     ");
                }
            }
            else
            {
                printf("|     ");
            }
        }

        printf("\n");
        for(int j = 0 ; j < noOfFrets ; j++)
        {
            printf("------");
        }
        printf("\n");
    }
}

void printCircleOfFifth(std::string s[])
{
    s[0] = "C ";
    int t = getPositionOfNote("C ");
    for(int i = 1 ; i < noOfNotes; i++)
    {
        t = (t + 7)%noOfNotes;
        s[i] = notes[t];
    }
    printf("\n\n\n");
    printf("            %2s\n",s[0].c_str());
    printf("       %2s        %2s\n\n",s[11].c_str(),s[1].c_str());
    printf("   %2s               %2s\n\n",s[10].c_str(),s[2].c_str());
    printf("%2s                     %2s\n\n",s[9].c_str(),s[3].c_str());
    printf("   %2s               %2s\n\n",s[8].c_str(),s[4].c_str());
    printf("       %2s        %2s\n",s[7].c_str(),s[5].c_str());
    printf("            %2s\n",s[6].c_str());
}
