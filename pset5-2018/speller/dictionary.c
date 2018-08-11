#include <stdbool.h>
#include <string.h>

#include "dictionary.h"

#define ALPHA_LENGTH 27
#define CHAR_INDEX(c) ((int)(c - 'a'))

typedef struct trie
{
    bool leaf;
    struct trie *children[ALPHA_LENGTH];
}
trie;

trie *root;

trie *get_node(void)
{
    trie *node = (trie *)malloc(sizeof(trie));
    node->leaf = false;

    for (int i = 0; i < ALPHA_LENGTH; i++)
    {
        node->character[i] = NULL;
    }

    return node;
}

void insert(const char *key)
{
    int length = strlen(key);
    trie *curr = root;

    for (int level = 0; level < length; level++)
    {
        int index = CHAR_INDEX(key[level]);
        if (!curr->children[index])
        {
            curr->children[index] = get_node();
        }

        curr = curr->children[index];
    }

    curr->leaf = true;
}

unsigned int word_count()
{
    int result = 0;
 
    if (root->leaf)
    {
        result++;
    }
     
    for (int i = 0; i < ALPHABET_SIZE; i++)
    {
        if (root->children[i])
        {
            result += word_count(root->children[i]);
        }
    }
    
    return result;
}

void lowercase(char *word)
{
    int i = 0;
    while (word[i])
    {
        putchar(tolower(word[i]));
        i++;
    }
}

// Returns true if word is in dictionary else false
bool check(const char *word)
{
    char *low_word = lowercase(word);

    trie *curr = root;

    int length = strlen(low_word);
    for (int level = 0; level < length; level++)
    {
        int index = CHAR_INDEX(word[level]);

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
    while((buf = fgets(buf, 45, dict)) != EOF)
    {
        insert(buf);
    }

    return false;
}

// Returns number of words in dictionary if loaded else 0 if not yet loaded
unsigned int size(void)
{
    if (!load())
    {
        return 0;
    }

    return word_count();
}

// Unloads dictionary from memory, returning true if successful else false
bool unload(void)
{
    // TODO
    return false;
}
