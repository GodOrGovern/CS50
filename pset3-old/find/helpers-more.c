#include <stdio.h>
#include "helpers.h"

bool binary(int value, int values[], int low, int high);
void count(int values[], int n, int exp);

bool search(int value, int values[], int n)
{
    if(binary(value, values, 0, n - 1))
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
    int max = values[0];
    for (int i = 0; i < n; i++)
    {
        if (max < values[i])
        {
            max = values[i];
        }
    }

    int exp;
    for (exp = 1; (max / exp) > 0; exp *= 10)
    {
        count(values, n, exp);
    }
}

void count(int values[], int n, int exp)
{
    int output[n];
    int i, count[10] = { 0 };

    for (i = 0; i < n; i++)
    {
        count[(values[i] / exp) % 10]++;
    }

    for (i = 1; i < 10; i++)
    {
        count[i] += count[i - 1];
    }

    for (i = n - 1; i >= 0; i--)
    {
        output[count[(values[i] / exp) % 10] - 1] = values[i];
        count[(values[i] / exp) % 10]--;
    }

    for (i = 0; i < n; i++)
    {
        values[i] = output[i];
    }
}