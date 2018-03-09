#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <ctype.h>

int main(void)
{
    string s = get_string();

    if (s[0] != ' ' && s[0] != '\0')
    {
        printf("%c", toupper(s[0]));
    }

    // checks for spaces over the length of the name and prints character right after space
    for (int n = 0, i = strlen(s); n < i; n++)
    {
        while (s[n] == ' ')
        {
            n++;
        }

        if (s[n - 1] == ' ' && s[n] != '\0')
        {
            printf("%c", toupper(s[n]));
        }
    }

    printf("\n");
}