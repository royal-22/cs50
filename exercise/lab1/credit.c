#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <math.h>
#include <stdlib.h>

bool validCard(long long creditCard);
bool luhnAlgo(long long creditCard);
void CreditCardBrand(long long creditCard);
int findLength(long long num);

int main(void)
{
    long long digits;
    do
    {
        printf("Insert a valid card:   ");
        scanf("%lld", &digits);
    } while (digits<1);
    
    if (validCard(digits))
    {
        CreditCardBrand(digits);
    }
    else
    {
        printf("INVALID ALERT!!!");
    }
}

bool validCard(long long creditCard)
{ 
    int length = findLength(creditCard);
    printf("%i\n", length);
    if ((length == 13 || length == 16 || length == 15) && luhnAlgo(creditCard))
    {
        return true;
    }
    else
        return false;
}

int findLength(long long num)
{
    int len; 
    for (len=0; num!=0; num/=10, len++);
    return len;
}



bool luhnAlgo(long long creditCard)
{
    int sum = 0;
    for (int i = 0; creditCard != 0; i++, creditCard/=10)
    {
        if (i % 2 == 0)
            sum += creditCard%10;
        else
        {
            int digit = 2 * (creditCard % 10);
            sum += digit / 10 + digit % 10;
        }
    }
    
    return (sum % 10) == 0;

    /*int i=1; 
    int currentNum, sum = 0, add;

    while(creditCard >= 0)
    {
        currentNum = creditCard%10;
        if (i%2 == 0)
        {
            add = currentNum*2;
            if (add>=10)
                sum += 1 + add%10;
            else
                sum += add;
        } 

        else
            sum += currentNum;
        
        creditCard/=10;
        i++;
    }

    printf("%i", sum);
    return true;*/
}

void CreditCardBrand(long long creditCard)
{
    if ((creditCard >= 34e13 && creditCard < 35e13) || (creditCard >= 37e13 && creditCard < 38e13))
    {
        printf("AMEX\n");
    }
    else if (creditCard >= 51e14 && creditCard < 56e14)
    {
        printf("MASTERCARD\n");
    }

    else if ((creditCard >= 4e12 && creditCard < 5e12) || (creditCard >= 4e15 && creditCard < 5e15))
    {
        printf("VISA\n");
    }
    else
        printf("INVALID\n");
    
}
