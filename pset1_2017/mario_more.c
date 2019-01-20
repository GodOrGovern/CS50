#include <stdio.h>
#include <string.h>
#include <cs50.h>

int main(void)
{
    int height;
    do
    {
        printf("Height: ");
        height = get_int();

        if (height == 0)
        {
            return 0;
        }
    }
    while (height < 1 || height > 23);

    for (int row = 0; row < height; row++)
    {
        for (int i = 1; i < height - row; i++)
        {
            printf(" ");
        }

        for (int j = 0; j < row + 1; j++)
        {
            printf("#");
        }

        printf("  ");

        for (int k = 0; k < row + 1; k++)
        {
            printf("#");
        }

        printf("\n");
    }
}
