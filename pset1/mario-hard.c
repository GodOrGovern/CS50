#include <cs50.h>
#include <stdio.h>
#include <string.h>

int main(void)
{
    check:
    printf("Height: ");
    int height = get_int();
    int row = 1;
    int count = 1;

    if (height > 0 && height <= 23)
    {
        for (row = 1; row - 1 < height; row++)
        {
            for (count = 1; count - 1 < height - row; count++ )
            {
                printf(" ");
            }

            for (count = 1; count - 1 < row; count++)
            {
                printf("#");
            }

            printf("  ");

            for (count = 1; count - 1 < row; count++)
            {
                printf("#");
            }

            printf("\n");
        }
    }

    else if (height == 0)
    {
        printf("\n");
    }

    else
    {
        goto check;
    }
}
