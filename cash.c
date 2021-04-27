#include <cs50.h>
#include <math.h>
#include <stdio.h>

int main(void)
{
    int coin_25, coin_10, coin_5, coin_1, cents, quantity_1, quantity_2, quantity_3, quantity_4, total_coins;
    float dolls;
    do
    {
        dolls = get_float("Change owed: ");
    }
    while (dolls < 0);
    cents = (int) round (100 * dolls);
    
    coin_25 = 25;
    coin_10 = 10;
    coin_5 = 5;
    coin_1 = 1;
    
    quantity_1 = floor(cents / coin_25);
    quantity_2 = floor((cents % coin_25) / coin_10);
    quantity_3 = floor(((cents % coin_25) % coin_10) / coin_5);
    quantity_4 = floor((((cents % coin_25) % coin_10) % coin_5) / coin_1);

    total_coins = quantity_1 + quantity_2 + quantity_3 + quantity_4;
    printf("%i\n", total_coins);
}