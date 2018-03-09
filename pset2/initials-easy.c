#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <ctype.h>

int main(void)
{
    string s = get_string();
    printf("%c", toupper(s[0]));

    for (int n = 0, i = strlen(s); n < i; n++)
    {
        if (s[n] == ' ')
        {
            printf("%c", toupper(s[n + 1]));
        }
    }

    printf("\n");
}