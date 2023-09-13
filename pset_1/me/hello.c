#include <cs50.h>
#include <stdio.h>

int main(void)
{
    // getting user input
    string name = get_string("What's your name? ");

    // printing their name
    printf("hello, %s\n", name);
}