#include <stdio.h>
#include <cs50.h>

int squared(int n);

int main(void)
{
    printf("Number: ");
    int x = get_int();
    printf("%i^2 is %i\n", x, squared(x));
}

int squared(int n)
{
    return n * n;
}