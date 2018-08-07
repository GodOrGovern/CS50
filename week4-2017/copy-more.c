#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <ctype.h>

int main(void)
{
    printf("s: ");
    char * s = get_string();

    if (s == NULL)
    {
        return 1;
    }

    char * t = malloc((strlen(s) + 1) * sizeof(char));

    if (t == NULL)
    {
        return 2;
    }

    for (int i = 0, n = strlen(s); i <= n; i++)
    {
        t[i] = s[i];
    }

    if (strlen(t) > 0)
    {
        t[0] = toupper(t[0]);
    }

    printf("\ns: %s\n", s);
    printf("t: %s\n", t);

    free(t);
    return 0;
}