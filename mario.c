#include <cs50.h>
#include <stdio.h>

int main(void)
{
    // Get height of pyramid from user
    // h = height, c = column, r = row, s = space
    int h;
    int c;
    int r;
    int s;
    do
    {
        h = get_int("Height of pyramid? \n");
    }
    while (h < 1 || h > 8);

    // Print a column of hashes equal to h
    for (c = 0; c < h; c++)
    {
        // Print a row of spaces equal to h - c where h is the height of the pyramid and c is the current column indexed from top to bottom
        for (s = h - 1; s > c; s-- )
        {
            printf(" ");
        }

        // Print a row of hashes equal to c + 1 where n equals the current column indexed from top to bottom
        for (r = -1; r < c; r++)
        {
            printf("#");
        }

        // Print two spaces to form the middle of the pyramid
        printf("  ");
        for (r = -1; r <c; r++)
        {
            printf("#");
        }
        printf("\n");
    }



}
