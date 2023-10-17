#include <stdio.h>
#include <cs50.h>

int main(void)
{
    int a = 2;
    int b = 3;
    int c = (float) a / b * 2;

    int x = 2;
    int y = 3;
    int z = x / y * 2;

    int n = 2 / 3 * 3;

    printf("%i\n", c);
    printf("%i\n", z);
    printf("%i\n", n);
}