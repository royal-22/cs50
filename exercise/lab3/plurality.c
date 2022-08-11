#include <stdio.h>
#include <string.h>
#include <stdbool.h>

#define MAX 9

typedef struct 
{
    char name[20];
    int votes;
} 
candidate;

candidate candidates[MAX];

int candidateCount;

bool vote(char *name, int count);
void printWinner(void);

int main(int argc, char **argv)
{
    // check for invalid usage
    if (argc < 2)
    {
        printf("Usage: plurality [candidate ...]\n");
        return 1;
    }

    candidateCount = argc - 1;
    if (candidateCount > MAX)
    {
        printf("Maximum number of candidates is %i\n", MAX);
        return 2;
    }

    for (int i = 0; i < candidateCount; i++)
    {
        //candidates[i].name = argv[i + 1];
        strcpy(candidates[i].name, argv[i+1]);
        candidates[i].votes = 0;

    }
    
    int voterCount;
    printf("Number of voters:  ");
    scanf("%i", &voterCount);

    for (int i=0; i < voterCount; i++)
    {
        char name[10];
        printf("Vote:  ");
        scanf("%s", &name);

        // Check for invalid vote
        if (!vote(name, candidateCount))
        {
            printf("Invalid vote\n");
        }
    }
    
    //Display winner of election
    printWinner();
}

bool vote(char *name, int count)
{
    for (int i = 0; i < count; i++)
    {
        if (strcmp(candidates[i].name, name) == 0)
        {
            candidates[i].votes += 1;
            return true;
        }
    }

    return false;
}

void printWinner(void)
{
    int max = 0;

    for (int i = 0; i < candidateCount; i++)
    {
        if (max < candidates[i].votes)
        {
            max = candidates[i].votes;
        }
    }

    for(int j = 0; j < candidateCount; j++)
    {
        if (candidates[j].votes == max)
        {
            printf("%s\n", candidates[j].name);
        }
    }
    
    return;
}
