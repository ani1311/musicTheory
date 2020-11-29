#include "functions.h"
 

//Constants

//Total no of notes
const int noOfNotes = 12;

//List of notes
std::string notes[noOfNotes] = {"A ","A#","B ","C ","C#","D ","D#","E ","F ","F#","G ","G#"};

//Scale formulas
int majorScaleFormula[8] = {0,2,4,5,7,9,11,-1};


//chord formulas
const int noOfChords = 8;



chord chords[]=  {
    {.name = "maj" ,  .notes  =  {{1,0},{3,0},{5,0},{-1,0}}},
    {.name = "min" ,  .notes  =  {{1,0},{3,-1},{5,0},{-1,0}}},
    {.name = "dim" ,  .notes  =  {{1,0},{3,-1},{5,-1},{-1,0}}},
    {.name = "sus2",  .notes  =  {{1,0},{2,0},{5,0},{-1,0}}},
    {.name = "sus4",  .notes  =  {{1,0},{4,0},{5,0},{-1,0}}},
    {.name = "aug" ,  .notes  =  {{1,0},{3,0},{5,1},{-1,0}}},
    {.name = "maj7",  .notes  =  {{1,0},{3,0},{5,0},{7,0},{-1,0}}},
    {.name = "min7",  .notes  =  {{1,0},{3,-1},{5,0},{7,-1},{-1,0}}},
};



//no of frets
const int noOfFrets = 30;
const int noOfString = 6;

//tunings
std::string standardTuning[6] = {"E ","B ","G ","D ","A ","E "};


// function implimentation

void majorScale(std::string key,std::string s[]) 
{
    int first = getPositionOfNote(key);
    for(int i = 0 ; i < 7 ; i++)
    {
        s[i] = notes[(first + majorScaleFormula[i])%noOfNotes];
    }
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

void makeChord(std::string s[],std::string key,std::string chord)
{
    int chordID = -1;
    for(int i = 0 ; i < noOfChords ; i++)
    {
        if(chords[i].name == chord)
        {
            chordID = i;
            break;
        }
    }
    if(chordID != -1)
    {
        std::string majScale[12];
        majorScale(key,majScale); 
        int no = getNoOfNotes(chords[chordID].notes);
        for(int i = 0 ; i < no ; i++)
        {
            s[i] = majScale[(chords[chordID].notes[i][0] - 1 + chords[chordID].notes[i][1])%noOfNotes];
        }
    }
}


std::string getNoteAt(int fret,int string,std::string tuning[])
{
    int s = string - 1;
    int note = getPositionOfNote(tuning[s]);
    note = (note + fret)%noOfNotes;
    return notes[note];
}

std::string getNoteAt(int fret,int string)
{
    int s = string - 1;
    int note = getPositionOfNote(standardTuning[s]);
    note = (note + fret)%noOfNotes;
    return notes[note];
}

void drawFretBoard()
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
        int note = getPositionOfNote(standardTuning[i]);
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

void drawFretBoard(std::string tuning[] = standardTuning)
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

void drawNotesOnFret(std::string notesToDraw[],int no)
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
        int note = getPositionOfNote(standardTuning[i]);
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

void drawNotesOnFret(std::string notesToDraw[],int no,std::string tuning[])
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


void drawNotesOnFret(std::string notesToDraw[],int no,int startFret,int endFret)
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
        int note = getPositionOfNote(standardTuning[i]);
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

void drawNotesOnFret(std::string notesToDraw[],int no,int startFret,int endFret,std::string tuning[])
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





int getNoOfNotes(int a[][2])
{
    int i = 0;
    while(1)
    {
        if(a[i][0] == -1)
        {
            return i;
        }
        i = i + 1;
    }
}
