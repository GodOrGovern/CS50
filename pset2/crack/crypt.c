#define _XOPEN_SOURCE

#include <unistd.h>
#include <stdio.h>
#include <cs50.h>

int main(int argc, string argv[])
{
    if (argc != 2)
    {
        printf("Error: Incorrect number of arguments\n");
        printf("Usage: ./crypt word\n");
        return 1;
    }

    string s = crypt(argv[1], "50");
    printf("%s\n", s);

    return 0;
}