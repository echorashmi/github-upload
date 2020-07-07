/**************************************************************
 * Already Started work for this - the Pseudocode is in my CS50 Google Doc.
 * Good Luck!
 * Next Steps:
    *  1. Learn about how to visualize, transpose and gain confidence in large scale arrays
    *     of 26 characters length.
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
****************************************************************/

/*
    User enters input string of 26 characters, which will map to A-Z

    $ ./substitution BCDEFGHIJKLMNOPQRSTUVWXYZA
    plaintext: ABC
    ciphertext: BCD

    Edge Cases to Handle:
    1. Key: Ensure it's 26 alphabetic characters only. If not, return 1 from main.
    2. Special Characters: Leave them unchanged - including spaces.

    check50 cs50/problems/2020/x/substitution
*/

#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <ctype.h>

int substitute(string plaintext, string key);

int main(int argc, string argv[])
{
    string key        = argv[1];
    //string key        = "Apple";
    //string ciphertext = "Rashmi";
    string plaintext;

    /***
     * Validate the Key:
     * 1. No Key
     * 2. Invalid Length of Key
    */
    if (!key || strlen(key) < 26)
    {
        printf("Fail on Key");
        return 1;
    }

    /***
     * Validate the Key continued:
     * 3. Invalid Characters in Key
    **/
    for (int i = 0; i < strlen(key); i++)
    {
        //Invalid Characters i.e. not in ASCII alphabet range.
        if (!isalpha(key[i]))
        {
            printf("Error character: %c", key[i]);
            return 1;
        }
    }

    /***
     * Validate the Key Continued:
     * 4. Duplicate Characters in Key
     * 5. Multiple Duplicate Characters in Key
    **/
    bool isDuplicates = false;
    for (int i = 0; i < strlen(key); i++)
    {
        for (int j = i + 1; j < strlen(key); j++)
        {
            if (key[i] == key[j])
            {
                printf("%c", key[i]);
                isDuplicates = true;
            }
        }
    }
    if (isDuplicates)
    {
        return 1;
    }

    plaintext = get_string("Plaintext: ");
    /***
     * At this point, we have a ready to use, sanitized cipher key.
    */
    //string key        = "DWUSXNPQKEGCZFJBTLYROHIAVM";
    //string plaintext  = "The quick brown fox jumps over the lazy dog";
    int ciphertext = substitute(plaintext, key);

    return 0;
}

int substitute(string plaintext, string key)
{
    char cipherkey[26][4];
    int j = 97;
    int k = 0;

    //Build the Cipher Parent Key:
    for (int i = 65; k < 26; i++, j++, k++)
    {
        cipherkey[k][0] = (char)i;
        cipherkey[k][2] = (char)j;
    }

    for (int i = 0; key[i] != '\0'; i++)
    {
        if (isupper(key[i]))
        {
            cipherkey[i][1] = key[i];
            cipherkey[i][3] = tolower(key[i]);
        }
        else
        {
            cipherkey[i][1] = toupper(key[i]);
            cipherkey[i][3] = key[i];
        }
    }

    /*
        for (int i = 0; i < 26; i++) //External For Loop for Caps Alphabet
        //Internal for loop for the cipher values:
        {
            printf("%i: %c => \n{\n", i, cipherkey[i][0]);
            for (j = 0; j < 4; j++) //This will always stay 4 because that's how many characters we need: 0, 1, 2, 3 to represent the cipher
            {
                printf("  %i: %c\n", j, cipherkey[i][j]);
            }
            printf("}\n");
        }
    */
    char ciphertext[strlen(plaintext)];
    for (int i = 0; plaintext[i] != '\0'; i++) //Parent for loop with plaintext
    {
        if (isalpha(plaintext[i]))
        {
            for (j = 0; j < 26; j++) //Loop through all 0-0th elements of the cipher key
            {
                if (plaintext[i] == cipherkey[j][0])
                {
                    ciphertext[i] = cipherkey[j][1];
                }
                else if (plaintext[i] == cipherkey[j][2])
                {
                    ciphertext[i] = cipherkey[j][3];
                }
            }
        }
        else
        {
            ciphertext[i] = plaintext[i];
        }
    }
    printf("ciphertext: %s\n", ciphertext);
    return 0;
}