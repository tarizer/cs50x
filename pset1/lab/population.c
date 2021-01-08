#include <cs50.h>
#include <stdio.h>
#include <math.h>

int main(void)
{
    int population;
    int population_end;
    int years;

    population = 0;
    population_end = 0;
    years = 0;
    while (population < 9)
    {
        population = get_int("Starting population (No less than 9): ");
    }
    while (population_end < population)
    {
        population_end = get_int("Ending population: ");
    }
    while (population < population_end)
    {
        population += floor(population / 3) - floor(population / 4);
        years++;
    }
    printf("Years: %i\n", years);
}
