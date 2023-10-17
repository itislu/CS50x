// Checks if a lowercase string's characters are in alphabetical order.

#include <cs50.h>
#include <stdio.h>
#include <string.h>

string get_lowercase_string(void);
string check_order(string word, int length);

int main(void)
{
    string word = get_lowercase_string();
    int length = strlen(word);
    printf("%s", check_order(word, length));
}

// Makes sure, in a recursive way, that user's input is all lowercase
string get_lowercase_string(void)
{
    string word = get_string("Word: ");
    int length = strlen(word);

    int i = 0;
    while (word[i] >= 'a' && word[i] <= 'z' && i < length)
    {
        i++;
    }
    if (i < length - 1)
    {
        word = get_lowercase_string();
    }
    return word;
}

// Checks if a character's ASCII value is higher than the next one's, meaning if it is a character later in the alphabet
string check_order(string word, int length)
{
    int i = 0;
    while (i < length - 1)
    {
        if (word[i] > word[i+1])
        {
            return "No\n";
        }
        i++;
    }
    return "Yes\n";
}