#include <stdio.h>

int main(void)
{
    int n; 

    do
    {
        
        printf("Value for n: ");
        scanf("%i", &n);

    } while (n<1 || n>9);
    

    for (int i = 0; i < n; i++)
    {
        for (int space = 0; space < n - i - 1; space++) // right justified
        {
            printf(" ");   
        }

        for (int j = 0; j <= i; j++)  // # printin' 
        {
            printf("#");
        }

        printf("  ");  // space in the middle of the pyramid

        for (int k = 0; k <= i; k++) // right side of the pyramid, left justified
        {
            printf("#");
        }
        
        
        printf("\n");
    }
    
}
