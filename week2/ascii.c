#include <stdio.h>

int main(void)
{
    for (int i = 65; i < 91; i++)
    {
        printf("%c = %i\n", i, i);
    }

    printf("\n");

    for (char c = 'A'; c <= 'Z'; c++)
    {
        printf("%c = %i\n", c, c);
    }
}