#include <stdio.h>
#include <cs50.h>

int main(void)
{
    printf("Value of x: ");
    int x = get_int();

    printf("Value of y: ");
    int y = get_int();

    printf("%i + %i = %i\n", x, y, x + y);
    printf("%i - %i = %i\n", x, y, x - y);
    printf("%i * %i = %i\n", x, y, x * y);
    printf("%i / %i = %i\n", x, y, x / y);
    printf("%i mod %i = %i\n", x, y, x % y);

    return 0;
}