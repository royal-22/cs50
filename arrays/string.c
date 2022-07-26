#include <stdio.h>
#include <string.h>

int main(void)
{
    char s[15];
    int length = strlen(s);
    printf("Input:  ");
    scanf("%s", &s);

    for (int i=0; i<length; i++)
    {
        printf("%c", s[i]);
    }
    printf("\n");
}
