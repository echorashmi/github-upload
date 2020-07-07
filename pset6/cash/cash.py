# Ask user how much cash is owed

# Spit out the minimum number of coins with which said change can be made

from cs50 import get_float

# Coins available are:
# 25c (Quarters)
# 10c (Dimes)
# 5c  (Nickles)
# 1c  (Pennies)

# Input: will be 9.75, not $9.75 (no Dollar Sign)
# If input is negative, repeat asking till the user provides correct positive input

# Step 1. Take Input multiple times till valid. Set n = number of coins
while True:
    due = get_float("Enter Due Amount: ")
    if due < 0:
        print("Invalid! Please try again.")
    else:
        due = due * 100
        break

coins = 0

for i in [25, 10, 5, 1]:
    coins += int(due / i)
    coins_mod = int(due % i)
    if coins > 0:
        due = coins_mod

print(coins)

# Test Cases:
# 0.41 -> 4
# 0.01 -> 1
# 0.15 -> 2
# 1.60 -> 7
# 23 -> 92
# 4.2 -> 18
# -1 -> Re-prompt user
# foo -> Re-prompt user
# (just press enter) -> Re-prompt user to type in another number

# submission: submit50 cs50/problems/2020/x/sentimental/cash