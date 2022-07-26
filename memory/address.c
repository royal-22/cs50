#include <stdio.h>

int main(void)
{
    char *s = "HI!"; 

    printf("%c\n", *s);
    printf("%c\n", *(s + 1));
    printf("%c\n", *(s + 2));
   
    int numbers[] = {4, 6, 8, 7, 2, 5, 0};
    printf("%i\n", *numbers);
}

