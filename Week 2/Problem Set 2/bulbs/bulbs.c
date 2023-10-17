#include <cs50.h>
#include <math.h>
#include <stdio.h>
#include <string.h>

const int BITS_IN_BYTE = 8;

void dec_to_bin(int decimal, int bits[]);
void print_bulb(int bit);

int main(void)
{
    string message = get_string("Message: ");

    // Converts into and then prints all characters in binary
    int i = 0;
    while (message[i] != '\0')
    {
        // Stores the ASCII value of the current character into a new variable, so the original messagecan stay intact
        int decimal = message[i];

        // Stores the converted bits of the current character in an array
        int bits[BITS_IN_BYTE];

        // Converts the current character from decimal to binary and stores each bit into the bits array
        dec_to_bin(decimal, bits);

        // Prints each bit of the bits array
        int j = 0;
        while (j < BITS_IN_BYTE)
        {
            print_bulb(bits[j]);
            j++;
        }
        printf("\n");

        i++;
    }
}

void dec_to_bin(int decimal, int bits[])
{
    int bits_index = 0;
    int exponent = BITS_IN_BYTE - 1;

    while (exponent >= 0)
    {
        // If current decimal is lower than the next lower bit can represent, it is 0, decimal can stay the same, and it goes to the next bit
        if (decimal < pow(2, exponent))
        {
            bits[bits_index] = 0;
        }

        // If current decimal is higher than than the next lower bit can represent, it is 1, and then subtracts the current base-2 power to get to the next bit
        else
        {
            bits[bits_index] = 1;
            decimal -= pow(2, exponent);
        }

        exponent--;
        bits_index++;
    }
}

void print_bulb(int bit)
{
    if (bit == 0)
    {
        // Dark emoji
        printf("\U000026AB");
    }
    else if (bit == 1)
    {
        // Light emoji
        printf("\U0001F7E1");
    }
}
