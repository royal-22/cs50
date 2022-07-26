#include <stdio.h>
int stringLength(char s[]);

int main(void)
{
    char name[15];
    printf("Name:  ");
    scanf("%s", &name);
    int length = stringLength(name);
    printf("%i", length);
}

int stringLength(char s[])
{
    int i = 0;
    while (s[i] != '\0')
    {
        i++;
    }
    return i;
}
