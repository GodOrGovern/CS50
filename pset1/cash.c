#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <cs50.h>

int main(void)
{
    float change = 0;
    do
    {
        printf("Change owed: ");
        change = get_float();
    }
    while (change < 0);

    // array with with values for each coin (in cents)
    int cents = round(change * 100);
    int coins[3] = {25, 10, 5};
    int minimum = 0;

    // determining minimum number of coins
    for (int i = 0; i < 3; i++)
    {
        minimum += cents / coins[i];
        cents %= coins[i];
    }

    printf("%i\n", minimum + cents);
    return 0;
}

