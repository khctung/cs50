#include <cs50.h>
#include <stdio.h>

void square(int *x);

int main(void)
{
    int x = 5;
    square(&x);
    printf("%i\n", x);
}

void square(int *n)
{
    *n = &n * &n;
}