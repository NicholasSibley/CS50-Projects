#include <cs50.h>
#include <ctype.h>
#include <math.h>
#include <stdio.h>
#include <string.h>

// Program to calculate the approximate grade level needed to comprehend a given string of text
// The grade level is caluclated by the Coleman-Liau index.  index = 0.0588 * L - 0.296 * S - 15.8
int main(void)
{

    // Prompt the user for a string of text
    string text = get_string("What is your text?\n");

    int letters = 0;
    int words = 1;
    int sentences = 0;

    // Calculate the number of letters, words, and sentences in the given text
    for (int i = 0; i < strlen(text); i++)
    {

        // Calculate the number of letters in the given text
        if (isalpha(text[i]))
        {
            letters++;
        }

        // Calculate the number of words in the given text
        else if (text[i] == ' ')
        {
            words++;
        }

        // Calculate the number of sentences in the given text
        else if (text[i] == '.' || text[i] == '!' || text[i] == '?')
        {
            sentences++;
        }
    }


    float L = letters / (float)words * 100;
    float S = sentences / (float)words * 100;

    int index = round(0.0588 * L - 0.296 * S - 15.8);

    // Result if the grade leve is earlier than grade 1
    if (index < 1)
    {
        printf("Before Grade 1\n");
        return 0;
    }

    // Result if the grade level is greater than 16 (meaning graduate school level)
    if (index > 16)
    {
        printf("Grade 16+\n");
        return 0;
    }

    // All other results
    else
    {
        printf("Grade %i\n", index);
        return 0;
    }
}
