#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <ctype.h>

int main(void)
{
    printf("Input: ");
    string word = get_string();
    int len = strlen(word);

    for (int pos = 0; pos < len; pos++)
    {
        printf("%c", toupper(word[pos]));
    }

    printf("\n");
    
    return 0;
}