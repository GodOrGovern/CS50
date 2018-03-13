#include <stdio.h>
#include <cs50.h>

int main(void)
{
    int height = 0;

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

    // builds pyramid
    for (int row = 0; row < height; row++)
    {
        for (int i = 1; i < height - row; i++)
        {
            printf(" ");
        }

        for (int j = 0; j < row + 2; j++)
        {
            printf("#");
        }

        printf("\n");
    }
}
