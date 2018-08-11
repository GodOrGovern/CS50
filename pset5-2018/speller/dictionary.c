#include <stdbool.h>

#include "dictionary.h"

#define ALPHA_LENGTH 27

typedef struct trie
{
    bool leaf;
    struct trie *children[ALPHA_LENGTH];
}
trie;

trie get_node()
{
    trie *node = (trie *)malloc(sizeof(trie));
    node->leaf = false;

    for (int i = 0; i < ALPHA_LENGTH; i++)
    {
        node->character[i] = NULL;
    }

    return node;
}

// Returns true if word is in dictionary else false
bool check(const char *word)
{
    // TODO
    return false;
}

// Loads dictionary into memory, returning true if successful else false
bool load(const char *dictionary)
{
    // TODO
    return false;
}

// Returns number of words in dictionary if loaded else 0 if not yet loaded
unsigned int size(void)
{
    // TODO
    return 0;
}

// Unloads dictionary from memory, returning true if successful else false
bool unload(void)
{
    // TODO
    return false;
}
