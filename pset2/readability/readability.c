/*
CS50: Problem Set 2 - Readability:
Prompt the user for a string of text.
Count the number of letters, words, and sentences in the text.

Letter : any lowercase character from a-z or uppercase character from A-Z
Word   : Sequence of characters separated by spaces
End of Sentence: Period, Excalamation Point, or Question Mark

Output:
Grade X
X - is grade level computed by Coleman-Liau Formula, rounded to the nearest integer.
If resulting is 16 or higher, output "Grade 16+"
If less than 1, output "Before Grade 1"
-
*/

#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <math.h>

int main(void)
{
    string text         = get_string("Text: ");
    //string text         = "Harry Potter was a highly unusual boy in many ways. For one thing, he hated the summer holidays more than any other time of year. For another, he really wanted to do his homework, but was forced to do it in secret, in the dead of the night. And he also happened to be a wizard.";
    int count_letters   = 0;
    int count_words     = 1;
    int count_sentences = 0;
    float l;
    float s;
    float index;

    for (int i = 0; text[i] != '\0'; i++)
    {
        int ascii_value = (int)text[i];

        //Uppercase || Lowercase
        if((ascii_value >= 65 && ascii_value <= 90) || (ascii_value >= 97 && ascii_value <=122))
        {
            count_letters++;
        }
        else if (ascii_value == 32) //Space
        {
            count_words++;
        }
        else if (ascii_value == 33 || ascii_value == 46 || ascii_value == 63) //!, ., ?
        {
            count_sentences++;
        }
    }
    //printf("Sentences: %i\n Words: %i\n Letters: %i", count_sentences, count_words, count_letters);

    /*
        Coleman-Liau Index Formula:
        index = 0.0588 * L - 0.296 * S - 15.8
    */

    //Average number of letters per 100 words:
    l = ((float)count_letters / (float)count_words) * 100;

    //printf("%f\n", l);

    //Average number of sentences per 100 words:
    s = ((float)count_sentences / (float)count_words) * 100;

    index = 0.0588 * l - 0.296 * s - 15.8;
    index = (int)round(index);

    if (index < 1)
    {
        printf("Before Grade 1\n");
    }
    else if (index > 16)
    {
        printf("Grade 16+\n");
    }
    else
    {
        printf("Grade %i\n", (int)index);
    }

}