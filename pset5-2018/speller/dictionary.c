#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <stdbool.h>
#include <string.h>

#include "dictionary.h"

#define ALPHA_LEN 27
#define CHAR_INDEX(c) ((int)(c - 'a'))

typedef struct trie
{
    bool leaf;
    struct trie *children[ALPHA_LEN];
}
trie;

int word_count;
bool loaded = false;
trie *root;

trie *get_node(void)
{
    trie *node = (trie *)malloc(sizeof(trie));
    node->leaf = false;

    for (int i = 0; i < ALPHA_LEN; i++)
    {
        node->children[i] = NULL;
    }

    return node;
}

void insert(const char *key)
{
    int len = strlen(key);
    trie *curr = root;

    for (int level = 0; level < len; level++)
    {
        int index = isalpha(key[level]) ? CHAR_INDEX(key[level]) : 26;
        if (!curr->children[index])
        {
            curr->children[index] = get_node();
        }

        curr = curr->children[index];
    }

    curr->leaf = true;
}

void free_trie(trie *node)
{
    for (int i = 0; i < ALPHA_LEN; i++) 
    {
        if (node->children[i]) 
        {
            free_trie(node->children[i]);
            node->children[i] = NULL;  
        }
    }
    
    free (node);
}

// Returns true if word is in dictionary else false
bool check(const char *word)
{
    int len = strlen(word);
    char low_word[len + 1];
    for (int i = 0; i < len; i++)
    {
        low_word[i] = tolower(word[i]);
    }
    
    low_word[len] = '\0';
    trie *curr = root;

    for (int level = 0; level < (len + 1); level++)
    {
        int index = isalpha(low_word[level]) ? CHAR_INDEX(low_word[level]) : 26;

        if (!curr->children[index])
        {
            return false;
        }

        curr = curr->children[index];
    }

    return (curr != NULL && curr->leaf);
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

    root = (trie *)malloc(sizeof(trie));

    char buf[45];
    while(fgets(buf, 45, dict) != NULL)
    {
        word_count++;
        insert(buf);
    }

    loaded = true;
    return true;
}

// Returns number of words in dictionary if loaded else 0 if not yet loaded
unsigned int size(void)
{
    if (!loaded)
    {
        return 0;
    }

    return word_count;
}

// Unloads dictionary from memory, returning true if successful else false
bool unload(void)
{
    if (root)
    {
        free_trie(root);
        return true;
    }
    return false;
}
