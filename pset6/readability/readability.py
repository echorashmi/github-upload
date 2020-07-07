# Ask user to type in some text, outputs the grade level for the text, according to Coleman-Liau Formula
# Coleman-Liau Index is: 0.0588 * L - 0.296 * S - 15.8
# L = Average number of Letters per 100 words in the text
# S = Average number of sentences per 100 words in the text

from cs50 import get_string
import math

# Step 0: Get input String


def main():
    text = get_string("Text: ")
    grade = calc_grade(text)
    if grade < 1:
        print("Before Grade 1")
    elif grade > 16:
        print("Grade 16+")
    else:
        print(f"Grade {grade}")


def calc_grade(text):
    text_length = len(text)
    letters = 0
    sentences = 0
    words = 1

# Step 1: Get L:
    for i in text:
        if i.isalpha():
            letters = letters + 1
        elif i.isspace():
            words = words + 1

# Step 2: Get S:
    for i in text:
        if i == "?" or i == "!" or i == ".":
            sentences = sentences + 1

# Step 3: Get W:

    l = (letters / words) * 100

    s = (sentences / words) * 100

    clindex = round(0.0588 * l - 0.296 * s - 15.8)
    return clindex


main()


# Step 3: Get W:

# Step 3: Get CL Index:

# Count the number of letters, words and sentences in the text
# A letter   = any lowercase character from a-z or uppercase character from A-Z
# A word     = any sequence of characters separated by spaces
# A sentence = any occurrence of a period, exclamation point, or question mark indicates the end of a sentence

# Output: Grade X where X is grade level, rounded to nearest integer
# Output: If 16+ then output Grade 16+. If Less than 1, output Before Grade 1

# Test Cases:
# One fish. Two fish. Red fish. Blue fish. -> Before Grade 1
# Would you like them here or there? I would not like them here or there. I would not like them anywhere. -> Grade 2
# Congratulations! Today is your day. You're off to Great Places! You're off and away! -> Grade 3
# Harry Potter was a highly unusual boy in many ways. For one thing, he hated the summer holidays more than any other time of year. For another, he really wanted to do his homework, but was forced to do it in secret, in the dead of the night. And he also happened to be a wizard. -> Grade 5
# In my younger and more vulnerable years my father gave me some advice that I've been turning over in my mind ever since. -> Grade 7
# Alice was beginning to get very tired of sitting by her sister on the bank, and of having nothing to do: once or twice she had peeped into the book her sister was reading, but it had no pictures or conversations in it, "and what is the use of a book," thought Alice "without pictures or conversation?" -> Grade 8
# When he was nearly thirteen, my brother Jem got his arm badly broken at the elbow. When it healed, and Jem's fears of never being able to play football were assuaged, he was seldom self-conscious about his injury. His left arm was somewhat shorter than his right; when he stood or walked, the back of his hand was at right angles to his body, his thumb parallel to his thigh. -> Grade 8
# There are more things in Heaven and Earth, Horatio, than are dreamt of in your philosophy. -> Grade 9
# It was a bright cold day in April, and the clocks were striking thirteen. Winston Smith, his chin nuzzled into his breast in an effort to escape the vile wind, slipped quickly through the glass doors of Victory Mansions, though not quickly enough to prevent a swirl of gritty dust from entering along with him. -> Grade 10
# A large class of computational problems involve the determination of properties of graphs, digraphs, integers, arrays of integers, finite families of finite sets, boolean formulas and elements of other countable domains. -> Grade 16+