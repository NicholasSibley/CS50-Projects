#include <cs50.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void)
{
    int input1 = get_int("Input 1:\n");
    int input2 = get_int("Input 2:\n");

    int x = 0;
    int y = 0;

    int sum = 0;

    if (input1 > input2)
    {
        x = input2;
        y = input1;
    }

    else
    {
        x = input1;
        y = input2;
    }

    for (int i = x; i < y; i++)
    {
        if ((i >= 7 && i % 7 == 2) || (i >= 7 && i % 7 == 3))
        {
            printf("%i\n", i);
        }
    }

    return 0;
}
