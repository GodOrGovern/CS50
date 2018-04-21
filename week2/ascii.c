#include <stdio.h>

int main(void)
{
    for (int num = 65; num < 91; num++)
    {
        printf("%c = %i\n", num, num);
    }

    printf("\n");

    for (char letter = 'A'; letter <= 'Z'; letter++)
    {
        printf("%c = %i\n", letter, letter);
    }

    return 0;
}