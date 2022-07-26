#include <stdio.h>

float discount(float price, int percentage);

int main(void)
{
    float regular; 
    float sale; 
    float percent;

    printf("Regular price:  ");
    scanf("%f", &regular);

    printf("Percent Off: ");
    scanf("%f", &percent);

    sale = discount(regular, percent);
    printf("Final price: %.2f", sale);
}

float discount(float price, int percentage)
{
    return price * (100 - percentage) / 100;
}
