#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <stdlib.h>
#include "../include/functions.h"

#define INT_MAX 2147483647
#define UINT_MAX 4294967295
#define LLONG_MAX 9223372036854775807

char * Get_String(void)
{
    char * buffer = NULL;
    unsigned int capacity = 0;
    unsigned int n = 0;
    int c;

    while ((c = fgetc(stdin)) != '\n' && c != EOF)
    {
        if (n + 1 > capacity)
        {
            if (capacity == 0)
            {
                capacity = 32;
            }

            else if (capacity <= (UINT_MAX / 2))
            {
                capacity *= 2;
            }

            else
            {
                free(buffer);
                return NULL;
            }

            char * temp = realloc(buffer, capacity * sizeof(char));
            if (temp == NULL)
            {
                free(buffer);
                return NULL;
            }
            buffer = temp;
        }

        buffer[n++] = c;
    }

    if (n == 0 && c == EOF)
    {
        return NULL;
    }

    char * minimal = malloc((n + 1) * sizeof(char));
    strncpy(minimal, buffer, n);
    free(buffer);

    minimal[n] = '\0';
    return minimal;
}

int Get_Int(void)
{
    while (true)
    {
        char * line = Get_String();
        if (line == NULL)
        {
            return INT_MAX;
        }

        int n; 
        char c;
        if (sscanf(line, " %d %c", &n, &c) == 1)
        {
            free(line);
            return n;
        }

        else
        {
            free(line);
            printf("Retry: ");
        }
    }
}


long long Get_LongLong(void)
{
    while (true)
    {
        char * line = Get_String();
        if (line == NULL)
        {
            return LLONG_MAX;
        }

        char c;
        long long n; 
        if (sscanf(line, " %lld %c", &n, &c) == 1)
        {
            free(line);
            return n;
        }

        else
        {
            free(line);
            printf("Retry: ");
        }
    }
}