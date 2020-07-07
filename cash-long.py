
# Step 2. Divide by 25. Modulo 25. Increment n.
coins_25 = int(due / 25)
coins_25_mod = int(due % 25)
if coins_25 > 0:
    due = coins_25_mod

# Step 3. Divide by 10. Modulo 10. Increment n.
coins_10 = int(due / 10)
coins_10_mod = int(due % 10)
if coins_10 > 0:
    due = coins_10_mod

# Step 4. Divide by 5. Modulo 5. Increment n.
coins_5 = int(due / 5)
coins_5_mod = int(due % 5)
if coins_5 > 0:
    due = coins_5_mod

# Step 5. Divide by 1. Modulo 1. Increment n.
coins_1 = int(due / 1)
coins_1_mod = int(due % 1)
if coins_1 > 0:
    due = coins_1_mod