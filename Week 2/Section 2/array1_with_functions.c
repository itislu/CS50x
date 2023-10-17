// Dynamically creates an array of requested size, where each element is double the previous one.
// Start array at 1.
// Print the array, integer by integer.

#include <cs50.h>
#include <stdio.h>

int build_array(int array[], int n);
void print_array(int array[], int n);

int main(void)
{
    int n;
    do
    {
        n = get_int("Length: ");
    }
    while (n < 1);

    int array[n];
    build_array(array, n);
    print_array(array, n);
}

int build_array(int array[], int n)    // UPDATE: "int" unnecessary, should be void as the output isn't needed - only the array is changed and that's what's needed
{
    array[0] = 1;
    int i = 1;
    while (i < n)
    {
        array[i] = array[i-1] * 2;
        i++;
    }
    return array[n];                    // UPDATE: An array can't be returned, this only returns the n-th element of the array - which is not what is desired in this case and doesn't lead to anywhere anw
}

void print_array(int array[], int n)
{
    int i = 0;
    while (i < n)
    {
        printf("%i ", array[i]);
        i++;
    }
    printf("\n");
}