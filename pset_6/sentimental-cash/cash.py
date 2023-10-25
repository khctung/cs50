import cs50

# wanting to continue running until we get a valid input
while True:
    change = cs50.get_float("Change: ")
    if change > 0:
        break

coins = 0

num_quarters = (change/25).floor()
coins += num_quarters
change -= num_quarters*25

num_dimes = (change/10).floor()
coins += num_dimes
change -= num_dimes*10

num_nickels = (change/5).floor()
coins += num_nickels
change -= num_nickels*5

coins += change;
print((int)coins)
