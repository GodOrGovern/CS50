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

    for (int row = 1; row - 1 < height; row++)
    {
        for (int i = 1; i - 1 < height - row; i++ )
        {
            printf(" ");
        }

        for (int j = 1; j - 1 < row; j++)
        {
            printf("#");
        }

        printf("  ");

        for (int k = 1; k - 1 < row; k++)
        {
            printf("#");
        }

        printf("\n");
    }
}
