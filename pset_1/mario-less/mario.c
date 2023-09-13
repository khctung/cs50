#include <cs50.h>
#include <stdio.h>

int main(void)
{
    // getting user input
    int height;
    do
    {
        height = get_int("Height: ");
    }
    while (height < 1);

    // repeat space and hash printing for each row
    for (int i = 1; i <= height; i++)
    {
        // print spaces
        for (int spaces = i; spaces < height; spaces++)
        {
            printf(" ");
        }

        // print hashes
        for (int hashes = 0; hashes <= i; hashes++)
        {
            printf("#");
        }
        printf("\n");
    }
}