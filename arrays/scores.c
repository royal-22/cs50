#include <stdio.h>

int main(void)
{
    int n;
    printf("How many scores?   ");
    scanf("%d", &n);

    int scores[n];
    for(int i=0; i<n; i++)
    { 
        printf("\nScores:  ");
        scanf("%d", &scores[i]);
    } 
    
    int average=0;
    for (int j=0; j<n; j++)
    {
        average += scores[j];
    }

    printf("Average: %d\n", average/n);
}
