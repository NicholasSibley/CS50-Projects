#include <cs50.h>
#include <stdio.h>
#include <string.h>

// Prototype for the replace function
string replace(string input);

// Program to replace vowels with numbers
int main(int argc, string argv[])
{
    // Output if an incorrect number of arguments is used
    if (argc != 2)
    {
        printf("Must include one and only one string\n");
        return 1;
    }

    string output = argv[1];

    printf("%s\n", replace(output));
}

// Finds each vowel and replaces it with an appropriate integer
string replace(string output)
{
    for (int i = 0; i < strlen(output); i++)
    {
        if (output[i] == 'a' || output[i] == 'A')
        {
            output[i] = '6';
        }

        else if (output[i] == 'e' || output[i] == 'E')
        {
            output[i] = '3';
        }

        else if (output[i] == 'i' || output[i] == 'I')
        {
            output[i] = '1';
        }

        else if (output[i] == 'o' || output[i] == 'O')
        {
            output[i] = '0';
        }
    }
    return output;
}



