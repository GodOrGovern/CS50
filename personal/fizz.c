#include <stdio.h>

void fizz(int a);

int main(void)
{
    int b = 0;
    while(b < 100)
    {
        fizz(b + 1);
        b++;
    }
}

void fizz(int a)
{ 
    if (a % 15 == 0)
    {
        printf("FizzBuzz\n");
    }

    else if (a % 3 == 0)
    {
        printf("Fizz\n");
    }

    else if (a % 5 == 0)
    {
        printf("Buzz\n");
    }

    else
    {
        printf("%i\n", a);
    }
}