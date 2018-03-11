#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include "../extra/functions.h"

int main(void)
{
    printf("Credit Card Number: ");
    long long n_credit = Get_LongLong();

    // gets length of input and tests for validity
    int n_digits = floor(log10(llabs(n_credit))) + 1;
    switch (n_digits)
    {
        case 13:
        case 15:
        case 16:
            break;

        default:
            printf("INVALID\n");
            return 0;
    }

    // transfers input to array
    int array[n_digits];
    for (int i = n_digits - 1; i >= 0; i--)
    {
        array[i] = n_credit % 10;
        n_credit = n_credit / 10;
    }

    // performs checksum on digits in the array
    int n_check = 0;
    for (int j = n_digits - 1; j >= 0; j--)
    {
        if ((n_digits - j) % 2 == 0)
        {
            int buf_array[2];
            int buf_num;
            buf_num = array[j] * 2;
            buf_array[0] = buf_num % 10;
            buf_array[1] = buf_num / 10;
            n_check = n_check + buf_array[0] + buf_array[1];
        }

        else
        {
            n_check = n_check + array[j];
        }
    }

    // validates checksum
    switch (n_check % 10)
    {
        case 0:
            break;

        default:
            printf("INVALID\n");
            return 0;
    }

    // test to see if input is visa
    switch (n_digits)
    {
        case 13:
            if (array[0] == 4)
            {
                printf("VISA\n");
                return 0;
            }

            else
            {
                printf("INVALID\n");
                return 0;
            }

        case 16:
            if (array[0] == 4)
            {
                printf("VISA\n");
                return 0;
            }

        default:
            break;
    }

    // test to see if input is amex or mastercard
    int n_initial = (array[0] * 10) + array[1];
    switch (n_initial)
    {
        case 34:
        case 37:
            if (n_digits == 15)
            {
                printf("AMEX\n");
                return 0;
            }

            else
            {
                printf("INVALID\n");
                return 0;
            }

        case 51:
        case 52:
        case 53:
        case 54:
        case 55:
            if (n_digits == 16)
            {
                printf("MASTERCARD\n");
                return 0;
            }

            else
            {
                printf("INVALID\n");
                return 0;
            }

        default:
            printf("INVALID\n");
            return 0;
    }
}
