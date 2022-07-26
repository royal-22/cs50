#include <stdio.h>
#include <string.h>

int main(void)
{
    char s[6];
    char t[6];
    printf("S:  ");
    scanf("%s", &s);

    printf("T:  ");
    scanf("%s", &t);

    printf("%p\n", s);
    printf("%p\n", t);
}
