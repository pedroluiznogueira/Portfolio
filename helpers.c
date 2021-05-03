#include "helpers.h"
#include <math.h>

// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            if (image[i][j].rgbtRed != image[i][j].rgbtGreen ||  image[i][j].rgbtRed != image[i][j].rgbtBlue || image[i][j].rgbtGreen != image[i][j].rgbtBlue)
            {
                for (int k = 0; k < 3; k++)
                {
                    int average = round((image[i][j].rgbtRed + image[i][j].rgbtGreen + image[i][j].rgbtBlue) / 3.0);
                    image[i][j].rgbtRed = average;
                    image[i][j].rgbtGreen = average;
                    image[i][j].rgbtBlue = average;

                }
            }
        }
    }
    return;
}

int cap(int value)
{
    return value > 255 ? 255 : value;
}


// Convert image to sepia
void sepia(int height, int width, RGBTRIPLE image[height][width])
{
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            for (int k = 0; k < 3; k++)
            {
                image[i][j].rgbtRed = round(cap(.393 * image[i][j].rgbtRed + .769 * image[i][j].rgbtGreen + .189 * image[i][j].rgbtBlue));
                image[i][j].rgbtGreen = round(cap(.349 * image[i][j].rgbtRed + .686 * image[i][j].rgbtGreen + .168 * image[i][j].rgbtBlue));
                image[i][j].rgbtBlue = round(cap(.272 * image[i][j].rgbtRed + .534 * image[i][j].rgbtGreen + .131 * image[i][j].rgbtBlue));
            }
        }

    }
    return;


    // Caso o valor passe de 255 quero colocar o valor em 255







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
