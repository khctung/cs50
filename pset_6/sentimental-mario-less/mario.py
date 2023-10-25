import cs50

# wanting to continue running until we get a valid input
while True:
    user_input = int(cs50.get_int(("Height: ")))
    if user_input <= 8 and user_input >= 1:
        break

# using user input to set the range for the loop
for i in range(user_input):
    print(" " * (user_input - i - 1), end="")
    print("#" * (i + 1), end="")
    print()
