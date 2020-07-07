/*
   CS50 Problem Set 2: Ceaser Cipher

   Implement a Program that encrypts messages using Caesar's cipher

   ./ceaser 13
   plaintext  : HELLO
   ciphertext : URYYB

   Ceaser -> shifting each letter by some number of places.
   We "rotate" each letter by k positions.
   If p is some plaintext, p(i) is the i'th character in p, k is secret key , each letter c(i) is:
   c(i) = (p(i) + k) % 26

   The space and comma don't shift - only alphabets shift.

   Accept a single command-line argument - a non-negative integer.

*/

#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

int main(int argc, string argv[])
{
    int key = 0;
    if (argc == 2)
    {
        int len = strlen(argv[1]);
        for (int i = 0; i < len; i++)
        {
           if(!isdigit(argv[1][i]))
           {
              printf("Usage: ./caesar key\n");
              return 1;
           }
        }

        key = atoi(argv[1]); //Convert String to Integer
    }
    else
    {
        printf("Usage: ./caesar key\n");
        return 1;
    }

   string s   = get_string("plaintext: ");
   string c[strlen(s)];
   int ascii_value;
   int ascii_cipher;

   int index[26];
   int j = 97;
   for (int i = 0; i < 26; i++)
   {
      index[i] = j;
      j++;
   }

   int indexUpper[26];
   j = 65;
   for (int i = 0; i < 26; i++)
   {
      indexUpper[i] = j;
      j++;
   }

   printf("ciphertext: ");

   for (j = 0; s[j] != '\0'; j++)
    {
        for (int i = 0; i < 26; i++)
        {
           //printf("\n\n%i %c %i\n\n", (int)s[j], s[j], index[i]);
            if((int)s[j] == index[i])
            {
                int temp = (i+key)%26;
                s[j] = (char)index[temp];
                break;
            }

            else if((int)s[j] == indexUpper[i])
            {
                int temp = (i+key)%26;
                s[j] = (char)indexUpper[temp];
                break;
            }
        }
    }
    printf("%s\n", s);
}