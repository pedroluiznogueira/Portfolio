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
            int originalRed = image[i][j].rgbtRed;
            int originalBlue = image[i][j].rgbtBlue;
            int originalGreen = image[i][j].rgbtGreen;

            image[i][j].rgbtRed = cap(round(0.393 * originalRed + 0.769 * originalGreen + 0.189 * originalBlue));
            image[i][j].rgbtGreen = cap(round(0.349 * originalRed + 0.686 * originalGreen + 0.168 * originalBlue));
            image[i][j].rgbtBlue = cap(round(0.272 * originalRed + 0.534 * originalGreen + 0.131 * originalBlue));
        }

    }
    return;

}

void swap(int *a, int *b)
{
    int tmp = *a;
    *a = *b;
    *b = tmp;
}

// Reflect image horizontally
void reflect(int height, int width, RGBTRIPLE image[height][width])
{
    int k =  1;
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {

            int originalRed = image[i][j].rgbtRed;
            int originalBlue = image[i][j].rgbtBlue;
            int originalGreen = image[i][j].rgbtGreen;
            int swapRed = image[i][width - k].rgbtRed;
            int swapBlue = image[i][width - k].rgbtBlue;
            int swapGreen = image[i][width - k].rgbtGreen;

            swap(&originalRed, &swapRed);
            swap(&originalGreen, &swapGreen);
            swap(&originalBlue, &swapBlue);

            k = k + 1;
        }

    }
    return;
}

// Blur image
void blur(int height, int width, RGBTRIPLE image[height][width])
{
    return;
}
