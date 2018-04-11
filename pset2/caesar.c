#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <stdlib.h>

// encryption function - lower and upper set the operable bounds for encrypting a string
void encrypt(char lower, char upper, int cipher, int letter, string text);

int main(int argc, string argv[])
{
    if (argc != 2)
    {
        printf("ERROR: Expected two command-line arguments\n");
        return 1;
    }

    int key = atoi(argv[1]);
    printf("plaintext: ");
    string plaintext = get_string();
    int length = strlen(plaintext);

    printf("ciphertext: ");

    // encrypts all letters input by the user
    for (int position = 0; position < length; position++)
    {
        encrypt('A', 'Z', key, position, plaintext);
        encrypt('a', 'z', key, position, plaintext);

        if (plaintext[position] > 'z' || plaintext[position] < 'A' || (plaintext[position] > 'Z' && plaintext[position] < 'a'))
        {
            printf("%c", plaintext[position]);
        }
    }

    printf("\n");
}

// encrypts all characters within the given range
void encrypt(char lower, char upper, int cipher, int letter, string text)
{
    int range = upper - lower;

    // adjusts algorithm for encryption based off letter and key
    if (text[letter] >= lower && text[letter] <= upper)
    {
        if (cipher <= range)
        {
            if (text[letter] + cipher <= upper)
            {
                printf("%c", text[letter] + cipher);
            }

            else
            {
                int remain = (text[letter] + cipher) - (upper);
                printf("%c", lower + (remain - 1));
            }
        }

        else
        {
            div_t over = div(cipher, range + 1);
            int remain = over.rem;

            if (text[letter] + remain <= upper)
            {
                printf("%c", text[letter] + remain);
            }

            else
            {
                int wrap = (text[letter] + remain) - (upper);
                printf("%c", lower + (wrap - 1));
            }
        }
    }
}