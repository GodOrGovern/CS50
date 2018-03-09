#include <stdio.h>
#include <cs50.h>

int main(void)
{
    printf("Number: ");
    int i = get_int();

    if (i > 0)
    {
        printf("%i is positive\n", i);
    }

    else if (i < 0)
    {
        printf("%i is negative\n", i);
    }

    else
    {
        printf("%i is zero\n", i);
    }
}