#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <string.h>

int check_score(string word);

int main(void)
{
    // getting user input
    string player1 = get_string("Player 1: ");
    string player2 = get_string("Player 2: ");

    // checking scores
    int score1 = check_score(player1);
    int score2 = check_score(player2);

    // printing results of game
    if (score1 > score2)
    {
        printf("Player 1 wins!\n");
    }
    else if (score1 < score2)
    {
        printf("Player 2 wins!\n");
    }
    else
    {
        printf("Tie!\n");
    }
}

// method for checking score
int check_score(string word)
{
    int score = 0;
    // storing values per letter
    int letter_scores[] = {1, 3, 3, 2, 1, 4, 2, 4, 1, 8, 5, 1, 3, 1, 1, 3, 10, 1, 1, 1, 1, 4, 4, 8, 4, 10};

    for (int i = 0; word[i] != '\0'; i++)
    {
        char letter = tolower(word[i]);
        if (letter >= 'a' && letter <= 'z')
        {
            score += letter_scores[letter - 'a'];
        }
    }
    return score;
}