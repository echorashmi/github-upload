#include <stdio.h>
#include <cs50.h>

int main(void)
{
    int index[26];
    int j = 97;
    for (int i = 0; i < 26; i++)
    {
        index[i] = j;
        j++;
    }

    //Let's pretend there are only 3 alphabets in the world.
    char a = 'a';
    char b = 'b';
    char c = 'c';
    char d = 'd';
    char z = 'z';
    char r = 'r';
    char f = 'f';
    char o = 'o';
    string bar = get_string("plaintext: ");
    char cipher;

    //Cipherloop:
    for (j = 0; bar[j] != '\0'; j++)
    {
        for (int i = 0; i < 26; i++)
        {
            if((int)bar[j] == index[i])
            {
                int temp = (i+23)%26; //Shift the letter ahead.
                printf("%c\n", (char)index[temp]);
                break;
            }
        }
    }



    //printf("%c\n", cipher);
}