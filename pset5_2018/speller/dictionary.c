#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <stdbool.h>
#include <string.h>

#include "dictionary.h"

#define ALPHA_LEN 27
#define CHAR_INDEX(c) ((int)(tolower(c) - 'a'))

int word_count = 0;
bool loaded = false;
int table[5490] = { 0 };

int get_hash(const char* word)
{
    int hash = 0;
    for (int i = 0; word[i] != '\0' && word[i] != '\n'; i++)
    {
        hash += tolower(word[i]);
    }

    return hash;
}

void insert(const char *key)
{
    table[get_hash(key)] = true;
}

// Returns true if word is in dictionary else false
bool check(const char *word)
{
    return table[get_hash(word)];
}

// Loads dictionary into memory, returning true if successful else false
bool load(const char *dictionary)
{
    FILE *dict = fopen(dictionary, "r");
    if (dict == NULL)
    {
        fprintf(stderr, "Could not open %s\n", dictionary);
        return false;
    }

    char buf[LENGTH + 1];
    while (fgets(buf, LENGTH + 2, dict) != NULL)
    {
        word_count++;
        insert(buf);
    }

    fclose(dict);
    loaded = true;
    return true;
}

// Returns number of words in dictionary if loaded else 0 if not yet loaded
unsigned int size(void)
{
    return !loaded ? 0 : word_count;
}

// Unloads dictionary from memory, returning true if successful else false
bool unload(void)
{
    return true;
}
