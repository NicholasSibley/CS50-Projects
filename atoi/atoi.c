#include <cs50.h>
#include <ctype.h>
#include <math.h>
#include <stdio.h>
#include <string.h>

// Function prototype
int convert(string input);

// Program to convert a string to an int
int main(void)
{

    // Promtp the user for input
    string input = get_string("Enter a positive integer: ");

    // Check if the input is valid
    for (int i = 0, n = strlen(input); i < n; i++)
    {
        if (!isdigit(input[i]))
        {
            printf("Invalid Input!\n");
            return 1;
        }
    }

    // Pass the user input to the convert function and print the result
    printf("%i\n", convert(input));
}

// Convert the user's string to int
int convert(string input)
{
  int length = strlen(input);
  int last_number = input[length - 1] - 48;

  if (length == 0)
  {
    return 0;
  }

  input[length - 1] = '\0';
  return last_number + 10 * convert(input);
}
