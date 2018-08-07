#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <ctype.h>

int main(void)
{
    string name = get_string();
    printf("%c", toupper(name[0]));

    for (int pos = 0, len = strlen(name); pos < len; pos++)
    {
        if (name[pos] == ' ')
        {
            printf("%c", toupper(name[pos + 1]));
        }
    }

    printf("\n");
}