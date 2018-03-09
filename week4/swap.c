#include <stdio.h>
#include <cs50.h>

void swap(int * a, int * b);

int main(void)
{
    printf("x: ");
    int x = get_int();
    printf("y: ");
    int y = get_int();

    swap(&x, &y);

    printf("\nnew x: %i\n", x);
    printf("new y: %i\n", y);
}

void swap(int * a, int * b)
{
    int tmp = * a;
    * a = * b;
    * b = tmp;
}