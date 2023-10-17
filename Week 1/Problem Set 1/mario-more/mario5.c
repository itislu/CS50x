#include <cs50.h>
#include <stdio.h>

int get_height(void);
void print(char c, int i);

int main(void)
{
    int h = get_height();

    // Build pyramids
    int blocks = 1;
    while (blocks <= h)
    {
        print(' ', h - blocks);
        print('#', blocks);
        printf("  ");
        print('#', blocks);
        printf("\n");
        blocks++;
    }
}

// Asks user for height of the pyramid
int get_height(void)
{
    int h;
    do
    {
        h = get_int("Height: ");
    }
    while (h < 1 || h > 8);
    return h;
}

// Prints the inputted character i amount of times
void print(char c, int i)
{
    while (i > 0)
    {
        printf("%c", c);
        i--;
    }
}