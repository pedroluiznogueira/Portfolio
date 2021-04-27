#include <stdio.h>
#include <cs50.h>

int main(void)
{
    int n;

    do
    {
        n = get_int("Qual a altura desejada ? ");
    }
    while (n <= 0 || n > 8);

    for (int i = 0; i < n; i++)
    {
        for (int j = n - 1; j > i; j--)
        {
            printf(" ");
        }
        for (int k = 0; k <= i; k++)
        {
            printf("#");
        }
        printf("  ");

        for (int l = 0; l <= i; l++)
        {
            printf("#");
        }

        printf("\n");
    }
}