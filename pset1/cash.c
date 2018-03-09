#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <ctype.h>

int main(void)
{
    float change = 0;
    int okay = 0;

    // prompts until user inputs positive number
    while (!okay)
    {
        char n_input[22];
        printf("Change owed: ");
        fflush(stdout);

        if (fgets(n_input, sizeof n_input, stdin))
        {
            char *chk = NULL;
            change = strtof(n_input, &chk);

            if ((isspace(*chk) || *chk == 0) && change >= 0)
            {
                okay = 1;
            }
        }
    }

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

