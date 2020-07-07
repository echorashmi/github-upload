/*
    Problem Set 1
    Credit
    Write a program that prompts user for Credit Card information and then reports:
    - Whether it is a valid:
        - AmEx  : 15-Digit Number, start with 34 or 37.
        - MC    : 16-Digit Number, Start with 51, 52, 53, 54, 55
        - Visa  : 13-Digit & 16-Digit Numbers, Start with 4
    - Last line of Output be: AMEX\n or MASTERCARD\n or VISA\n or INVALID\n
    - Assume input will be numeric, devoid of hyphens or spaces
    - Use get_long and not int
*/

#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>

int luhn_checksum(int[], int);

int main(void)
{
    long int n = get_long("Please enter your credit card number (without Spaces or hyphens): ");
    //long int n = 4111111111111113;
    int length = floor(log10(labs(n))) + 1;
    int digits[length]; //reverse digits
    int forwarddigits[length];
    int i = 0;

    //Extract the Individual Digits (in reverse order):
    while (n != 0)
    {
        digits[i] = n % 10;
        n = n / 10;
        i++;
    }

    for (i = 0; i < length; i++)
    {
        forwarddigits[i] = digits[length - (i + 1)];

    }

    //Check the length:
    switch (length)
    {
        case 15: //Amex
        {
            if (forwarddigits[0] == 3 && (forwarddigits[1] == 4 || forwarddigits[1] == 7))
            {
                if (luhn_checksum(digits, length) == true)
                {
                    printf("AMEX\n");
                }
                else
                {
                    printf("INVALID\n");
                }
            }
            else
            {
                printf("INVALID\n");
            }
            break;
        }
        case 13: //Visa
        {
            if (forwarddigits[0] == 4)
            {
                if (luhn_checksum(digits, length) == true)
                {
                    printf("VISA\n");
                }
                else
                {
                    printf("INVALID\n");
                }
            }
            else
            {
                printf("INVALID\n");
            }
            break;
        }
        case 16: //MC or Visa
        {
            if (forwarddigits[0] == 4)
            {
                if (luhn_checksum(digits, length) == true)
                {
                    printf("VISA\n");
                }
                else
                {
                    printf("INVALID\n");
                }
            }
            else if (forwarddigits[0] == 5 && (forwarddigits[1] == 1 || forwarddigits[1] == 2 || forwarddigits[1] == 3 || forwarddigits[1] == 4 || forwarddigits[1] == 5))
            {
                if (luhn_checksum(digits, length) == true)
                {
                    printf("MASTERCARD\n");
                }
                else
                {
                    printf("INVALID\n");
                }
            }
            else
            {
                printf("INVALID\n");
            }
            break;
        }
        default:
        {
            printf("INVALID\n");
        }
    }
}

int luhn_checksum(int digits[], int length)
{
    int sum_of_products = 0;
    int product = 1;

    //1. Digits - select all the odd indices starting with 1:
    for (int i = 1; i < length; i = i + 2)
    {
        product = digits[i] * 2;
        if (product >= 10) //Because it can only be at max 2 digits long.
        {
            sum_of_products = sum_of_products + product % 10 + product / 10;
        }
        else
        {
            sum_of_products = sum_of_products + product;
        }
    }

    //4. Add the sum to the sum of the digits that weren't multipled by 2
    for (int i = 0; i < length; i = i + 2)
    {
        sum_of_products = sum_of_products + digits[i];
    }

    //5. If last digit in the sum is 0, return success, else fail
    if (sum_of_products % 10 == 0)
    {
        return true;
    }

    return false;
}