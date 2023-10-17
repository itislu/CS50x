// Calculates the approximate (U.S.) grade level needed to comprehend some text, using the Coleman-Liau index

#include <cs50.h>
#include <ctype.h>
#include <math.h>
#include <stdio.h>

int letters = 0, words = 0, sentences = 0;
void count(string text);

int main(void)
{
    string text = get_string("Text: ");
    count(text);

    // Average number of letters per 100 words
    float L = (float) letters / words * 100;

    // Average number of sentences per 100 words
    float S = (float) sentences / words * 100;

    // Calculates the grade with the Coleman-Liau formula
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

void count(string text)
{
    int i = 0;

    while (text[i] != '\0')
    {
        // Counts any upper- and lowercase letter
        if (isalpha(text[i]))
        {
            letters++;
        }

        // Counts every appearance of a space or tab as a word if the text contains at least one letter
        else if (letters > 0 && isblank(text[i]))
        {
            words++;
        }

        // Counts every appearance of a period, exclamation point, and question mark as a sentence if the text contains at least one letter
        else if (letters > 0 && (text[i] == '.' || text[i] == '!' || text[i] == '?'))
        {
            sentences++;
        }
        i++;
    }

    // To account for the last word not having a space after it
    if (letters > 0)
    {
        words++;
    }
}