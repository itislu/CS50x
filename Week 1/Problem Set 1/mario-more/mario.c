#include <cs50.h>
#include <stdio.h>

int get_height(void);
void build(int blocks, int h);
void print(char c, int i);

int main(void)
{
    int h = get_height();
    int top = 1;
    build(top, h);
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

// Builds pyramids with the number of blocks at top and the height as inputs
void build(int blocks, int h)
{
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

// Prints the inputted character i amount of times
void print(char c, int i)
{
    while (i > 0)
    {
        printf("%c", c);
        i--;
    }
}