#include <cs50.h>
#include <stdio.h>

// Prototype for function
bool prime(int number);

// Program to generate all prime numbers in a range specified
// by the user
int main(void)
{

    // Prompt user for lower bound of range
    int min;
    do
    {
        min = get_int("Minimum: ");
    }
    while (min < 1);

    // Prompt user for upper bound of range
    int max;
    do
    {
        max = get_int("Maximum: ");
    }
    while (min >= max);

    // Print each prime number in the given range
    for (int i = min; i <= max; i++)
    {
        if (prime(i))
        {
            printf("%i\n", i);
        }
    }
}

// Function to determine if the argument passed is a prime number
bool prime(int number)
{
    int x;
    int y;
    for (x = 2; x < number; x++)
    {
        y = number % x;
        if (y == 0)
        {
            return false;
        }
    }
    if (number == 1)
    {
        return false;
    }
    return true;
}
