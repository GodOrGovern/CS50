#include <stdio.h>
#include <cs50.h>

int main(void)

{
    printf("Do you want to remove this file? ");
    char c = get_char();

    switch(c)
    {
        case 'y':
        case 'Y':
            printf("Yes\n");
            break;

        case 'n':
        case 'N':
            printf("No\n");
            break;

        default:
            printf("error\n");
    }
}