// Calculates the approximate grade level needed to comprehend some text, using the Coleman-Liau index

#include <cs50.h>
#include <ctype.h>
#include <math.h>
#include <stdio.h>

int count_letters(string text);
int count_words(string text, int letters);
int count_sentences(string text);

int main(void)
{
    string text = get_string("Text: ");
    int letters = count_letters(text);
    int words = count_words(text, letters);
    int sentences = count_sentences(text);

    // Average number of letters per 100 words
    float L = (float) letters / words * 100;

    // Average number of sentences per 100 words
    float S = (float) sentences / words * 100;

    // Calculates the Coleman-Liau index
    float grade_float = 0.0588 * L - 0.296 * S - 15.8;

    // Rounds the index to the nearest integer, as ultimately a distinct grade is desired
    int grade = (int) round(grade_float);

    // Print grade after checking for cases outside of grades 1-16
    if (grade < 1)
    {
        printf("Before Grade 1\n");
    }
    else if (grade > 16)
    {
        printf("Grade 16+\n");
    }
    else
    {
        printf("Grade %i\n", grade);
    }
}

// Counts any upper- and lowercase letter
int count_letters(string text)
{
    int i = 0, letters = 0;

    while (text[i] != '\0')
    {
        if (isalpha(text[i]))
        {
            letters++;
        }
        i++;
    }

    return letters;
}

// If the text contains at least one letter, it counts every appearance of a space or tab as a word, +1 for the last word of the text
int count_words(string text, int letters)
{
    int i = 0, words = 0;

    // Skip the counting if there are no letters -> words stays at 0
    if (letters > 0)
    {
        // Count every space as an indicator of a word
        while (text[i] != '\0')
        {
            if (isblank(text[i]))
            {
                words++;
            }
            i++;
        }

        // To account for the last word not having a space after it
        return words + 1;
    }

    return words;
}

// Counts every appearance of a period, exclamation point, and question mark as a sentence
int count_sentences(string text)
{
    int i = 0, sentences = 0;

    while (text[i] != '\0')
    {
        if (text[i] == '.' || text[i] == '!' || text[i] == '?')
        {
            sentences++;
        }
        i++;
    }

    return sentences;
}