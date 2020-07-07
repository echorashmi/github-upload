#include <stdio.h>
#include <cs50.h>
#include <math.h>
#include <stdlib.h>

int main(int argc, string argv[])
{
    long int number = atol(argv[1]);

    while (number != 0)
    {
        int digit = number % 10;
        number    = number / 10;
        printf("%d\n", digit);
    }
    return 0;
}