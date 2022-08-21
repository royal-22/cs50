#include <stdio.h>
#include <string.h>
#include <stdbool.h>

// Max voters and candidates

#define MAX_VOTERS 100
#define MAX_CANDIDATES 9

int preferences[MAX_VOTERS][MAX_CANDIDATES];

// preferences = { {1, 2, 3, 0}, {0, 2, 3, 1}, {0, 2, 1, 3}} 
// voters are 3 | candidates are 4 and each number represents one candidate according to the array of candidates

typedef struct 
{
    char name[20];
    int votes;
    bool eliminated;
} candidate;

// array of candidates
candidate candidates[MAX_CANDIDATES];
// Numbers of voters and candidates
int voterCount;
int candidateCount;

//Function prototypes 
bool vote(int voter, int rank, char *name);
void tabulate(void);
bool printWinner(void);
int findMin(void);
bool isTie(int min);
void eliminate(int min);

int main(int argc, char **argv)
{
    if (argc < 2)
        {
        printf("Usage: runoff [candidate ...]\n");
        return 1;
        }
    
    candidateCount = argc -1;

    if (candidateCount > MAX_CANDIDATES)
        {
        printf("Maximun number of candidates is %i\n", MAX_CANDIDATES);
        return 2;
        }
    
    for(int i=0; i < candidateCount; i++)
    {
        strcpy(candidates[i].name, argv[i+1]);
        candidates[i].votes = 0;
        candidates[i].eliminated = false;
    }

    printf("Number of voters:  ");
    scanf("%i", &voterCount);

    if(voterCount > MAX_VOTERS)
        {    
        printf("Maximun number of voters is %i\n", MAX_VOTERS);
        return 3;
        }
    
    for (int i=0; i<voterCount; i++)
    {
        // Query for each rank
        // this loop sets rank for each voter, according to the order in which the user enters the candidate name
        for (int j=0; j<candidateCount; j++)
        {
            char name[12];
            printf("Rank %i:  ", j + 1);
            scanf("%s", &name);

            // Record vote, unless it's unvalid
            if(!vote(i, j, name))
            {
                printf("..%s..\n", name);
                printf("Invalid vote. \n");
                return 4;
            }
        }
        printf("\n");
    }
    

    // keep holding runoffs until winner exists
    while(true)
    {
        // calculate votes given remaining candidates
        tabulate();

        bool won = printWinner();
        if (won)
            break;
        
        // eliminate last-place candidates
        int min = findMin();
        bool tie = isTie(min);

        // If tie, everyone wins
        if (tie)
        {
            for(int i=0; i<candidateCount; i++)
            {
                if (!candidates[i].eliminated)
                {
                    printf("%s\n", candidates[i].name);
                }
            }
            break;
        }
        //eliminate anyone with minimun number of votes
        eliminate(min);

        // reset vote counts back to zero
        for (int i=0; i<candidateCount; i++)
        {
            candidates[i].votes = 0;
        }
    }
    return 0;
}

bool vote(int voter, int rank, char *name)
{
    for(int i=0; i<candidateCount; i++)
    {
        if (strcmp(candidates[i].name, name) == 0)
        {
            preferences[voter][rank] = i;
            
            /*printf("voter: %d\n", voter);
            printf("rank: %d\n", rank);*/
            return true;
        }
    }
    return false;
}

void tabulate(void)
{
    int num;
    for(int i=0; i<voterCount; i++)
    {
        for(int j=0; j<candidateCount; j++)
        {
            num = preferences[i][j];
            if (!candidates[num].eliminated) // candidates[num].eliminated == false
            {
                candidates[num].votes += 1;
                break;
            }
        }
    }
}

bool printWinner(void)
{
    for(int i=0; i<candidateCount; i++)
    {
        if (candidates[i].votes > voterCount/2)
        {
            printf("Winner %s\n", candidates[i].name);
            return true;
        }
    }
    return false;
}

int findMin(void)
{
    int min = 100;

    for (int i=0; i<candidateCount; i++)
    {
        if (candidates[i].votes < min || candidates[i].eliminated == false)
        {
            min = candidates[i].votes;
        }
    }
    return min;
}

bool isTie(int min)
{
    for (int i=0; i<candidateCount; i++)
    {
        if (candidates[i].votes != min || candidates[i].eliminated == false)
        {
            return false;
        }
    }
    return true;
}

void eliminate(int min)
{
    for (int i=0; i<candidateCount; i++)
    {
        if (candidates[i].votes == min)
        {
            candidates[i].eliminated = true;
        }
    }
    return;
}