#include "helpers.h"
#include <math.h>

// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            if (image[i][j].rgbtRed != image[i][j].rgbtGreen ||  image[i][j].rgbtRed != image[i][j].rgbtBlue)
            {
                for (int k = 0; k < 3; k++)
                {
                    int average = round((image[i][j].rgbtRed + image[i][j].rgbtGreen + image[i][j].rgbtBlue) / 3);
                    image[i][j].rgbtRed = average;
                    image[i][j].rgbtGreen = average;
                    image[i][j].rgbtBlue = average;

                }
            }
            else if (image[i][j].rgbtRed == image[i][j].rgbtGreen || image[i][j].rgbtRed == image[i][j].rgbtBlue)
            {
                image[i][j].rgbtBlue = image[i][j].rgbtRed;
                image[i][j].rgbtGreen = image[i][j].rgbtRed;

            }
        }
    }
    return;
}

// Convert image to sepia
void sepia(int height, int width, RGBTRIPLE image[height][width])
{
    return;
}

// Reflect image horizontally
void reflect(int height, int width, RGBTRIPLE image[height][width])
{
    return;
}

// Blur image
void blur(int height, int width, RGBTRIPLE image[height][width])
{
    return;
}
