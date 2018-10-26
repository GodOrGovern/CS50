#include <stdio.h>
#include <cs50.h>
#include <string.h>

int main(void)
{
    printf("Input: ");
    char *s = get_string();

    if (s == NULL)
    {
        return 1;
    }

    printf("\n");

    for (int i = 0, n = strlen(s); i < n; i++)
    {
        printf("%c\n", *(s + i));
    }

    return 0;
}