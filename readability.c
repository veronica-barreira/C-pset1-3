#include <cs50.h>
#include <stdio.h>
#include <math.h>
#include <string.h>
#include <ctype.h>

int count_letters(string text, int lenght);
int count_words(string text, int lenght);
int count_sentences(string text, int lenght);

int main(void)
{
    string text = get_string("Text: "); // get input from user
    int n = strlen(text);               // get string lent
    
    float L = (float) count_letters(text, n) / count_words(text, n) * 100;  // average number of letters per 100 words
    float S = (float) count_sentences(text, n) / count_words(text, n) * 100; // average number of sentences per words
    
    int index = round(0.0588 * L - 0.296 * S - 15.8);      // index for grade
    printf("%i", index);
    
    if (index < 1)
    {
        printf("Before Grade 1\n");
    }
    
    else if (index >= 1 && index <= 15)
    {
        printf("Grade %i\n", index);
    
    }
    
    else
    {
        printf("Grade 16+\n");
    }
}

int count_letters(string text, int lenght)  // function count letters
{
    int letters = 0;
    for (int i = 0; i < lenght; i++) 
    {
        if (isalpha(text[i]))
        {
            letters++;
        }
    }
    
    //printf("letters: %i\n", letters);
    return letters;
}
    
int count_words(string text, int lenght)    // function count words
{
    int words = 1;
    for (int i = 0; i < lenght; i++)
    {
        if (text[i] == ' ' && text[i - 1] != ' ')
        {
            words++;
        }
    }
    
    return words;
    //printf("words: %i\n", words);
}

int count_sentences(string text, int lenght) //function count sentences
{
    int sentences = 0;
    for (int i = 0; i < lenght; i++)
    {
        if (text[i] == '.' || text[i] == '!' || text[i] == '?')
        {
            sentences++;
        }
    }
    return sentences;
}



