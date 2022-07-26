#include <stdio.h>

int main(void)
{
    const int MINE = 2;
    int points;
    printf("How many points have you lost? ");
    scanf("%d", &points);

    if (points < MINE)
    {
        printf("You lost fewer points than me.");
    }

    else if (points > MINE)
    {
        printf("You lost more points than me. ");
    }
    else
    {
        printf("You lost the same number of points than me.");
    }

}
