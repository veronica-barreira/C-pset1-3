#include <cs50.h>
#include <stdio.h>
#include <math.h>

int main(void)
{
    float dollars;
    do
    {
        dollars = get_float("Change owed: ");
    }
    while (dollars < 0);
    
    int cents = round(dollars * 100);
    
   // printf("%i\n",cents);
    
    int coins = 0;
    int c = cents;
    
    while (c > 0)
    {
        if (c >= 25)
        {
            coins++;
            c = (c - 25);
        }
        
        else if (c < 25 && c >= 10)
        {
            coins++;
            c = (c - 10);
        }
        
        else if (c >= 5 && c < 10)
        {
            coins++;
            c = (c - 5);
        }
        
        else
        {
            coins++;
            c = (c - 1);
        }

    }
    
    
    printf("%i\n",coins);
    
}