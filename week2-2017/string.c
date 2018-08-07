#include <stdio.h>
#include <cs50.h>
#include <string.h>

int main(void)
{
    printf("Input: ");
    string word = get_string();

    if (word != NULL)
    {
        for (int pos = 0, len = strlen(word); pos < len; pos++)
        {
            printf("%i = %c\n", pos, word[pos]);
        }
    }

    return 0;
}