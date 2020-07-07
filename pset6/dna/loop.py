arr1 = [75, 79, 83, 87, 91]

# Calculate how many consecutive sequences there are in this string.

i = 0

while True:
    if(arr1[i+1] - arr1[i] == 4):
        print(f"Success at {i}")
    else:
        print(f"Failure at {i}")
    i += 1
    if((i+1) >= len(arr1)):
        break