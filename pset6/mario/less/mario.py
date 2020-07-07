from cs50 import get_int
from sys import exit

while True:
    n = get_int("Enter Integer between 1 and 8: ")
    if n < 1 or n > 8:
        print("Invalid Input, please try again")
    else:
        break

# For loop:
for i in range(n):
    d = i+1  # Calculate blocks per line
    h = n-i-1  # Calculate spaces per line
    print(" " * h, end="")  # Print spaces
    print("#" * d, end="\n")  # Print blocks