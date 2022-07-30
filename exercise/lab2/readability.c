/* 
source: https://cs50.harvard.edu/x/2022/psets/2/readability/
https://github.com/cs50/labs/tree/2019/fall/credit 
*/

#include <stdio.h>
#include <string.h>

int countLetters(char *text);
int countWords(char *text);
int countSentence(char *text);

int main(void)
{
    char text[100];
    printf("Text:  ");
    scanf("%s", &text);

    int letters = countLetters(text);
    int words = countWords(text);
    int sentence = countSentence(text);

    int L = letters / words * 100;
    int S = sentence / words * 100; 

    float index = 0.0588 * L - 0.296 * S - 15.8;

}


int countLetters(char *text)
{
    int count = 0;
    int len = strlen(text);

    for (int i = 0; i < len; i++)
    {
        if((text[i] >= 48 && text[i] <= 57) || (text[i] >= 65 && text[i] <= 90))
        {
            count += 1; 
        }
    }

    return count;    
}

int countWords(char *text)
{
    int count = 1;
    int len = strlen(text); 

    for (int i = 0; i < len; i++)
    {
        if (text[i] == 32)
        {
            count += 1;
        }
        
    }
    return count;
    
}
