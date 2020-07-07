#include <stdio.h>
#include <cs50.h>

void sort(void);

int main(void)
{
    sort();
}

/*
* Bubble Sort: Building the array from Right to Left, Largest to Smallest
*/
void sort(void)
{
    int array[] = {5, 2, 1, 3, 6, 4};
    int swap_counter = 1;

    while(swap_counter != 0)
    {
        swap_counter = 0;
        for(int i = 0; i < 6; i++)
        {
            if(i == 6)
            {
                break;
            }
            if(array[i] > array[i+1])
            {
                int t = array[i];
                array[i] = array[i+1];
                array[i+1] = t;
                swap_counter++;
            }
        }
    }

    for(int i = 0; i < 6; i++)
    {
        printf("%i", array[i]);
    }
    printf("\n");
}