#include <stdio.h>
#include <cs50.h>

int sigma(int a);

int main(void)
{
    int n = 0;

    do
    {
        printf("Input: ");
        n = get_int();
    }
    while (n <= 0);

    for (int i = 1; i <= n; i++)
    {
        printf("Sigma(%i) = %i\n", i, sigma(i));
    }
}

int sigma(int a)
{
    if (a <= 0)
    {
        return 0;
    }

    else
    {
        return (a + sigma(a - 1));
    }
}