#include <stdio.h>
#include <cs50.h>

int main(void)
{
    int n = 1;
    for (int i = 0; i < 64; i++)
    {
        printf("Value of n: %i\n", n);
        n *= 2;
    }
}