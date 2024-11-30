#include "helpers.h"
#include <math.h>
#include <stdio.h>
#include <stdlib.h>

// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            int avg = round((image[i][j].rgbtRed + image[i][j].rgbtGreen + image[i][j].rgbtBlue) / 3.0);
            image[i][j].rgbtRed = avg;
            image[i][j].rgbtGreen = avg;
            image[i][j].rgbtBlue = avg;
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
            int sepiaRed = round((0.393 * image[i][j].rgbtRed) + (0.769 * image[i][j].rgbtGreen) + (0.189 * image[i][j].rgbtBlue));
            int sepiaGreen =
                round((0.349 * image[i][j].rgbtRed) + (0.686 * image[i][j].rgbtGreen) + (0.168 * image[i][j].rgbtBlue));
            int sepiaBlue = round((0.272 * image[i][j].rgbtRed) + (0.534 * image[i][j].rgbtGreen) + (0.131 * image[i][j].rgbtBlue));
            if (sepiaRed > 255)
            {
                sepiaRed = 255;
            }
            if (sepiaGreen > 255)
            {
                sepiaGreen = 255;
            }
            if (sepiaBlue > 255)
            {
                sepiaBlue = 255;
            }
            image[i][j].rgbtRed = sepiaRed;
            image[i][j].rgbtGreen = sepiaGreen;
            image[i][j].rgbtBlue = sepiaBlue;
        }
    }

    return;
}

// Reflect image horizontally
void reflect(int height, int width, RGBTRIPLE image[height][width])
{
    RGBTRIPLE(*image2)[width] = calloc(height, width * sizeof(RGBTRIPLE));
    for (int x = 0; x < height; x++)
    {

        for (int k = 0; k < width; k++)
        {
            image2[x][k] = image[x][width - 1 - k];
        }

        for (int k = 0; k < width; k++)
        {
            image[x][k] = image2[x][k];
        }
    }
    return;
}

// Blur image
void blur(int height, int width, RGBTRIPLE image[height][width])
{
    RGBTRIPLE(*image2)[width] = calloc(height, width * sizeof(RGBTRIPLE));
    for (int x = 0; x < height; x++)
    {

        for (int k = 0; k < width; k++)
        {
            image2[x][k] = image[x][k];
        }
    }
    for (int x = 0; x < height; x++)
    {

        // define stuff

        for (int k = 0; k < width; k++)
        {
            if ((x == 0) && (k == 0))
            {
                image[x][k].rgbtRed = round(
                    ((image2[x][k].rgbtRed + image2[x][k + 1].rgbtRed + image2[x + 1][k].rgbtRed + image2[x + 1][k + 1].rgbtRed)) /
                    4.0);
                image[x][k].rgbtGreen = round(((image2[x][k].rgbtGreen) + (image2[x][k + 1].rgbtGreen) +
                                               (image2[x + 1][k].rgbtGreen) + (image2[x + 1][k + 1].rgbtGreen)) /
                                              4.0);
                image[x][k].rgbtBlue = round(((image2[x][k].rgbtBlue) + (image2[x][k + 1].rgbtBlue) + (image2[x + 1][k].rgbtBlue) +
                                              (image2[x + 1][k + 1].rgbtBlue)) /
                                             4.0);
            }
            else if ((x == 0) && (k == width - 1))
            {
                image[x][k].rgbtRed = round(((image2[x][k].rgbtRed) + (image2[x][k - 1].rgbtRed) + (image2[x + 1][k].rgbtRed) +
                                             (image2[x + 1][k - 1].rgbtRed)) /
                                            4.0);
                image[x][k].rgbtGreen = round(((image2[x][k].rgbtGreen) + (image2[x][k - 1].rgbtGreen) +
                                               (image2[x + 1][k].rgbtGreen) + (image2[x + 1][k - 1].rgbtGreen)) /
                                              4.0);
                image[x][k].rgbtBlue = round(((image2[x][k].rgbtBlue) + (image2[x][k - 1].rgbtBlue) + (image2[x + 1][k].rgbtBlue) +
                                              (image2[x + 1][k - 1].rgbtBlue)) /
                                             4.0);
            }
            else if ((x == height - 1) && (k == width - 1)) // correct
            {
                image[x][k].rgbtRed = round(((image2[x][k].rgbtRed) + (image2[x][k - 1].rgbtRed) + (image2[x - 1][k].rgbtRed) +
                                             (image2[x - 1][k - 1].rgbtRed)) /
                                            4.0);
                image[x][k].rgbtGreen = round(((image2[x][k].rgbtGreen) + (image2[x][k - 1].rgbtGreen) +
                                               (image2[x - 1][k].rgbtGreen) + (image2[x - 1][k - 1].rgbtGreen)) /
                                              4.0);
                image[x][k].rgbtBlue = round(((image2[x][k].rgbtBlue) + (image2[x][k - 1].rgbtBlue) + (image2[x - 1][k].rgbtBlue) +
                                              (image2[x - 1][k - 1].rgbtBlue)) /
                                             4.0);
            }
            else if ((x == height - 1) && (k == 0)) // correct
            {
                image[x][k].rgbtRed = round(((image2[x][k].rgbtRed) + (image2[x][k + 1].rgbtRed) + (image2[x - 1][k].rgbtRed) +
                                             (image2[x - 1][k + 1].rgbtRed)) /
                                            4.0);
                image[x][k].rgbtGreen = round(((image2[x][k].rgbtGreen) + (image2[x][k + 1].rgbtGreen) +
                                               (image2[x - 1][k].rgbtGreen) + (image2[x - 1][k + 1].rgbtGreen)) /
                                              4.0);
                image[x][k].rgbtBlue = round(((image2[x][k].rgbtBlue) + (image2[x][k + 1].rgbtBlue) + (image2[x - 1][k].rgbtBlue) +
                                              (image2[x - 1][k + 1].rgbtBlue)) /
                                             4.0);
            }
            else if ((x == 0) && (k != 0))
            {
                image[x][k].rgbtRed =
                    round(((image2[x][k - 1].rgbtRed) + (image2[x][k].rgbtRed) + (image2[x][k + 1].rgbtRed) +
                           (image2[x + 1][k - 1].rgbtRed) + (image2[x + 1][k].rgbtRed) + (image2[x + 1][k + 1].rgbtRed)) /
                          6.0);
                image[x][k].rgbtGreen =
                    round(((image2[x][k - 1].rgbtGreen) + (image2[x][k].rgbtGreen) + (image2[x][k + 1].rgbtGreen) +
                           (image2[x + 1][k - 1].rgbtGreen) + (image2[x + 1][k].rgbtGreen) + (image2[x + 1][k + 1].rgbtGreen)) /
                          6.0);
                image[x][k].rgbtBlue =
                    round(((image2[x][k - 1].rgbtBlue) + (image2[x][k].rgbtBlue) + (image2[x][k + 1].rgbtBlue) +
                           (image2[x + 1][k - 1].rgbtBlue) + (image2[x + 1][k].rgbtBlue) + (image2[x + 1][k + 1].rgbtBlue)) /
                          6.0);
            }
            else if (x == height - 1) // correct
            {
                image[x][k].rgbtRed =
                    round(((image2[x][k - 1].rgbtRed) + (image2[x][k].rgbtRed) + (image2[x][k + 1].rgbtRed) +
                           (image2[x - 1][k - 1].rgbtRed) + (image2[x - 1][k].rgbtRed) + (image2[x - 1][k + 1].rgbtRed)) /
                          6.0);
                image[x][k].rgbtGreen =
                    round(((image2[x][k - 1].rgbtGreen) + (image2[x][k].rgbtGreen) + (image2[x][k + 1].rgbtGreen) +
                           (image2[x - 1][k - 1].rgbtGreen) + (image2[x - 1][k].rgbtGreen) + (image2[x - 1][k + 1].rgbtGreen)) /
                          6.0);
                image[x][k].rgbtBlue =
                    round(((image2[x][k - 1].rgbtBlue) + (image2[x][k].rgbtBlue) + (image2[x][k + 1].rgbtBlue) +
                           (image2[x - 1][k - 1].rgbtBlue) + (image2[x - 1][k].rgbtBlue) + (image2[x - 1][k + 1].rgbtBlue)) /
                          6.0);
            }
            else if (k == 0)
            {
                image[x][k].rgbtRed =
                    round(((image2[x - 1][k].rgbtRed) + (image2[x][k].rgbtRed) + (image2[x + 1][k].rgbtRed) +
                           (image2[x - 1][k + 1].rgbtRed) + (image2[x][k + 1].rgbtRed) + (image2[x + 1][k + 1].rgbtRed)) /
                          6.0);
                image[x][k].rgbtGreen =
                    round(((image2[x - 1][k].rgbtGreen) + (image2[x][k].rgbtGreen) + (image2[x + 1][k].rgbtGreen) +
                           (image2[x - 1][k + 1].rgbtGreen) + (image2[x][k + 1].rgbtGreen) + (image2[x + 1][k + 1].rgbtGreen)) /
                          6.0);
                image[x][k].rgbtBlue =
                    round(((image2[x - 1][k].rgbtBlue) + (image2[x][k].rgbtBlue) + (image2[x + 1][k].rgbtBlue) +
                           (image2[x - 1][k + 1].rgbtBlue) + (image2[x][k + 1].rgbtBlue) + (image2[x + 1][k + 1].rgbtBlue)) /
                          6.0);
            }
            else if (k == width - 1)
            {
                image[x][k].rgbtRed =
                    round(((image2[x - 1][k].rgbtRed) + (image2[x][k].rgbtRed) + (image2[x + 1][k].rgbtRed) +
                           (image2[x - 1][k - 1].rgbtRed) + (image2[x][k - 1].rgbtRed) + (image2[x + 1][k - 1].rgbtRed)) /
                          6.0);
                image[x][k].rgbtGreen =
                    round(((image2[x - 1][k].rgbtGreen) + (image2[x][k].rgbtGreen) + (image2[x + 1][k].rgbtGreen) +
                           (image2[x - 1][k - 1].rgbtGreen) + (image2[x][k - 1].rgbtGreen) + (image2[x + 1][k - 1].rgbtGreen)) /
                          6.0);
                image[x][k].rgbtBlue =
                    round(((image2[x - 1][k].rgbtBlue) + (image2[x][k].rgbtBlue) + (image2[x + 1][k].rgbtBlue) +
                           (image2[x - 1][k - 1].rgbtBlue) + (image2[x][k - 1].rgbtBlue) + (image2[x + 1][k - 1].rgbtBlue)) /
                          6.0);
            }
            else
            {
                image[x][k].rgbtRed =
                    round(((image2[x - 1][k - 1].rgbtRed) + (image2[x - 1][k].rgbtRed) + (image2[x - 1][k + 1].rgbtRed) +
                           (image2[x][k - 1].rgbtRed) + (image2[x][k].rgbtRed) + (image2[x][k + 1].rgbtRed) +
                           (image2[x + 1][k - 1].rgbtRed) + (image2[x + 1][k].rgbtRed) + (image2[x + 1][k + 1].rgbtRed)) /
                          9.0);
                image[x][k].rgbtGreen =
                    round(((image2[x - 1][k - 1].rgbtGreen) + (image2[x - 1][k].rgbtGreen) + (image2[x - 1][k + 1].rgbtGreen) +
                           (image2[x][k - 1].rgbtGreen) + (image2[x][k].rgbtGreen) + (image2[x][k + 1].rgbtGreen) +
                           (image2[x + 1][k - 1].rgbtGreen) + (image2[x + 1][k].rgbtGreen) + (image2[x + 1][k + 1].rgbtGreen)) /
                          9.0);
                image[x][k].rgbtBlue =
                    round(((image2[x - 1][k - 1].rgbtBlue) + (image2[x - 1][k].rgbtBlue) + (image2[x - 1][k + 1].rgbtBlue) +
                           (image2[x][k - 1].rgbtBlue) + (image2[x][k].rgbtBlue) + (image2[x][k + 1].rgbtBlue) +
                           (image2[x + 1][k - 1].rgbtBlue) + (image2[x + 1][k].rgbtBlue) + (image2[x + 1][k + 1].rgbtBlue)) /
                          9.0);
            }
        }
    }
    return;
}
