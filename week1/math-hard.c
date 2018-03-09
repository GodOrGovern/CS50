#include <stdio.h>
#include <cs50.h>

int main(void)
{
    printf("Value of x: ");
    float x = get_float();

    printf("Value of y: ");
    float y = get_float();

    printf("%f + %f = %f\n", x, y, x + y);
    printf("%f - %f = %f\n", x, y, x - y);
    printf("%f * %f = %f\n", x, y, x * y);
    printf("%f / %f= %f\n", x, y, x / y);
}