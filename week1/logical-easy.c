#include <stdio.h>
#include <cs50.h>

int main(void)
{
    printf("Would you like to remove this file? ");
    char choice = get_char();

    if (choice == 'y' || choice == 'Y')
    {
        printf("Yes\n");
    }

    else if (choice == 'n' || choice == 'N')
    {
        printf("No\n");
    }

    else
    {
        printf("Error\n");
    }

    return 0;
}