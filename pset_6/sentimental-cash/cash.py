import cs50

# wanting to continue running until we get a valid input
while True:
    change = cs50.get_float("Change: ")
    if change > 0:
        break

# converting dollar to cents
change *= 100

coins = 0

# calculating change for quarters
num_quarters = change // 25
coins += num_quarters
change -= num_quarters * 25

# calculating change for dimes
num_dimes = change // 10
coins += num_dimes
change -= num_dimes * 10

# calculating change for nickels
num_nickels = change // 5
coins += num_nickels
change -= num_nickels * 5

# adding directly for pennies
coins += change
print(int(coins))
