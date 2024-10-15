#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

int block = 512; // Size of one block

// File to recover data from a corrupted image
int main(int argc, char *argv[])
{
    // Accept a single command-line argument
    if (argc != 2)
    {
        printf("Usage: ./recover FILE\n");
        return 1;
    }

    // Open the memory card
    FILE *card = fopen(argv[1], "r");
    if (card == NULL)
    {
        printf("Could not open %s\n", argv[1]);
        return 2;
    }

    // Create a buffer for a block of data
    uint8_t buffer[block];
    bool found_jpg = false;
    int counter = 0;
    char filename[8];
    FILE *img = NULL;

    // While there's still data left to read from the memory card
    while (fread(buffer, 1, 512, card) == 512)
    {
        if (buffer[0] == 0xff && buffer[1] == 0xd8 && buffer[2] == 0xff &&
            (buffer[3] & 0xf0) == 0xe0)
        {
            found_jpg = true;
        }

        if (found_jpg == true)
        {
            if (counter != 0)
            {
                fclose(img);
            }

            sprintf(filename, "%03i.jpg", counter);
            img = fopen(filename, "w");
            fwrite(buffer, 1, 512, img);
            found_jpg = false;
            counter++;
        }

        else if (counter != 0)
        {
            fwrite(buffer, 1, 512, img);
        }
    }
    fclose(img);
    fclose(card);
}
