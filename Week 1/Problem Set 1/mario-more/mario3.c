#include <cs50.h>
#include <stdio.h>

int get_height(void);
void print_spaces(int spaces);
void print_blocks(int blocks);

int main(void)
{
    int h = get_height();

    // Build pyramids
    int blocks = 1;
    int spaces;
    while (blocks <= h)
    {
        print_spaces(spaces = h - blocks);

        print_blocks(blocks);
        printf("  ");
        print_blocks(blocks);
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

// Prints as many spaces so that together with the then following blocks the sum of characters adds up to user requested height of the pyramid
void print_spaces(int spaces)
{
    while (spaces > 0)
    {
        printf(" ");
        spaces--;
    }
}

// Prints as many blocks as the number of the current height of the pyramid
void print_blocks(int blocks)
{
    while (blocks > 0)
    {
        printf("#");
        blocks--;
    }
}