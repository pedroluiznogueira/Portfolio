#include <cs50.h>
#include <math.h>
#include <stdio.h>

int main(void)
{
    int a, b, c, d, cents, sum_1, sum_2, sum_3, sum_4, total_points;
    float dolares;
    do
    {
        dolares = get_float("Quantidade em dolares: ");
    }
    while (dolares < 0);
    cents = (int) round (100 * dolares);
    
    a = 25;
    b = 10;
    c = 5;
    d = 1;
    
    sum_1 = floor(cents / a);
    sum_2 = floor((cents % a) / b);
    sum_3 = floor(((cents % a) % b) / c);
    sum_4 = floor((((cents % a) % b) % c) / d);

    total_points = sum_1 + sum_2 + sum_3 + sum_4;
    printf("%i\n", total_points);
}