#include <stdio.h>
#include <cs50.h>
#include <string.h>

int main(void)
{
    printf("What would you like to capitalize? ");
    string word = get_string();

    if (word != NULL)
    {
        int len = strlen(word);
        char array[len];
        sprintf(array, "%s", word);

        for (int pos = 0; pos < len; pos++)
        {
            if (array[pos] >= 97 && array[pos] <= 122)
            {
                array[pos] = array[pos] - 32;
            }

            printf("%c", array[pos]);
        }
    }

    printf("\n");
    
    return 0;
}