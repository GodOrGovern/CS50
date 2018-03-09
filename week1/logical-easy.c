#include <stdio.h>
#include <cs50.h>

int main(void)
{
    printf("Would you like to remove this file? ");
    char c = get_char();

    if (c == 'y' || c == 'Y')
    {
        printf("Yes\n");
    }

    else if (c == 'n' || c == 'N')
    {
        printf("No\n");
    }

    else
    {
        printf("Error\n");
    }
}