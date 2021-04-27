#include <cs50.h>
#include <math.h>
#include <stdio.h>

int main(void)
{
    int cents;
    float dolares;
    do
    {
        dolares = get_float("Quantidade em dolares: ");
    }
    while (dolares < 0);
    cents = (int) round (100 * dolares);
    
    int sum = 0;

    int a = 41 % 25;
    if (a < 25)
    {
        sum = sum + 1;
    }
    
    int b = 41 % 10;
    if (b < 10)
    {
        sum = sum + 1;
    }
    
    int c = 41 % 5;
    if (c < 5)
    {
        sum = sum + 1;
    }
    
    int d = 41 % 1;
    if (d < 1)
    {
        sum = sum + 1;
    }

    printf("%i\n", sum);
}