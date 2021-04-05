#include <cs50.h>
#include <stdio.h>

int main(void)
{
    float i;
    do
    {
        // Prompt user for the initial population
        i = get_float("Initial Population: \n");
    }
    while (i < 9);

    float j;
    do
    {
        // Prompt user for the final population
        j = get_float("Final Population: \n");
    }
    while (j < i);
    
    // Calculates the number of years that the population will take to reach the final size
    float z = 12 * (j - i) / i;
    
    if(z == 1)
    printf("Year: %.0f\n", z);
    else
    // Inform the user the number of years
    printf("Years: %.0f\n", z);
}