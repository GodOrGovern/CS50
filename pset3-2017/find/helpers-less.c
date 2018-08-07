#include <stdio.h>
#include "helpers.h"

bool binary(int value, int values[], int low, int high);

bool search(int value, int values[], int n)
{
    if (binary(value, values, 0, n - 1))
    {
        return true;
    }

    return false;
}

bool binary(int value, int values[], int low, int high)
{
    if (low <= high)
    {
        int mid = low + (high - 1) / 2;

        if (value == values[mid])
        {
            return true;
        }

        if (value > values[mid])
        {
            return binary(value, values, mid + 1, high);
        }

        if (value < values[mid])
        {
            return binary(value, values, low, mid - 1);
        }
    }

    return false;
}

void sort(int values[], int n)
{
    int index, buffer;
    while (n > 0)
    {
        for (index = 0; index < n - 1; index++)
        {
            if (values[index] > values[index + 1])
            {
                buffer = values[index];
                values[index] = values[index + 1];
                values[index + 1] = buffer;
            }
        }
        
        return sort(values, n - 1);
    }
}