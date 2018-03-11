#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <stdlib.h>
#include "functions.h"

#define INT_MAX 2147483647
#define UINT_MAX 4294967295
#define FLT_MAX 3.40282346638528859811704183484516925e+38F
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

float Get_Float(void)
{
    while (true)
    {
        char * line = Get_String();
        if (line == NULL)
        {
            return FLT_MAX;
        }

        char c; 
        float f;
        if (sscanf(line, " %f %c", &f, &c) == 1)
        {
            free(line);
            return f;
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