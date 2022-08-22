#include <stdio.h>
#include <stdbool.h>

// Max number of candidates
#define MAX 9

// preferences[i][j] is number of voters who prefer i over j
int preferences[MAX][MAX];

// locked[i][j] means i is locked in over j
bool locked[MAX][MAX];

// each pair has a winner, loser
typedef struct
{
    int winner;
    int loser;
}
pair;

// Array of candidates
char *candidates[MAX];
pair pairs[MAX * (MAX - 1) / 2];

int pairCount;
int candidateCount;

// Function prototypes
bool vote(int rank, char *name, int ranks[]);
void recordPreferences(int rank[]);
void addPairs(void);
void sortPairs(void);
void lockPairs(void);
void printWinner(void);

int main(int argc, char **argv)
{
    // check for invalid usage
    if (argc < 2)
    {
        printf("Usage: tideman [candidate ...]\n");
        return 1;
    }

    // Populate array of candidates
    candidateCount = argc - 1;
    if (candidateCount > MAX)
    {
        printf("Maximum number of candidates is %i\n", MAX);
        return 2;
    }
    for(int i=0; i<candidateCount; i++)
    {
        candidates[i] = argv[i+1];
    }

    // Clear graph of locked in pairs

    for(int i=0; i<candidateCount; i++)
    {
        for (int j=0; j < candidateCount; j++)
        {
            locked[i][j] = false;
        }
    }

    pairCount = 0;
    int voterCount;
    printf("Number of voters:  ");
    scanf("%i", &voterCount);

    // Query for votes
    for(int i=0; i<voterCount; i++)
    {
        // ranks[i] is voter's ith preference
        int ranks[candidateCount];

        for (int j=0; j<candidateCount; j++)
        {
            char name[15];
            printf("Rank %i: ", j+1);
            scanf("%s", &name);

            if (!vote(j, name, ranks))
            {
                printf("Invalid vote.\n");
                return 3;
            }

        }
        recordPreferences(ranks);

        printf("\n");
    }

    addPairs();
    sortPairs();
    lockPairs();
    printWinner();
    return 0;
}

// Update ranks given a new vote

bool vote(int rank, char *name, int ranks[])
{
    // TODO
    for (int i=0; i<candidateCount; i++)
    {
        if(strcmp(candidates[i], name) == 0)
        {
            ranks[rank] = i;
            return true;  
        }
    }
    return false;
}

// Update preferences given one voter's ranks
void recordPreferences(int ranks[])
{
    for(int i=0; i<candidateCount-2; i++)
    {
        for (int j=i+1; j<candidateCount; j++)
        {
            preferences[ranks[i]][ranks[j]] += 1;
        }
    }
    return;
}

// Record pairs of candidates where one id preferred over the other
void addPairs(void)
{
    for(int i=0; i<candidateCount-1; i++)
    {
        for (int j=i+1; j<candidateCount; j++)
        {
            if(preferences[i][j] > preferences[j][i])
            {
                pairs[pairCount].winner = i;
                pairs[pairCount].loser = j;
                pairCount ++;
            }

            else if (preferences[j][i] >preferences[i][j])
            {
                pairs[pairCount].winner = j;
                pairs[pairCount].loser = i;
                pairCount ++;
            }
        }
    }
    return;
}

// Sort pairs in decreasing order by strength of victory
void sortPairs(void)
{
    pair temp;
    for (int i=0; i<pairCount-1; i++)
    {
        for(int j=0; j<pairCount - i - 1; j++)
        {
            if ((pairs[j].winner - pairs[j].loser) < (pairs[j+1].winner - pairs[j+1].loser))
            {
                temp.winner = pairs[j].winner;
                temp.loser = pairs[j].winner;

                pairs[j].winner = pairs[j+1].winner;
                pairs[j].loser = pairs[j+1].loser;
                
                pairs[j+1].winner = temp.winner;
                pairs[j+1].loser = temp.loser;
            }
        }
    }
}

// Lock pairs into candidate graph in order, without creating cycles
void lockPairs(void)
{
    return;
}

// Print the winner of the election
void printWinner(void)
{
    return;
}
