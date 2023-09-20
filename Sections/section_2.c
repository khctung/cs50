#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <string.h>

int main(void)
{
    string str = "Alex";
    for (int i = 0, n = strlen(str); i < n; i++)
    {
        printf("%c\n", str[i]);
    }
}