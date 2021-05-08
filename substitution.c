#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <ctype.h>

int main(int argc, string argv[])
{
    string k;
    if (argc != 2)      //  must contain one key - one arg
    {
        printf("Usage: ./substitution key");
        return 1;
    }
    
    else
    {
        if (strlen(argv[1]) != 26)             // must countain 26 characters, not less not more
        {
            printf("Key must contain 26 characters.");
            return 1;
        }
        
        else
        {
            for (int i = 0; argv[1][i] != '\0'; i++)           
            {
                if (isalpha(argv[1][i]) == 0)                    // must contain only alphabetical char
                {
                    printf("Key must only contain alphabetic characters.");
                    return 1;
                }
                
                else                     // must contain each letter exactly once
                {
                    for (int j = 1; j < i; j++)
                    {
                        if (argv[1][i] == argv[1][j])
                        {
                            printf("Key must not contain repeated characters.");
                            return 1;
                        }
                        
                        else            // key  accepted
                        {
                            k = argv[1];
                            
                        }
                    }
                    
                }
            }
            
        }
    }
        
    string PL = get_string("plaintext: ");
    printf("ciphertext: ");
        
// TODO ciphertext substitution:
        
    for (int j = 0; j < strlen(PL); j++)
    {
        if (isalpha(PL[j]) != 0)                // for alphabetic characters
        {
            if (isupper(PL[j]) != 0)           // If letter uppercase
            {
                int q = PL[j] - 65;
                char ch = k[q];

                if (isupper(k[q]) != 0)         // if key is uppercase
                {
                    printf("%c", ch); 
                }
                
                else                            // if key is lowercase
                {
                    printf("%c", toupper(ch));
                }
            }
            
            else                                // if letter is lowercase
            {
                int q = PL[j] - 97;
                char ch = k[q];
                if (isupper(k[q]) == 0)             // if key lowercase
                {
                    printf("%c", ch);
                }
                else                                // if key uppercase
                {
                    printf("%c", tolower(ch));
                }
            }
        }


        else                                       // for no alphabetic characters - it works well
        {
            printf("%c", PL[j]);
        }
        
    }
    
    printf("\n");
    return 0;
    
}