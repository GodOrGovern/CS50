#include <stdio.h>
#include <cs50.h>

void cough(void);

int main(void)
{
    cough();
}

void cough(void)
{
    printf("How many times would you like to cough? ");
    int n = get_int();
    for (int i = 0; i < n; i++)
    {
        printf("Cough\n");
    }
}