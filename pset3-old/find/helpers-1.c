#include <stdio.h>
#include "helpers.h"

bool binary(int target, int array[], int low, int high);

bool search(int value, int values[], int n)
{
    if(binary(value, values, 0, n - 1))
    {
        return true;
    }

    return false;
}

bool binary(int target, int array[], int low, int high)
{
    if (low <= high)
    {
        int mid = low + (high - 1) / 2;

        if (target == array[mid])
        {
            return true;
        }

        if (target > array[mid])
        {
            return binary(target, array, mid + 1, high);
        }

        if (target < array[mid])
        {
            return binary(target, array, low, mid - 1);
        }
    }

    return false;
}

void sort(int values[], int n)
{
    int d, swap;

    for (d = 0; d < n - 1; d++)
    {
        if (values[d] > values[d + 1])
        {
            swap = values[d];
            values[d] = values[d + 1];
            values[d + 1] = swap;
        }
    }
}

