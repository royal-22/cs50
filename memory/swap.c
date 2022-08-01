#include <stdio.h>

void swap(int *x, int *y);

int main(void)
{
    int x=1;
    int y=2;

    printf("x is %i, y is %i\n", x, y);

    swap(&x, &y); // pass an address to do the swap

    printf("x is %i, y is %i\n", x, y);
}

void swap(int *x, int *y)
{
    int tmp = *x;
    *x = *y;
    *y = tmp;
}
