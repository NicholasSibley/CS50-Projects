#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Program to encrypt messages using "Caesar's Cipher"
// Caesar's cipher works by "rotating" each letter by x positions
int main(int argc, string argv[])
{

    // Output if an incorrect number of command line arguments are used
    if (argc != 2)
    {
        printf("Usage: ./caesar key\n");
        return 1;
    }

    // Output if the argument is not an integer
    for (int i = 0; i < strlen(argv[1]); i++)
    {
        if (!isdigit(argv[1][i]))
        {
            printf("Usage: ./caesar key\n");
            return 1;
        }
    }

    int k = atoi(argv[1]);

    // Prompts the user for some plaintext
    string plaintext = get_string("Plaintext: \n");
    printf("Ciphertext: ");

    // Encrypts the plaintext into the ciphertext and prints it out
    for (int j = 0; j < strlen(plaintext); j++)
    {
        if (isupper(plaintext[j]))
        {
            printf("%c", (plaintext[j] - 65 + k) % 26 + 65);
        }

        else if (islower(plaintext[j]))
        {
            printf("%c", (plaintext[j] - 97 + k) % 26 + 97);
        }

        else
        {
            printf("%c", plaintext[j]);
        }
    }

    printf("\n");
}
