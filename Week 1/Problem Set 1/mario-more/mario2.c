#include <cs50.h>
#include <stdio.h>

void print_blocks(int blocks);

int main(void)
{
    //ask user for height -> make a function
    int h;
    do
    {
        h = get_int("Height: ");
    }
    while (h < 1 || h > 8);

    //build pyramids
    int row = 1;
    while (row <= h)
    {
        //print spaces, so that blocks can come after them
        int spaces = h - row;
        while (spaces > 0)
        {
            printf(" ");
            spaces--;
        }

        //print as many blocks as the number of the current row -> make a function
        int blocks = row;
        print_blocks(blocks);

        //gap of two spaces between the pyramids
        printf("  ");

        //print blocks equal to row again
        print_blocks(blocks);

        printf("\n");
        row++;
    }
}

//HOW DO I MAKE A PIECE OF CODE REUSABLE??
void print_blocks(int blocks)
{
    while (blocks > 0)
    {
        printf("#");
        blocks--;
    }
}