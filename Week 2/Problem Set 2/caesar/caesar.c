// Encrypts a text using Ceasar's cipher, with the key given as a command-line argument

#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

bool only_digits(string s);
char rotate(char c, int key);

int main(int argc, string argv[])
{
    // Check if there is exactly one command-line argument and if it only consists of digits, otherwise stop
    if (argc != 2 || ! only_digits(argv[1]))
    {
        printf("Usage: ./caesar key\n");
        return 1;
    }

    // Convert and store key as an int
    int key = atoi(argv[1]);

    // Ask user for plaintext
    string plaintext = get_string("plaintext:  ");

    printf("ciphertext: ");

    // Print the encrypted text
    int i = 0, l = strlen(plaintext);
    while (i < l)
    {
        printf("%c", rotate(plaintext[i], key));
        i++;
    }

    printf("\n");
    return 0;
}

// Checks if given string only consists of digits
bool only_digits(string s)
{
    int i = 0, l = strlen(s);
    while (i < l)
    {
        if (! isdigit(s[i]))
        {
            return false;
        }
        i++;
    }
    return true;
}

// Rotates a character by the given amount
char rotate(char c, int key)
{
    // Encryption for lowercase
    if (islower(c))
    {
        c = (c - 'a' + key) % 26 + 'a';
    }

    // Encryption for uppercase
    else if (isupper(c))
    {
        c = (c - 'A' + key) % 26 + 'A';
    }

    return c;
}