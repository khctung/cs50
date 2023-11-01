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

- for loops can have else conditionals
- sys = system related functionality (library)

version 1:
from sys import argv

if len(argv) == 2:
    print(f"hello, {argv[1]}")


version 2:
import sys

if len(sys.argv) != 2:
    sys.exit()


- pip
- ex. pip install cowsay
import cowsay
cowsay.cow("hi!")

pip intall qrcode



SQL notes

flat-file database = literal text file (.txt or .csv)
-> has delimiters to separate values, csv = comma separated values
-> mimic row/columns by using n/ for rows and commas for columns
-> first row is header row (describes what each column is for)

import csv
file = open("favorites.csv", "r")  # r is not needed since python assumes read
# do something with file
close(file)

metadata = data that describes my actual data, like the header row

with open("favorites.csv", "r") as file:  # no need to close since it closes for you
    reader = csv.reader(file)
    next(reader)
    for row in reader:
        print(row[1])

with open("favorites.csv", "r") as file:  # no need to close since it closes for you
    reader = csv.DictReader(file)  # stores data into a dictionary w/ the header rows as keys
    for row in reader:
        print(row["language"])


