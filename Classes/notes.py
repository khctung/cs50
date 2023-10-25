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
list = array (but better!)
tuple = x,y -> combos of values that don't change
dict = assigning key w value (basically hash tables)
set = collection of values w/o duplicates