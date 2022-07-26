#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main(void)
{
    char s[15];
    printf("Before:   ");
    scanf("%s", &s);

    for(int i=0, n = strlen(s); i<n; i++)
    {
        printf("%c", toupper(s[i]));
        /*if (s[i] >= 'a' && s[i] <= 'z') 
        {
            printf("%c", s[i] - 32);
        }*/
    }
}
