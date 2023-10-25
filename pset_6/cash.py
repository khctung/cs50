import cs50

# wanting to continue running until we get a valid input
while True:
    change = cs50.get_float("Change: ")
    if change > 0:
        break

coins = 0
num_quarters = change/25;
coins += change/25;
change -= change*25;





    // counting the minimum # of coins
    int coins = 0;

    // checking for quarters
    if (change >= 25)
    {
        int num_quarters = change / 25;
        coins += num_quarters;
        change -= num_quarters * 25;
    }

    // checking for dimes
    if (change >= 10)
    {
        int num_dimes = change / 10;
        coins += num_dimes;
        change -= num_dimes * 10;
    }

    // checking for nickels
    if (change >= 5)
    {
        int num_nickels = change / 5;
        coins += num_nickels;
        change -= num_nickels * 5;
    }

    // adding remaining change as pennies
    coins += change;
    printf("%i\n", coins);
}
