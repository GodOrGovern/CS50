// Declares a dictionary's functionality
#ifndef DICTIONARY_H
#define DICTIONARY_H

#include <stdbool.h>

// Maximum length for a word
#define LENGTH 45
#define ALPHA_LENGTH 26

// Variable type for trie node
typedef struct trie
{
    bool word_end;
    struct trie *children[ALPHA_LENGTH];
}
trie;

// Prototypes
bool check(const char *word);
bool load(const char *dictionary);
unsigned int size(void);
bool unload(void);

#endif // DICTIONARY_H
