#include <stdio.h>
#include <cs50.h>
#include <string.h>

int main(void)
{
    printf("What would you like to capitalize? ");
    string s = get_string();

    if (s != NULL)
    {
        int n = strlen(s);
        char array[n];
        sprintf(array, "%s", s);

        for (int i = 0; i < n; i++)
        {
            if (array[i] >= 97 && array[i] <= 122)
            {
                array[i] = array[i] - 32;
            }

            printf("%c", array[i]);
        }
    }

    printf("\n");
}