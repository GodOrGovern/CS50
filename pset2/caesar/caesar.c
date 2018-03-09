#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <stdlib.h>

// encryption function - lower and upper set the operable bounds for encrypting a string
void encrypt(char lower, char upper);


// setting global variables so they can be used in encrypt( )
int k = 0;
int i = 0;
string p = 0;
int main(int argc, string argv[])
{
    // checks to make sure user typed exactly two arguments
    if (argc != 2)
    {
        printf("ERROR: There are not two command-line arguments\n");
        return 1;
    }

    // converts cmd-line input (argv[1]) to integer (k), then gets string (p) from user and finds length of string (n)
    k = atoi(argv[1]);
    printf("plaintext: ");
    p = get_string();
    int n = strlen(p);

    printf("ciphertext: ");

    // iterates i over the values 0 to n, increasing i by 1 each time
    for (i = 0; i < n; i++)
    {
        // see encryption function for more details
        encrypt('A', 'Z');
        encrypt('a', 'z');

        // checks if a character in p is a letter (if not it prints it without modification)
        if (p[i] < 'A' || (p[i] > 'Z' && p[i] < 'a') || p[i] > 'z')
        {
            printf("%c", p[i]);
        }
    }

    printf("\n");
}

// encrypts all characters within the given range
void encrypt(char lower, char upper)
{
    // stores the difference between the upper and lower bounds (range) as an integer
    int range = upper - lower;

    // checks if a character is within the set boundaries
    if (p[i] >= lower && p[i] <= upper)
    {
        // applies if k is less than or equal to range
        if (k <= range)
        {
            // if (character + k) is less than upper bound, print result of (character + k)
            if (p[i] + k <= upper)
            {
                printf("%c", p[i] + k);
            }

            // otherwise, find (character + k) mod (upper bound), add that value (minus 1) to lower bound, and print the result
            else
            {
                int remain = (p[i] + k) % (upper);
                printf("%c", lower + (remain - 1));
            }
        }

        // applies if k is more than range
        else
        {
            // divides k by (range + 1) and stores value of remainder in z
            div_t over = div(k, range + 1);
            int z = over.rem;

            // if (character + z) is less than upper bound, print result of (character + z)
            if (p[i] + z <= upper)
            {
                printf("%c", p[i] + z);
            }

            // otherwise, find (character + z) mod (upper bound), add that value (minus 1) to lower bound, and print the result
            else
            {
                int wrap = (p[i] + z) % (upper);
                printf("%c", lower + (wrap - 1));
            }
        }
    }
}