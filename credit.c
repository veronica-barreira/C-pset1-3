#include <cs50.h>
#include <stdio.h>
#include <math.h>

int main(void)
{
    long cardNum;

    do
    {
        cardNum = get_long("Number: ");
    }
    while (false);

    // to know the numbers of digits

    int digits = (log10(cardNum) + 1);

    //printf("digits: %i\n", digits);

    //find 2 first digit

    int first = cardNum / pow(10, (digits - 2)) ;

    //printf("first: %i\n", first);


    // last number

    int evens = 0;
    int odds = 0;
    int lastNum = 0;
    int multi = 0;
    int count = digits;

    while (count > 0)
    {
        lastNum = cardNum % 10;     // last Number

        odds = odds + lastNum;   // digits NOT multiplied by 2

        cardNum = cardNum / 10;     // remove last number from CardNum

        count--;

        //printf("odds: %i\n", odds);

        lastNum = cardNum % 10;     // second last number
        cardNum = cardNum / 10;     // remove last number from cardNum

        evens = lastNum * 2; // digits multiplied by 2

        count--;

        if (evens >= 10)
        {
            int evenslast = evens % 10;
            evens = evens / 10;
            multi = multi + evens + evenslast; //sum of digists multiplied by 2
        }

        else
        {
            multi = multi + evens; //sum of digists multiplied by 2
        }

        //printf("muti: %i\n", multi);

    }


    int check = odds + multi;

    //printf("check: %i\n", check);

    check = check % 10;

    if (check == 0)
    {
        if (digits == 15 && (first == 37 || first == 34))
        {
            printf("AMEX\n");
        }

        else if (digits == 16 && first >= 51 && first <= 55)
        {
            printf("MASTERCARD\n");
        }

        else if (first >= 40 && first <= 49 && (digits == 13 || digits == 16))
        {
            printf("VISA\n");
        }


        else
        {
            printf("INVALID\n");
        }

    }

    else
    {
        printf("INVALID\n");
    }

}