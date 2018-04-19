#define _XOPEN_SOURCE

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int generate(char *permute, int length);

int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        printf("Error: Expected two command line inputs\n");
        return 1;
    }

    char *salt;
    strncpy(salt, argv[1], 2);

    char *strn;
    int len = 0;
    while (len < 5)
    {
        if(generate(strn, len))
        {
            len++;
        }
        
        if (strncmp(crypt(strn, salt), argv[1], 13))
        {
            printf("%s\n", strn);
            return 0;
        }
    }

    printf("Couldn't find password\n");
    return 1;
}

int generate(char *permute, int length)
{
    
}