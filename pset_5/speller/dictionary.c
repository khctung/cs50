// Implements a dictionary's functionality

#include <ctype.h>
#include <stdbool.h>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>

#include "dictionary.h"

// Represents a node in a hash table
typedef struct node
{
    char word[LENGTH + 1];
    struct node *next;
}
node;

// TODO: Choose number of buckets in hash table
const unsigned int N = 26;

// Hash table
node *table[N];

// number of words in dictionary
int num_words = 0;

// Returns true if word is in dictionary, else false
bool check(const char *word)
{
    // getting hash value for the word
    int hash_value = hash(word);

    for (int i = 0; i < ; i++)
    {
        if (strcasecmp(table[hash_value].word, word) == 0)
        {
            return true;
        }
        
    }
    if (strcasecmp(table[hash(word)],word) == 0)
    {
        return true;
    }

    for each node in the linked list at table[index]:
        if the word in the node is the same as the word we're checking (ignoring case):
            return true
    return false;
}

// Hashes word to a number
unsigned int hash(const char *word)
{
    unsigned long total_chars = 0;
    for (int i = 0; i < str(word); i++)
    {
        total_chars = tolower(word[i]);
    }
    return total_chars % N;
}

// Loads dictionary into memory, returning true if successful, else false
bool load(const char *dictionary)
{
    // Open the dictionary file
    FILE *source = fopen(dictionary, "r");

    if (file == NULL)
    {
        printf("Error opening file.\n");
        return false;
    }

    char word[LENGTH+1];

    // Read each word in the file
    while (fscanf(source, "%s", word) != EOF)
    {
        // Add each word to the hash table
        node *new_node = malloc(sizeof(node));
        if (new_node == NULL)
        {
            unload();
            return false;
        }

        // copying the word into new node
        strcpy(new_node->word, word);

        // getting the "bin" of the word
        int index = hash(word);

        // adding the node to the bin in the hash table
        new_node->next = table[index]
        table[index] = new_node

        num_words++;
    }

    // Close the dictionary file
    fclose(source);
    return true;
}

// Returns number of words in dictionary if loaded, else 0 if not yet loaded
unsigned int size(void)
{
    // if dictionary not loaded, then num_words would be 0
    if (num_words == 0)
    {
        return 0;
    }
    // if dictionary loaded, then can just return num_words
    return num_words;
}

// Unloads dictionary from memory, returning true if successful, else false
bool unload(void)
{
    // TODO
    return false;
}
