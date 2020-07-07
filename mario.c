#include <stdio.h>
#include <cs50.h>

int main(void)
{
    //Get the User Input for Height
    int height_of_tower = get_int("How tall do you want the tower? (Enter a integer between 1 and 8): ");

    if(height_of_tower >= 1 && height_of_tower <= 8) //Pass Case
    {
        for (int i = 1; i <= height_of_tower; i++)
        {
            for (int j = height_of_tower; j > i; j--)
            {
                printf(" ");
            }
            for(int j = 0; j < i; j++)
            {
                printf("#");
            }
            printf("  ");
            for(int j = 0; j < i; j++)
            {
                printf("#");
            }
            printf("\n");
        }
    }
    else //Fail Case
    {
        printf("Error! Please try again. ");
        main();
    }
}