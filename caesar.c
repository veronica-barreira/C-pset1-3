#include <cs50.h>
#include <stdio.h>
#include <math.h>

#include <cs50.h>
#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[])
{
    int k = 0;

    if (argc != 2)
    {
        printf("Usage: ./caesar key\n");
        return 1;
    }

    else
    {
        for (int i = 0; argv[1][i] != '\0'; i++)
        {
            if (isdigit((unsigned char)argv[1][i]) != 0)     // TODO iterate over all argv to see if all are digits
            {
                k = atoi(argv[1]);
            }

            else
            {

                printf("Usage: ./caesar key\n");
                return 1;

            }
        }
    }

    string P = get_string("plaintext: ");

    printf("ciphertext: ");

    for (int j = 0; j < strlen(P); j++)
    {
        
        if (isalpha(P[j]) != 0)         // for alphabetic character
        {
            if (isupper(P[j]) != 0)     // if character is uppercase
            {
                printf("%c", (((P[j] - 65) + k) % 26) + 65);    // Cipher
            }

            else                    // if character is lowercase
            {
                printf("%c", (((P[j] - 97) + k) % 26) + 97);        // Cipher
            }
        }

        else        // for non alphabetic character
        {
            printf("%c", P[j]);
        }
    }

    printf("\n");
    return 0;

}

