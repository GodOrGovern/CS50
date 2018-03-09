#include <stdio.h>
#include <cs50.h>
#include <string.h>

int main(void)
{
    // get string (s) from user
    printf("Input: ");
    string s = get_string();

    // make sure s is a valid string
    if (s != NULL)
    {
        // print each character in s on a separate line
        for (int i = 0, n = strlen(s); i < n; i++)
        {
            printf("%i = %c\n", i, s[i]);
        }
    }
}