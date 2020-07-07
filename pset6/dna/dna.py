"""
    Example. Imagine a String ABCDEF
    How will I find the 'B' from this string?
"""

def main():
    locations = {
            'AGATC': {
                'counter': 0,
                'locs': []
            },
            'AATG': {
                'counter': 0,
                'locs': []
            },
            'TATC': {
                'counter': 0,
                'locs': []
            }
        }

    string = "AAGGTAAGTTTAGAATATAAAAGGTGAGTTAAATAGAATAGGTTAAAATTAAAGGAGATCAGATCAGATCAGATCTATCTATCTATCTATCTATCAGAAAAGAGTAAATAGTTAAAGAGTAAGATATTGAATTAATGGAAAATATTGTTGGGGAAAGGAGGGATAGAAGG"

    for j in locations:
        i = 0
        dnastr = j
        while i < len(string):
            first_match_found = verify(string[i], dnastr[0])
            if(first_match_found):
                is_true = verify(string[i:i+len(dnastr)], dnastr)
                if(is_true):
                    locations[j]['locs'].append(i)
            i += 1

    # Next Step: Get the number of consecutive loops:
    dna_tuple = get_consecutive(locations)

    print(locations)

def verify(literal, comparator):
    if(literal == comparator):
        return 1
    else:
        return 0

def get_consecutive(locations):
    for i in locations:
        dnastr_length = len(i)
        locations[i]['counter'] = get_counter(locations[i]['locs'], dnastr_length)

def get_counter(locations_array, length):
    if(len(locations_array) == 1):
        return 1
    else:
        # Calculate the difference between the numbers in an array:

main()















# Steps to solve:

# Code for Finding the DNA Sequence:
def main():
    sequence = getsequence()
    dnastrs  = getdnastrs()
    findstr(sequence, dnastrs)

def findstr(sequence, dnastrs):
    dnastr = dnastrs[0] #Just use 1 for now.
    if(sequence.find(dnastr)):
        print(dnastr)


def getsequence():
    sequence = "AAGGTAAGTTTAGAATATAAAAGGTGAGTTAAATAGAATAGGTTAAAATTAAAGGAGATCAGATCAGATCAGATCTATCTATCTATCTATCTATCAGAAAAGAGTAAATAGTTAAAGAGTAAGATATTGAATTAATGGAAAATATTGTTGGGGAAAGGAGGGATAGAAGG"
    return sequence

def getdnastrs():
    dnastrs = ["AGATC", "AATG", "TATC"]
    return dnastrs

# main()

# Step 1: Read from Sequence.txt

# Step 2: Open Database > Small.csv (for testing, then use Large.csv)

# Step 3: Use python string find - str.find(sub[, start[, end]] )

# Step 4: Store the number of occurences as this: { str: AAAA, occurences: [1, 5, 10, 15, 35] } //Where these numbers are positions in the string i.e. 1st position, 5th position, 15th position, etc. (where position starts from 0)

# Count the number of consecutive repeats?. How will I find the consecutive repeats? By length. By string length, we know the length of the repeats and hence to know that 1, 5, 10, 15 are all consecutive, but 35 is not consecutive.

# Problem Statement:
# Database DNA & how to read it - how many times does Albus have AGATC repeated in his DNA - 15.
# How many times does Albus have TTTTTTCT in his DBA? 49 times.
# name,AGATC,TTTTTTCT,AATG,TCTAG,GATA,TATC,GAAA,TCTG
# Albus,15,49,38,5,14,44,14,12
# Cedric,31,21,41,28,30,9,36,44
# Draco,9,13,8,26,15,25,41,39
# Fred,37,40,10,6,5,10,28,8
# Ginny,37,47,10,23,5,48,28,23
# Hagrid,25,38,45,49,39,18,42,30

# Sequences:
# 1.txt: AAGGTAAGTTTAGAATATAAAAGGTGAGTTAAATAGAATAGGTTAAAATTAAAGGAGATCAGATCAGATCAGATCTATCTATCTATCTATCTATCAGAAAAGAGTAAATAGTTAAAGAGTAAGATATTGAATTAATGGAAAATATTGTTGGGGAAAGGAGGGATAGAAGG

# Task: Take a Sequence of DNA and figure out whether or not it matches all the STR counts in the database provided.

# Given this DNA Sequence:
# 1.txt: AAGGTAAGTTTAGAATATAAAAGGTGAGTTAAATAGAATAGGTTAAAATTAAAGG#-AGATCAGATCAGATCAGATC-#TATCTATCTATCTATCTATCA#-GAAA-#AGAGTAAATAGTTAAAGAGTAA#-GATA-#TTGAATT#-AATG-##-GAAA-#ATATTGTTGGG#-GAAA-#GGAGG#-GATA-#GAAGG

# To find who it belongs to, we need to:
# Find where certain parts of the DNA repeat eg: AGATC repeats in the string where I marked it between #'s
# This is called a Short Tandem Repeat (STR)
# Different people have each STR repeated different number of times.

# People vary in hwo many times the STR repeats consecutively, person A 25 times
# Matching STR Counts represent who the DNA belongs to.
# AGAT is a sequence the FBI uses in it's own Database

# Python's csv module has reader and DictReader
# Python sys module gives you sys.argv -> DNA followed by sequence
# file read-> f.read()
# Open the files, compute the individual STR counts. How many times do they repeat consecutively?
# We only want the longest run of consecutive STRs.
# How many times the STR repeats starting at that position
# Keep checking to see if the STR matches once
# What is the maximum number of times the STR repeats consecutively.
# Substring: s[i:j] -> returns i:j (upto but not including j)
# Subsequence of it matches some expected results.

# Save the STR Counts in a Data Structure.
# Each Row in the Data, do each of the STR Count matches, and print out the name

# int(x) takes a string and turns it into the INT version of that string.

# To confirm the match, check every column other than the first column

