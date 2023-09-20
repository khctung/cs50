#include <cs50.h>
#include <ctype.h>
#include <math.h>
#include <stdio.h>
#include <string.h>

int get_letters(string input);
int get_words(string input);
int get_sentences(string input);

int main(void)
{
    // getting user input
    string text = get_string("Text: ");

    // calculating # of letters
    int letters = get_letters(text);
    // calculating # of words
    int words = get_words(text);
    // calculating # of sentences
    int sentences = get_sentences(text);

    // computing grade level
    float L = ((float) letters / (float) words) * 100;
    float S = ((float) sentences / (float) words) * 100;
    int grade_level = round(0.0588 * L - 0.296 * S - 15.8);

    // deciding what to print based on grade level
    if (grade_level < 1)
    {
        printf("Before Grade 1\n");
    }
    else if (grade_level >= 16)
    {
        printf("Grade 16+\n");
    }
    else
    {
        printf("Grade %i\n", (int) grade_level);
    }
}

// function for getting the # of letters
int get_letters(string input)
{
    int num_letters = 0;
    for (int i = 0, n = strlen(input); i < n; i++)
    {
        if (isalpha(input[i]))
        {
            num_letters++;
        }
    }
    return num_letters;
}

// function for getting the # of words
int get_words(string input)
{
    int num_words = 0;
    for (int i = 0, n = strlen(input); i < n; i++)
    {
        if (isblank(input[i]))
        {
            num_words++;
        }
    }
    num_words++;
    return num_words;
}

// function for getting the # of sentences
int get_sentences(string input)
{
    int num_sentences = 0;
    for (int i = 0, n = strlen(input); i < n; i++)
    {
        if (input[i] == '!' || input[i] == '.' || input[i] == '?')
        {
            num_sentences++;
        }
    }
    return num_sentences;
}