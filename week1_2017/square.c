#include <stdio.h>
#include <cs50.h>

int squared(int num);

int main(void)
{
    printf("Number: ");
    int num = get_int();

    printf("%i^2 is %i\n", num, squared(num));

    return 0;
}

int squared(int num)
{
    return num * num;
}