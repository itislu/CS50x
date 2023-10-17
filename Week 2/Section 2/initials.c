// Given a name as a set of command-line arguments, print the initials of that name to the terminal.

#include <cs50.h>
#include <stdio.h>

int main(int argc, string argv[])
{
    printf("%c%c\n", argv[1][0], argv[2][0]);
}