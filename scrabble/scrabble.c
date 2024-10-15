#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <string.h>

// Array that holds the point value of each letter ordered alphabetically with
// 'a' at the first index and 'z' at the last index
int points[] = {1, 3, 3, 2, 1, 4, 2, 4, 1, 8, 5, 1, 3, 1, 1, 3, 10, 1, 1, 1, 1, 4, 4, 8, 4, 10};

// Prototype for the compute_score function
int compute_score(string word);

// Program that determines the winner of a Scabble-like game
int main(void)
{

    // Prompt players for their chosen words
    string word1 = get_string("Player 1, what is your word? \n");
    string word2 = get_string("Player 2, what is your word? \n");

    // Pass the chosen words to the compute score function
    int score1 = compute_score(word1);
    int score2 = compute_score(word2);

    // Result if Player 1 has a higher score
    if (score1 > score2)
    {
        printf("Player 1 Wins!\n");
    }

    // Result if Player 2 has the higher score
    else if (score1 < score2)
    {
        printf("Player 2 Wins!\n");
    }

    // Else it must be a tie
    else
    {
        printf("Tie!\n");
    }
}

// Function to calculate the score of a word
int compute_score(string word)
{
    int score = 0;
    for (int i = 0; i < strlen(word); i++)
    {
        if (isupper(word[i]))
        {
            score = score + points[word[i] - 'A'];
        }
        if (islower(word[i]))
        {
            score = score + points[word[i] - 'a'];
        }
    }
    return score;
}
