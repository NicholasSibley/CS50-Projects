#include <cs50.h>
#include <stdio.h>

// Print a pyrmid similar to what is seen in Super Mario

int main(void)
{
    // Prompt user for height > 0
    // h = height, r = row, c = column, s = space
    int h;
    int r;
    int c;
    int s;
    do
    {
        h = get_int("Height:\n");
    }
    while (h < 1 || h > 8);

    // Print right-aligned pyramid
    for (r = 0; r < h; r++)
    {
        for (s = h - 1; s > r; s--)
        {
            printf(" ");
        }
        for (c = 0; c <= r; c++)
        {
            printf("#");
        }
        printf("\n");
    }
}
