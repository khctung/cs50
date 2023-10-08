#include <cs50.h>
#include <stdio.h>

void square(int *x);

int main(void)
{
    int x = 4;
    int *p1 = &x;
    int *p2 = p1;
    *p2 = 3;

    printf("%i\n", x);
    printf("%i\n", *p1);
    printf("%i\n", *p2);
}