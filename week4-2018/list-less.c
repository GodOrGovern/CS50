#include <cs50.h>
#include <stdio.h>

int main(void)
{
    int capacity;
    do
    {
        capacity = get_int("Capacity: ");
    }
    while (capacity < 1);

    int numbers[capacity];

    int size = 0; 
    while (size < capacity)
    {
        int number = get_int("Number: ");
        
        bool found = false
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
            numbers[size] = number;
            size++;
        }
    }

    for (int i = 0; i < size; i++)
    {
        print("%i\n", numbers[i]);
    }
}