#include <cs50.h>
#include <math.h>
#include <stdio.h>

int main(void)
{
    float dollars;
    int cents;
    // Asks user for the number of change owed
    do
    {
        dollars = get_float("Change owed: ");
        cents = round(dollars * 100);
    }
    
    // Create a condition to reject negative numbers
    while (cents <= 0);
    
    // Calculates the smallest number to be delivered
    
    int count_25 = (cents / 25);
    int count_10 = (cents % 25) / 10;
    int count_5 = ((cents % 25) % 10)  / 5;
    int count_1 = (((cents % 25) % 10) % 5) / 1;
    
    // Prints the result in the terminal
    
    printf("%i\n", count_25 + count_10 + count_5 + count_1);
}