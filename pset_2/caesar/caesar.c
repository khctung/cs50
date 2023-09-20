#include <cs50.h>
#include <ctype.h>
#include <math.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

bool only_digits(string input);
char rotate(int num, char character);

int main(int argc, string argv[])
{
    // checking whether or not the user input is valid
    if (argc == 2 && only_digits(argv[1]))
    {
        // setting the key and asking for input for plain text
        int key = atoi(argv[1]);
        string plain_text = get_string("plaintext:  ");

        printf("ciphertext: ");
        // manually rotating and printing each ciphered character
        for (int i = 0, n = strlen(plain_text); i < n; i++)
        {
            printf("%c", rotate(key, plain_text[i]));
        }
        printf("\n");
        return 0;
    }
    else
    {
        printf("Usage: ./caesar key\n");
        return 1;
    }
}

// function for checking if a string is made of only digits
bool only_digits(string input)
{
    for (int i = 0, n = strlen(input); i < n; i++)
    {
        if (!isdigit(input[i]))
        {
            return false;
        }
    }
    return true;
}

// function for ciphering the given character
char rotate(int num, char character)
{
    if (isalpha(character))
    {
        if (islower(character))
        {
            character = (char) (((character - 'a' + num) % 26) + 'a');
        }
        else
        {
            character = (char) (((character - 'A' + num) % 26) + 'A');
        }
    }
    return character;
}