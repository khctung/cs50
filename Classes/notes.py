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

from collections import Counter

with open("favorites.csv", "r") as file:  # no need to close since it closes for you
    reader = csv.DictReader(file)  # stores data into a dictionary w/ the header rows as keys
    # counts = {} = dict()
    counts = Counter()

    for row in reader:
        favorite = row["language"]
        counts[favorite] += 1
        """
        if favorite in counts:
            counts[favorite] += 1
        else:
            counts[favorite] = 1
        """

for favorite in sorted(counts, key=counts.get, reverse=True): # sort by value instead of key, which is the default
    print(f"{favorite}: {counts[favorite]}")
OR
for favorite, count in counts.most_common():
    print(f"{favorite}: {count}")





11/13/2023 notes (lecture 9)
app.py
from flask import Flask, render_template, request

app = Flask(__name__)  #refers to current file's name
@app.route("/") #defining route for application
def index(): #called whenever application opened
    if "name" in request.args:
        name = request.args["name"]
    else:
        name = "world"
    name = request.args.get("name", "world") #can delete if-else conditional above
    return render_template("index.html", name=name) #goes into template, then index, and returns

# newest version
@app.route("/greet", methods=["POST"]) #post is more secure, doesn't show in URL
def greet():
    name = request.args.get("name", "world") #for get
    name = request.form.get("name", "world") #for post
    return render_template("greet.html", name=name)


@app.route("/", methods=["GET", "POST"])
def index():
    if request.method == "POST": #via post: process form (do something with input)
        name = request.form.get("name", "world") #for post
        return render_template("greet.html", name=name)
    return render_template("index.html") #via get: see form

click "view page source" --> technically not valid HTML, just returning

request.args = refers to any http request, args = property of all the key-value dictionary pairs that user could have provided in url
error 400 = blindly expecting parameter to exist
