#include <cs50.h>
#include <stdio.h>

int main(void)
{
    //ask user for height
    int h;
    do
    {
        h = get_int("Height: ");
    }
    while (h < 1 || h > 8);

    //build pyramids
    int row = 1;
    int spaces;
    int blocks;
    while (row <= h)
    {
        //print spaces h - row
        spaces = h - row;
        while (spaces > 0)
        {
            printf(" ");
            spaces--;
        }

        //print blocks equal to row - make a function
        blocks = row;
        while (blocks > 0)
        {
            printf("#");
            blocks--;
        }

        //gap of two spaces
        printf("  ");

        //print blocks equal to row again
        //HOW CAN THIS BE AVOIDED TO BE A COMPLETE COPY OF 2 STEPS BEFORE, BUT THE STEP BETWEEN HAS TO STAY?
        blocks = row;
        while (blocks > 0)
        {
            printf("#");
            blocks--;
        }

        printf("\n");
        row++;
    }
}