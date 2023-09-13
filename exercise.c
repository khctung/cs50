#include <cs50.h>
#include <stdio.h>

int main(void)
{
    string name = get_string("What is your name? ");
    int age = get_int("What is your age? ");
     phone_number = get_int("What is your phone number? ");

    printf("hello, %s, your age is %i and your phone number is %i", name, age, phone_number);

}