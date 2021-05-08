#include <cs50.h>
#include <stdio.h>

int main(void)
{
    int height;
    do
    {
        height = get_int("Height: ");           // repomp the user 
    }
    while (height<1 | height > 8);
    
    for (int i = 0; i < height; i++) // for rows
    {
        for (int s = (height - 1) - i; s > 0; s--) // for spaces
        {
            printf(" ");
        }
        for (int h = 0; h <= i ; h++) // for hashes 
        {
            printf("#");
        }
        
        printf("  ");
        
        for (int hs = 0; hs <= i ; hs++) // for hashes 
        {
            printf("#");
        
        }
        printf("\n");
    }
    
    
}