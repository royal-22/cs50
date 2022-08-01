#include <stdio.h>

int main(void)
{
    int n; 
    do
    {
        printf("Width:  ");
        scanf("%d", &n);
    }
    while (n < 1);

    for (int i = 1; i <= n; i++)
    {
        for (int space=0; space < height - row - 1; space++)
        {
            printf(" ");
        }

        for(int j=0; j<=row; j++)
        {

        }
        printf("\n");
    }
}
