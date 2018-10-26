#include <cs50.h>
#include <stdio.h>

int main(void)
{
    int *numbers = NULL;
    int capacity = 0;

    int size = 0;
    while (true)
    {
        int number = get_int("Number: ");

        if (number = INT_MAX)
        {
            break;
        }

        bool found = false;
        for (int i = 0; i < size; i++)
        {
            if (numbers[i] == number)
            {
                found = true;
                break;
            }
        }

        if (!found)
        {
            if (size == capacity)
            {
                numbers = realloc(numbers, sizeof(int) * (size + 1));
                if (!numbers)
                {
                    return 1;
                }
                
                capacity++;
            }

            numbers[size] = number;
            size++;
        }
    }

    for (int i = 0; i < size; i++)
    {
        printf("%i\n", numbers[i]);
    }
}