// Dynamically creates an array of requested size, where each element is double the previous one.
// Start array at 1.
// Print the array, integer by integer.

#include <cs50.h>
#include <stdio.h>

int main(void)
{
    // Ask user for length of array
    int n;
    do
    {
        n = get_int("Length: ");
    }
    while (n < 1);

    // Set up array to start with 1 and print that
    int array[n];
    array[0] = 1;
    printf("%i ", array[0]);

    // Fill in the array with double the current element and print that
    int i = 1;
    while (i < n)
    {
        array[i] = array[i-1] * 2;
        printf("%i ", array[i]);
        i++;
    }
    printf("\n");
}