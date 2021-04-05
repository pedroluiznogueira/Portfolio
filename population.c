#include <cs50.h>
#include <stdio.h>

int main(void)
{
    int i;
    do
    {
        // Prompt user for the initial population
        i = get_int("Initial Population: \n");
    }
    while (i < 9);

    int j;
    do
    {
        // Prompt user for the final population
        j = get_int("Final Population: \n");
    }
    while (j < i);
    
    // Calculates the number of years that the population will take to reach the final size
    int z = 12 * (j - i) / i;
    
    // Inform the user the number of years
    printf("Years: %i\n", z);
}