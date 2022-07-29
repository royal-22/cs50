#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <stdlib.h>


void reverse(int key, char *phrase);
bool validInput(char *str);

int main(int argc, char **argv)
{
    char *digits = argv[1];

    if (argc == 2 && validInput(digits))
    {
        char text[20];

        printf("Plaintext:   ");
        scanf("%[^\n]%*c", &text);

        int key = atoi(digits);

        printf("%s\n", text);
        reverse(key, text);
    }
    else   
    {
        printf("Usage: ./caesar key");
    }
}

bool validInput(char *str)
{
    int len = strlen(str);

    printf("%i\n", len);

    for(int i=0; i < len; i++)
    {
        if (str[i] >= 48 && str[i] <= 57)
        {
            continue;
        }
        else
            return false;
    }
    return true;
}


void reverse(int key, char *phrase)
{
    char crypt[20];
    int len = strlen(phrase);

    for(int i=0; i<len; i++)
    {
        if (phrase[i] >= 65 && phrase[i] <= 90)
        {
            char letter = phrase[i] + key; 

            if (letter > 90)
            {
                letter -= 90;
                letter += 65; 
                crypt[i] = letter;
            }

            else
                crypt[i] = letter;
        }

        else if (phrase[i] >= 97 && phrase[i] <= 122)
        {
            char letter = phrase[i] + key; 

            if (letter > 122)
            {
                letter -= 122;
                letter += 97; 
                crypt[i] = letter;
            }

            else
                crypt[i] = letter;
        }
        
        else
            crypt[i] = phrase[i];
    }

    printf("%s", crypt);
}
