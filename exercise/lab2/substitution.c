/*
https://cs50.harvard.edu/x/2022/psets/2/substitution/
*/


#include <stdio.h>
#include <stdbool.h>
#include <ctype.h>
#include <string.h>

// Has ASCII arrays value assigned to small letter for alphabets
int smallLetters[] = {97, 98, 99, 100, 101, 102, 103, 104, 105, 106, 107, 108, 109, 110, 111, 112, 113, 114, 115, 116, 117, 118, 119, 120, 121, 122};

// Ascii values for capital letter of alphabets
int capitalLetters[] = {65, 66, 67, 68, 69, 70, 71, 72, 73, 74, 75, 76, 77, 78, 79, 80, 81, 82, 83, 84, 85, 86, 87, 88, 89, 90};


bool validKey(char *key);
void substitution(char *text, char *key);


int main(int argc, char **argv)
{
    char *key = argv[1];

    for (int i=0; i < strlen(key); i++)
    {
        key[i] = tolower(key[i]);
    }

    printf("%s\n", key);

    if (argc == 2)
    {
        if(validKey(key))
        {
            char text[30];
            printf("Plain text:   ");
            scanf("%[^\n]%*c", &text);

            substitution(text, key);
        }

        else
            printf("Key must contain 26 characters\n");
    }

    else
        printf("Usage: ./substitution key\n");

}


bool validKey(char *key)
{
    int len=strlen(key);
    printf("%i\n", len);
    if (len != 26)
        return false;

    for (int i = 0; i < len; i++)
    {
        if (!isalpha(key[i]))
            return false;
        for (int j=i+1; j<len; j++)
        {
            if (key[i] == key[j])
                return false;
        }
    }
    return true;
}

void substitution(char *text, char *key)
{
    printf("HII\n");
}