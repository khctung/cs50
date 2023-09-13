#include <cs50.h>
#include <stdio.h>

int main(void)
{

    int rename(const char *old_filename, const char *new_filename);

    string name = get_string("What is your name? ");
    int age = get_int("What is your age? ");
    // could store as string and float
    long phone_number = get_long("What is your phone number? ");
    // could store as string or double too

    printf("hello, %s, your age is %i and your phone number is %ld\n", name, age, phone_number);
}
