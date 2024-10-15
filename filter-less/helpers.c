#include <math.h>

#include "helpers.h"

int capMax(int color);

// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            float average =
                round((image[i][j].rgbtRed + image[i][j].rgbtGreen + image[i][j].rgbtBlue) / 3.0);

            image[i][j].rgbtRed = average;
            image[i][j].rgbtGreen = average;
            image[i][j].rgbtBlue = average;
        }
    }
    return;
}

// Convert image to sepia
void sepia(int height, int width, RGBTRIPLE image[height][width])
{
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            int sepiaRed = capMax(round(.393 * image[i][j].rgbtRed + .769 * image[i][j].rgbtGreen +
                                        .189 * image[i][j].rgbtBlue));

            int sepiaGreen = capMax(round(.349 * image[i][j].rgbtRed + .686 * image[i][j].rgbtGreen +
                                          .168 * image[i][j].rgbtBlue));
                                          
            int sepiaBlue = capMax(round(.272 * image[i][j].rgbtRed + .534 * image[i][j].rgbtGreen +
                                         .131 * image[i][j].rgbtBlue));

            image[i][j].rgbtRed = sepiaRed;
            image[i][j].rgbtGreen = sepiaGreen;
            image[i][j].rgbtBlue = sepiaBlue;
        }
    }

    return;
}

int capMax(int color)
{
    if (color > 255)
    {
        return 255;
    }

    return color;
}

// Reflect image horizontally
void reflect(int height, int width, RGBTRIPLE image[height][width])
{
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < (width / 2); j++)
        {
            RGBTRIPLE buffer;
            buffer = image[i][j];
            image[i][j] = image[i][width - (j + 1)];
            image[i][width - (j + 1)] = buffer;
        }
    }
    return;
}

// Blur image
void blur(int height, int width, RGBTRIPLE image[height][width])
{
    RGBTRIPLE copy[height][width];
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            copy[i][j] = image[i][j];
        }
    }

    int sum_red;
    int sum_green;
    int sum_blue;
    float average_red;
    float average_green;
    float average_blue;

    int counter;

    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            sum_red = 0;
            sum_green = 0;
            sum_blue = 0;

            counter = 0;

            for (int k = -1; k < 2; k++)
            {
                for (int l = -1; l < 2; l++)
                {
                    if (i + k >= 0 && j + l >= 0 && i + k < height && j + l < width)
                    {
                        sum_red = sum_red + copy[i + k][j + l].rgbtRed;
                        sum_green = sum_green + copy[i + k][j + l].rgbtGreen;
                        sum_blue = sum_blue + copy[i + k][j + l].rgbtBlue;
                        counter++;
                    }
                }
            }
            average_red = round((float) sum_red / counter);
            average_green = round((float) sum_green / counter);
            average_blue = round((float) sum_blue / counter);

            image[i][j].rgbtRed = average_red;
            image[i][j].rgbtGreen = average_green;
            image[i][j].rgbtBlue = average_blue;
        }
    }
    return;
}
