#define _XOPEN_SOURCE

#include <unistd.h>
#include <stdio.h>
#include <cs50.h>
#include <string.h>

int main(int argc, string argv[])
{
    char salt[2];
    char line[128];
    FILE * fp[6];

    if (argc != 2)
    {
        printf("Error: Incorrect number of arguments\n");
        printf("Usage: ./crack userinput\n");
        return 1;
    }

    strncpy(salt, argv[1], 2);

    for (int k = 0; k <= 5; k++)
    {
        char *string[50];
        sprintf(string[0], "files/new%i.txt", k);
        fp[k] = fopen(string[0], "r");

        if (fp[k] == NULL)
        {
            printf("Unable to open file\n");
            return 2;
        }
    }

    int file = 0;
    while (fgets(line, sizeof(line), fp[file]) && file < 6)
    {
        int length = strlen(line) - 1;
        char actual[1];
        if (length == 1 && line[0] != '~')
        {
            actual[0] = line[0];
            char * ptr = malloc(2 * length);
            ptr[0] = actual[0];
            ptr[1] = '\0';
            char * attempt;
            attempt = crypt(ptr, salt);
            if (strcmp(attempt, argv[1]) == 0)
            {
                printf("%c\n", actual[0]);
                fclose(fp[file]);
                return 0;
            }
        }

        else if (line[0] != '~')
        {
            strncpy(actual, line, length);
            char * attempt;
            attempt = crypt(actual, salt);
            if (strcmp(attempt, argv[1]) == 0)
            {
                printf("%s\n", actual);
                fclose(fp[file]);
                return 0;
            }
        }

        else
        {
            fclose(fp[file]);
            file++;
        }
    }

    printf("Couldn't find password\n");
    return 1;
}
