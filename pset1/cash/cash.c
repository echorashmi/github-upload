/*
    A Program that asks user how much change is owed, and prints the minimum number of coins
    with which that change has been made
    Implements Greedy Algorithm.
    Author: Rashmi Bachani
    Date: Sunday, June 21, 2020.
*/

#include <stdio.h>
#include <cs50.h>
#include <math.h>
#include <stdlib.h>

int greedy_algorithm_version_one(int);
int greedy_algorithm_version_two(int);
int greedy_algorithm_version_three(int, int, int);

int main(void)
{
    //Take input of how much change is owed eg: 3.25, 2.10, etc. (use get_float)
    float owed_amount_in_dollars = get_float("Please enter the amount that is owed to this customer: ");

    //Check for Negative Inputs:
    if (owed_amount_in_dollars < 0)
    {
        printf("Error, please try again!\n");
        main();
    }
    else
    {
        int owed_amount_in_cents = round(owed_amount_in_dollars * 100);
        int number_of_coins = greedy_algorithm_version_three(owed_amount_in_cents, 25, 0);
        printf("%i", number_of_coins);
    }
}

/* Version One: Using If Statements */
int greedy_algorithm_version_one(int owed_amount_in_cents)
{
    int number_of_coins   = 0;
    int number_of_tens    = 0;
    int after_tens        = 0;
    int number_of_fivers  = 0;
    int after_fivers      = 0;
    int number_of_loonies = 0;

    //Get the modulus of 25, 10, 5 and 1 from this number.
    int number_of_quarters = owed_amount_in_cents / 25;
    int after_quarters     = owed_amount_in_cents % 25;
    //printf("%d", after_quarters);

    if (after_quarters > 0)
    {
        number_of_tens         = after_quarters / 10;
        after_tens             = after_quarters % 10;
    }


    if (after_tens > 0)
    {
        number_of_fivers       = after_tens / 5;
        after_fivers           = after_tens % 5;
    }

    if (after_fivers > 0)
    {
        number_of_loonies      = after_fivers / 1;
    }


    number_of_coins = number_of_quarters + number_of_tens + number_of_fivers + number_of_loonies;

    return number_of_coins;
}

/* Version 2: */
int greedy_algorithm_version_two(int owed_amount_in_cents)
{
    return owed_amount_in_cents;
    /*
    int slots = 1;
    int number_of_coins = 0;

    switch(slots):
    {
        case 25:

        case 10:

        case 5:

        case 1:
    }

    return number of coins;
    */
}


/* Fail - this doesn't work */
int greedy_algorithm_version_three(int owed_amount_in_cents, int slot_value, int number_of_coins)
{
    //int slot_values[4] = {25, 10, 5, 1};

    if (owed_amount_in_cents % slot_value == 0 )
    {
        number_of_coins = number_of_coins + owed_amount_in_cents / slot_value;
        owed_amount_in_cents = owed_amount_in_cents % slot_value;
        return owed_amount_in_cents;
    }
    else
    {
        if(owed_amount_in_cents > 0){
            number_of_coins      = number_of_coins + owed_amount_in_cents / slot_value;
            owed_amount_in_cents = owed_amount_in_cents % slot_value;

            if(slot_value == 25)
            {
                owed_amount_in_cents = greedy_algorithm_version_three(owed_amount_in_cents, 10, number_of_coins);
                number_of_coins      = number_of_coins + owed_amount_in_cents / slot_value;
            }
            if(owed_amount_in_cents > 0 && slot_value == 10)
            {
                owed_amount_in_cents = greedy_algorithm_version_three(owed_amount_in_cents, 5, number_of_coins);
                number_of_coins      = number_of_coins + owed_amount_in_cents / slot_value;
            }
            if(owed_amount_in_cents > 0 && slot_value == 5)
            {
                owed_amount_in_cents = greedy_algorithm_version_three(owed_amount_in_cents, 1, number_of_coins);
                number_of_coins      = number_of_coins + owed_amount_in_cents / slot_value;
            }
             return number_of_coins;
        }
        return 0;
    }
}