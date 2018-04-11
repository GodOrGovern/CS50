#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

void encrypt(char lower, char upper, int cipher, char letter);

int main(int argc, string argv[])
{
    if (argc != 2)
    {
        printf("ERROR: Expected two command-line arguments\n");
        return 1;
    }

    int key = atoi(argv[1]) % 26;
    printf("plaintext: ");
    string plaintext = get_string();
    int length = strlen(plaintext);

    printf("ciphertext: ");

    // encrypts all letters input by the user
    for (int pos=0; pos < length; pos++)
    {
        if (isalpha(plaintext[pos]))
        {
            encrypt('A', 'Z', key, plaintext[pos]);
            encrypt('a', 'z', key, plaintext[pos]);
        }
        
        else
        {
            printf("%c", plaintext[pos]);
        }    
    }

    printf("\n");
    return 0;
}

void encrypt(char lower, char upper, int cipher, char letter)
{
    // adjusts algorithm for encryption based off letter and key
    if (letter >= lower && letter <= upper)
    {
        if (letter + cipher <= upper)
        {
            printf("%c", letter + cipher);
        }

        else
        {
            int remain = (letter + cipher) - (upper);
            printf("%c", lower + (remain - 1));
        }
    }
}