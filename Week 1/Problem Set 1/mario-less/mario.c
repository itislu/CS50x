#include <cs50.h>
#include <stdio.h>

int main(void)
{
    // ask user for height
    int h;
    do
    {
        h = get_int("Height: ");
    }
    while (h < 1 || h > 8);

    //build pyramid
    int space;
    int block;
    int row = 1;
    while (row <= h)
    {
        //print spaces
        space = h - row;
        while (space > 0)
        {
            printf(" ");
            space--;
        }

        //print blocks
        block = row;
        while (block > 0)
        {
            printf("#");
            block--;
        }

        printf("\n");
        row++;
    }
}