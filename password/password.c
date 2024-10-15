#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <string.h>

// Prototype for valid function
bool valid(string password);

// Program to check that a password has at least one lowercase letter, uppercase letter, number and symbol
int main(void)
{
    // Prompt the user for a password
    // If the user's input is invalid continue prompting until valid
    string password = get_string("Enter your password: ");
    if (valid(password))
    {
        printf("Your password is valid!\n");
    }
    else
    {
        printf("Your password needs at least one uppercase letter, lowercase letter, number and symbol\n");
    }
}

// Check that each requirement for the password is met
bool valid(string password)
{
    bool hasPunct;
    bool hasDigit;
    bool hasLower;
    bool hasUpper;

    for (int i = 0; i < strlen(password); i++)
    {
        if (ispunct(password[i]))
        {
            hasPunct = true;
        }
    }

    for (int i = 0; i <strlen(password); i++)
    {
        if (isdigit(password[i]))
        {
            hasDigit = true;
        }
    }

    for (int i = 0; i <strlen(password); i++)
    {
        if (islower(password[i]))
        {
            hasLower = true;
        }
    }

    for (int i = 0; i <strlen(password); i++)
    {
        if (isupper(password[i]))
        {
            hasUpper = true;
        }
    }

    if (hasPunct == true && hasDigit == true && hasLower == true && hasUpper == true)
    {
        return true;
    }
    return false;
}
