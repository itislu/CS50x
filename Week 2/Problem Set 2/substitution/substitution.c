// Encrypt a text with a substitution cipher, with the key given as a command-line argument by the user

#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <string.h>

// Number of letters in the alphabet
const int valid_length = 26;        // UPDATE: Should have made the constant name all uppercase

bool valid_key_length(string key);
bool valid_key_unique(string key);
string substitute(string plaintext, string key);

int main(int argc, string argv[])
{
    string key = argv[1];

    // Check if there is exactly one command-line argument, otherwise stop
    if (argc != 2)
    {
        printf("Usage: ./substitution key\n");
        return 1;
    }

    // Check if the key is valid, otherwise stop
    if (! valid_key_length(key) || ! valid_key_unique(key))
    {
        printf("Key must contain each letter of the alphabet exactly once.\n");
        return 1;
    }

    // Ask user for plaintext
    string plaintext = get_string("plaintext:  ");

    // Encrypt plaintext and print encrypted text
    printf("ciphertext: %s\n", substitute(plaintext, key));

    return 0;
}

// Checks if key is exactly 26 characters
bool valid_key_length(string key)
{
    if (strlen(key) == valid_length)
    {
        return true;
    }
    return false;
}

// Checks if key only contains letters, no duplicates and therefore all 26 letters of the alphabet exactly once
bool valid_key_unique(string key)
{
    char used_letters[valid_length] = {0};

    for (int i = 0; i < valid_length; i++)
    {
        // Check if valid character
        if (isalpha(key[i]))
        {
            // Case must not matter in the key
            key[i] = toupper(key[i]);

            // Check if character already used
            for (int j = 0; used_letters[j] != 0; j++)
            {
                if (key[i] == used_letters[j])
                {
                    return false;
                }
            }
            used_letters[i] = key[i];
        }
        else
        {
            return false;
        }
    }
    return true;
}

// Substitutes each letter in the plaintext with the corresponding letter in the key, with case being preserved
string substitute(string plaintext, string key)
{
    string ciphertext = plaintext;
    int l = strlen(plaintext);

    for (int i = 0; i < l; i++)
    {
        if (isupper(plaintext[i]))
        {
            ciphertext[i] = toupper(key[plaintext[i] - 'A']);
        }

        else if (islower(plaintext[i]))
        {
            ciphertext[i] = tolower(key[plaintext[i] - 'a']);
        }
    }
    return ciphertext;
}