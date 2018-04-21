#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <ctype.h>

void encrypt(char lower, char upper, int cipher, char letter);

int main(int argc, string argv[])
{
    if (argc != 2)
    {
        printf("Error: expected two command line inputs\n");
        return 1;
    }

    int len_key = strlen(argv[1]);
    for (int spot = 0; spot < len_key; spot++)
    {
        if (!(isalpha(argv[1][spot])))
        {
            printf("Key can only contain letters\n");
            return 1;
        }
    }

    // get key from user input
    string buffer = argv[1];
    int key[len_key];
    for (int i = 0; buffer[i]; i++)
    {
        buffer[i] = toupper(buffer[i]);
        key[i] = buffer[i] - 65;
    }

    printf("plaintext: ");
    string plaintext = get_string();
    int len_text = strlen(plaintext);
    int pos_key = 0;

    printf("ciphertext: ");
    for (int pos = 0; pos < len_text; pos++)
    {
        if (isalpha(plaintext[pos]))
        {
            encrypt('a', 'z', key[pos_key % len_key], plaintext[pos]);
            encrypt('A', 'Z', key[pos_key % len_key], plaintext[pos]);
            pos_key++;
        }

        else
        {
            printf("%c", plaintext[pos]);
        }
    }

    printf("\n");
    return 0;
}

// use key to encrypt user plaintext within bounds
void encrypt(char lower, char upper, int cipher, char letter)
{
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