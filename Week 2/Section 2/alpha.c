// Checks if a lowercase string's characters are in alphabetical order.

#include <cs50.h>
#include <stdio.h>
#include <string.h>

int check_lowercase(string word, int length);
string check_order(string word, int length);

int main(void)
{
    string word;
    int length;

    int is_lowercase;
    do
    {
        word = get_string("Word: ");
        length = strlen(word);
        is_lowercase = check_lowercase(word, length);
    }
    while (is_lowercase == 0);

    printf("%s", check_order(word, length));
}

// Makes sure that user's input is all lowercase
int check_lowercase(string word, int length)
{
    int i = 0;
    while (i < length)
    {
        if (word[i] < 'a' || word[i] > 'z')
        {
            return 0;
        }
        i++;
    }
    return 1;
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