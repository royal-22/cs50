/* 
source: https://cs50.harvard.edu/x/2022/psets/2/readability/
https://github.com/cs50/labs/tree/2019/fall/credit 
*/

#include <stdio.h>
#include <string.h>
#include <math.h>

int countLetters(char *text);
int countWords(char *text);
int countSentence(char *text);

int main(void)
{
    char text[1000];
    printf("Text:  ");
    scanf("%[^\n]%*c", &text);

    int letters = countLetters(text);
    int words = countWords(text);
    int sentence = countSentence(text);

    printf("%i\n", letters);
    
    printf("%i\n", sentence);
    
    printf("%i\n", words);

    float L = ((float)letters / (float)words) * 100;
    float S = ((float)sentence / (float)words) * 100; 

    /*printf("%i\n", letters/words);
    printf("%f\n", L);
    printf("%f\n", S); */

    float index = 0.0588 * L - 0.296 * S - 15.8;

    int grade = round(index);


    if (grade >= 1 && grade < 16)
        printf("Grade %i\n", grade);

    else if(grade >= 16)
        printf("Grade 16+");
    
    else
        printf("Before Grade 1");

}


int countLetters(char *text)
{
    int count = 0;
    int len = strlen(text);

    for (int i = 0; i < len; i++)
    {
        if((text[i] >= 65 && text[i] <= 90) || (text[i] >= 97 && text[i] <= 122))
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

int countSentence(char *text)
{
    int count = 0;
    int len = strlen(text);

    for (int i = 0; i < len; i++)
    {
        if ((text[i] == 46) || (text[i] == 63) || (text[i] == 33))
            count += 1;        
    }
    
    return count;
}
