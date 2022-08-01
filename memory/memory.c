#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    int *x = malloc(3*sizeof(int));

    x[0] = 22; 
    x[1] = 56;
    x[2] = 54;

    free(x);
}
