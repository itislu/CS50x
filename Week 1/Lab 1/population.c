#include <cs50.h>
#include <stdio.h>

int main(void)
{
    // TODO: Prompt for start size
    int pop_start;
    do
    {
        pop_start = get_int("Population size to start with: ");
    }
    while (pop_start < 9);

    // TODO: Prompt for end size
    int pop_end;
    do
    {
        pop_end = get_int("Goal for population size: ");
    }
    while (pop_end < pop_start);

    // TODO: Calculate number of years until we reach threshold
    int years;
    for (years = 0; pop_start < pop_end; years++)
    {
        pop_start = pop_start + pop_start / 3 - pop_start / 4;
    }

    // TODO: Print number of years
    printf("Years: %i\n", years);
}