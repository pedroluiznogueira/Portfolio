#include <cs50.h>
#include <math.h>
#include <stdio.h>

int main(void)
{
    int start_size, end_size, population, sum;
    // TODO: Prompt for start size
    do
    {
        start_size = get_int("Start Size: ");
    }
    while (start_size < 9);
    // TODO: Prompt for end size
    do
    {
        end_size = get_int("End Size: ");
    }
    while (end_size < start_size);
    // TODO: Calculate number of years until we reach threshold
    population = start_size;
    sum = 0;

    for (int i = 0; population < end_size; i++)
    {
        population = floor(population + (population / 3) - (population / 4));
        sum = sum + 1;
    }
    // TODO: Print number of years
    printf("Years: %i\n", sum);
}