#include <cs50.h>
#include <stdio.h>

int main(void)
{
    int n;

    do
    {
        n = get_int("Height: ");
    }
    while (n <= 0 || n > 8);
    
    if (n >= 1)
    {
        for (int a = 0; a < n - 1; a++)
        {
            printf(" ");
        }
    
        for (int i = 0; i < n - (n - 1); i++)
        {
            printf("#");
        }
        printf("\n");
    }
    //
    if (n >= 2)
    {    
        for (int b = 0; b < n - 2; b++)
        {
            printf(" ");
        }
    
        for (int j = 0; j < n - (n - 2); j++)
        {
            printf("#");
        }
        printf("\n");
    }
    //
    if (n >= 3)
    {    
        for (int c = 0; c < n - 3; c++)
        {
            printf(" ");
        }

        for (int k = 0; k < n - (n - 3); k++)
        {
            printf("#");
        }
        printf("\n");
    }
    //
    if (n >= 4)
    {
        for (int d = 0; d < n - 4; d++)
        {
            printf(" ");
        }

        for (int l = 0; l < n - (n - 4); l++)
        {
            printf("#");
        }
        printf("\n");
    }
    //
    if (n >= 5)
    {
        for (int e = 0; e < n - 5; e++)
        {
            printf(" ");
        }

        for (int m = 0; m < n - (n - 5); m++)
        {
            printf("#");
        }
        printf("\n");
    }
    //
    if (n >= 6)
    {
        for (int f = 0; f < n - 6; f++)
        {
            printf(" ");
        }
    
        for (int o = 0; o < n - (n - 6); o++)
        {
            printf("#");
        }
        printf("\n");
    }
    //
    if (n >= 7)
    {
        for (int g = 0; g < n - 7; g++)
        {
            printf(" ");
        }
    
        for (int p = 0; p < n - (n - 7); p++)
        {
            printf("#");
        }
        printf("\n");
    }
    //
    if (n >= 8)
    {
        for (int q = 0; q < n; q++)
        {
            printf("#");
        }
        printf("\n");
    }
    return (0);
}