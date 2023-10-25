code hello.py
python hello.py
# doesn't need separate compiler, just functions as interpreter

# python allocates memory for you, but might be slower than c because of this
import cs50
from cs50 import get_string

# don't need to declare type in python

#format string
answer = get_string("What's your name? ")
print(f"hello, {answer}")
#print automatically gives a space
only bool, float, int, and string in python (cuts out char, long, double)

range = range of values
list = like array but has memory allocated for you (no nodes, etc) + have methods with them
tuple = x,y -> combos of values that don't change
dict = assigning key w value (basically hash tables)
set = collection of values w/o duplicates
len = length of list/string

# traceback = traceback everything your program just did
indentation is really important in python (because no curly braces)

can compare strings in python
# doesn't work because addresses in string are different in c

object-oriented programming (OOP) = variables/datatypes can have values AND functionality
- ex. for strings, toupper function is built into strings themselves (methods)

- positional parameters must be passed in the same order as they appear in function (defined by position)
- named parameters can be passed in any order (defined by name)

helper functions = using def
def main():
    # do stuff

main() # need to call main

truncation = dividing ints -> truncates and give back a float
floating-point imprecision remains in python
integer overflow (too high of a number) -> not a problem in python!!

exceptions = error handling (ex. ValueError)
def get_int(prompt):
    while True:
        try:
            return int(input(prompt))
        except ValueError:
            print("Not an integer")
            # or try pass (which keeps looping until right)

for loops can have else conditionals