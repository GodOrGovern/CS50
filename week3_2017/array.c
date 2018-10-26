#include <stdio.h>
#include <cs50.h>
#include <string.h>

int main(int argc, string argv[])
{
    if (argc == 1)
    {
        printf("Error: Incorrect number of cmd-line arguments\n");
        return 1;
    }

    printf("What character would you like to search for: ");
    char c = get_char();
    int count = 0;
    
    for (int k = 1; k < argc; k++)
    {
        int n = strlen(argv[k]);
        
        for (int i = 0; i < n; i++)
        {
            if (argv[k][i] == c)
            {
                string s[4];
                s[0] = "st";
                s[1] = "nd";
                s[2] = "rd";
                s[3] = "th";

                int rem = (i + 10) % 10;

                if (rem <= 2 && (i < 10 || i > 1))
                {
                    printf("%c is the %i%s character in %s\n", c, i + 1, s[rem], argv[k]);
                }

                else
                {
                    printf("%c is the %i%s character in %s\n", c, i + 1, s[3], argv[k]);
                }

                count++;
            }
        }
    }

    if (count > 0)
    {
        return 0;
    }
    
    for (int o = 1; o < argc; o++)
    {
        printf("Error: Unable to locate %c in %s\n", c, argv[o]);
    }
    
    return 2;
}