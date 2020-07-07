#include <stdio.h>
#include <cs50.h>

int factorial(int n);

int main(void)
{
    int f = factorial(5);
    printf("%i\n", f);
}

int factorial(int n)
{

    //Base Case:
    if(n == 1)
        return 1;
    //Recursive Case:
    else
        return n*factorial(n-1);
}