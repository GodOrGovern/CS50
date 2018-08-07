#include <stdio.h>
#include <cs50.h>

void cough(void);

int main(void)
{
    cough();
    return 0;
}

void cough(void)
{
    printf("How many times would you like to cough? ");
    int n_times = get_int();
    for (int i = 0; i < n_times; i++)
    {
        printf("Cough\n");
    }
}