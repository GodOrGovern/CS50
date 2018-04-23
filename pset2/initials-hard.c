#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <ctype.h>

int main(void)
{
    string name = get_string();

    if (name[0] != ' ' && name[0] != '\0')
    {
        printf("%c", toupper(name[0]));
    }
    
    for (int pos = 0, len = strlen(name); pos < len; pos++)
    {
        while (name[pos] == ' ')
        {
            pos++;
        }

        if (name[pos - 1] == ' ' && name[pos] != '\0')
        {
            printf("%c", toupper(name[pos]));
        }
    }

    printf("\n");
}