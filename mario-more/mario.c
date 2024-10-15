#include <cs50.h>
#include <stdio.h>

// Print a pyramid similar to what is seen in Super Mario
// Should print two pyramids: one left aligned and one right aligned
int main(void)
{
    // Prompt user for pyramid height
    // h = height, r = row, c = column, s = space
    int h;
    int r;
    int c;
    int s;

    do
    {
        h = get_int("Height:");
    }
    while (h < 1 || h > 8);

    // Print right-aligned and left-aligned pyramid
    for (r = 0; r < h; r++)
    {
        for (s = h - 1; s > r; s--)
        {
            printf(" ");
        }
        printf("#");
        for (c = 0; c < r; c++)
        {
            printf("#");
        }
        printf("  ");
        for (c = 0; c <= r; c++)
        {
            printf("#");
        }
        printf("\n");
    }
}
