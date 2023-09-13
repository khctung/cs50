#include <cs50.h>
#include <stdio.h>

int main(void)
{
    // getting user input
    int change;
    do
    {
        change = get_int("Change owed: ");
    }
    while (height <= 0);

    // counting the minimum # of coins
    int coins = 0;
    while (change != 0)
    {
        if (change >= 25)
        {
            int num_quarters = change/25;
            coins += num_quarters;
            change -= num_quarters*25;
        }
        if (change >= 10)
        {
            int num_dimes = change/10;
            coins += num_dimes;
            change -= num_dimes*10;
        }
        if (change >= 5)
        {
            int num_nickels = change/5;
            coins += num_nickels;
            change -= num_nickels*5;
        }
        
    }
}