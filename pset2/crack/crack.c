#define _XOPEN_SOURCE

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int permute(char *attempt, char salt[], char *argv [], int pos);

int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        printf("Error: Expected two command line inputs\n");
        return 1;
    }

    char salt[2];
    strncpy(salt, argv[1], 2);

    char *attempt;
    attempt = (char *)malloc(sizeof(char) * 5);

    int pos = 0;
    while (pos < 5)
    {
        if (permute(attempt, salt, argv, pos++))
        {
            printf("%s\n", attempt);
            free(attempt);
            return 0;
        }
    }

    free(attempt);
    printf("Couldn't find password\n");
    return 1;
}

int permute(char *attempt, char salt[], char *argv[], int pos)
{
    char *alphabet = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";

    for (int letter = 0; letter < 52; letter++)
    {
        attempt[pos] = alphabet[letter];
        
        if (pos > 0)
        {
            permute(attempt, salt, argv, pos - 1);
        }

        if (!(strcmp(crypt(attempt, salt), argv[1])))
        {
            return 1;
        }
    }

    return 0;
}