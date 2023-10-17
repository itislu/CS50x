// Write a function to replace vowels with numbers
// Get practice with strings
// Get practice with command line
// Get practice with switch

#include <cs50.h>
#include <stdio.h>

string replace(string argv[1]);

int main(int argc, string argv[])
{
    // if more or less than 1 CL argument, print error message and return value 1 from main
    if (argc != 2)
    {
        printf("Please add exactly one command-line argument when executing this program.\n");
        return 1;
    }

    printf("%s\n", replace(argv));
}

// function called replace
string replace(string argv[1])
{
    int i = 0;
    while (argv[1][i] != '\0')      // Loops till it reaches the last character of a string: NUL
    {
        switch (argv[1][i])
        {
            case 'a':
                argv[1][i] = '6';
                break;
            case 'e':
                argv[1][i] = '3';
                break;
            case 'i':
                argv[1][i] = '1';
                break;
            case 'o':
                argv[1][i] = '0';
                break;
        }
        i++;
    }
    return argv[1];
}