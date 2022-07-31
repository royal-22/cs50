/*
source:  https://cs50.harvard.edu/x/2022/labs/2/
*/

#include <stdio.h>
#include <string.h>

// Points assigned to esach letter of the alphabet ACCORDING TO SCRABBLE GAME; her point 1 is for A or a, 3 for B or b
// and similarly point 10 for Z and z

int POINTS[] = {1, 3, 3, 2, 1, 4, 2, 4, 1, 8, 5, 1, 3, 1, 1, 3, 10, 1, 1, 1, 1, 4, 4, 8, 4, 10};

// Has ASCII arrays value assigned to small letter for alphabets
int smallLetters[] = {97, 98, 99, 100, 101, 102, 103, 104, 105, 106, 107, 108, 109, 110, 111, 112, 113, 114, 115, 116, 117, 118, 119, 120, 121, 122};

// Ascii values for capital letter of alphabets
int capitalLetters[] = {65, 66, 67, 68, 69, 70, 71, 72, 73, 74, 75, 76, 77, 78, 79, 80, 81, 82, 83, 84, 85, 86, 87, 88, 89, 90};
int temPoints[] = {};

int computeScore(char *str);

int main(void)
{
    char playerOne[20], playerTwo[20]; 

    printf("Player 1:  ");
    scanf("%s", &playerOne);

    printf("Player 2:  ");
    scanf("%s", &playerTwo);

    int pointsPlayerOne = computeScore(playerOne);
    int pointsPlayerTwo = computeScore(playerTwo);

    if (pointsPlayerOne > pointsPlayerTwo)
        printf("Player 1 wins :)");

    else if (pointsPlayerTwo > pointsPlayerOne)
        printf("Player 2 wins :)");

    else
        printf("Tie :))");

}

int computeScore(char *str)
{
    int score = 0;

    int len = strlen(str);
    printf("%i\n", len);

    for(int i=0; i<len; i++)
    {
        if(str[i] >= 65 && str[i] <= 90)
        {
            for (int j=0; j<sizeof(capitalLetters); j++)
            {
                if(str[i] == capitalLetters[j])
                {
                    temPoints[i] = POINTS[j];
                    score += temPoints[i];
                }
            }
        }

        else if(str[i] >= 97 && str[i] <= 122)
        {
            for (int k=0; k<sizeof(smallLetters); k++)
            {
                if(str[i] == smallLetters[k])
                {
                    temPoints[i] = POINTS[k];
                    score += temPoints[i];
                }
            }
        }

        else
            i+=1;
    }

    return score;
}
