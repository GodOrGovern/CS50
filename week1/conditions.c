#include <stdio.h>
#include <cs50.h>

int main(void)
{
    printf("Number: ");
    int input = get_int();

    if (input > 0)
    {
        printf("%i is positive\n", input);
    }

    else if (input < 0)
    {
        printf("%i is negative\n", input);
    }

    else
    {
        printf("%i is zero\n", input);
    }

    return 0;
}