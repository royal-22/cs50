#include <stdio.h>

int main(int argc, char **argv)
{
    if (argc != 2)
    {
        printf("Wrong, bye");
        return 1;
    }
    printf("%s\n", argv[1]);
    return 0;  
}
