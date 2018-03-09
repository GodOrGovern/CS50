#include <stdio.h>
#include <cs50.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

// function that encrypts string p - lower and upper set the operable bounds for encrypting a string
void encrypt(char lower, char upper);

int o = 0;      // will be length of second command-line input
int n = 0;      // will be length of string p - the text being encrypted
string p = 0;   // will be string p - the text being encrypted
int key[100];   // will be array that is used to store values from argv[1] and encrypt p
int j = 0;      // will be counter that is increased no matter what the character in p is
int c = 0;      // will be a counter that is only increased if a character in p is a letter

// argv[1] will be used to encrypt p
int main(int argc, string argv[])
{
    // checks to make sure the user typed exactly two cmd-line arguments (if not it prints an error)
    if (argc != 2)
    {
        printf("Error: Incorrect number of command line arguments\n");
        return 1;
    }

    /* assigns length of second cmd-line input (encryption key) to o and checks to see if all characters in
    argv[1] are alphabetic (if not it prints an error) */
    o = strlen(argv[1]);
    for (int i = 0; i < o; i++)
    {
        if (argv[1][i] < 'A' || (argv[1][i] > 'Z' && argv[1][i] < 'a') || argv[1][i] > 'z')
        {
            printf("Error: Argument contains non-alphabetic characters\n");
            return 1;
        }
    }

    // prompts user for "plaintext" and stores input as string p, which will be encrypted using argv[1]
    // assigns the length of p to n
    printf("plaintext: ");
    p = get_string();
    n = strlen(p);

    printf("ciphertext: ");

    /* j is increased by 1 after completion of these various functions, so this effectively iterates j
    over the values 0 to n, increasing j by 1 each time */
    while (j < n)
    {
        /* finds the remainder when j is divided by o (for simplicity, think of remainder as r) -
        converts the r(th) character in argv[1] into a number so that 'A' and 'a' are 0, 'B' and 'b' are 1 (etc.) -
        assigns that value to the j(th) integer in key */
        div_t wrap = div(j, o);
        key[j] = toupper(argv[1][wrap.rem]) - 65;

        // checks if a character in p is a letter (if not it prints it without modifications)
        if (p[j] < 'A' || (p[j] > 'Z' && p[j] < 'a') || p[j] > 'z')
        {
            printf("%c", p[j]);
            j++;
        }

        // see encryption function for more details
        else
        {
            encrypt('A', 'Z');
            encrypt('a', 'z');
        }
    }

    printf("\n");
}

// encrypts all characters within the given range
void encrypt(char lower, char upper)
{
    // checks if a character is within the set boundaries
    if (p[j] >= lower && p[j] <= upper)
    {
        /* if the j(th) character in p plus the c(th) character in key is less than
        the upper bound, print result of p[j] + key[c] */
        if (key[c] + p[j] <= upper)
        {
            printf("%c", p[j] + key[c]);
        }

        /* otherwise, assign the result of (p[j] + key[c]) mod (upper bound) to remain,
        add (remain - 1) to (lower bound), and print the result */
        else
        {
            int remain = (p[j] + key[c]) % (upper);
            printf("%c", lower + (remain - 1));
        }

        // increase both counters by 1
        j++;
        c++;
    }
}