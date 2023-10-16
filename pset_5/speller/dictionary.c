// Implements a dictionary's functionality

#include <ctype.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <strings.h>

#include "dictionary.h"

// Represents a node in a hash table
typedef struct node
{
    char word[LENGTH + 1];
    struct node *next;
} node;

// TODO: Choose number of buckets in hash table (bigger the less overlap!)
const unsigned int N = 5000;

// Hash table
node *table[N];

// number of words in dictionary
int num_words = 0;

// Returns true if word is in dictionary, else false
bool check(const char *word)
{
    // getting hash value for the word
    int hash_value = hash(word);

    // start at beginning of the nodes
    node *check_node = table[hash_value];

    // while not at the end of the list
    while (check_node)
    {
        // check if word is matching node
        if (strcasecmp(check_node->word, word) == 0)
        {
            return true;
        }
        // if not, then move on to next node
        check_node = check_node->next;
    }
    return false;
}

// Hashes word to a number
unsigned int hash(const char *word)
{
    unsigned long total_chars = 0;

    // basically i want the total ascii value of chars in the word % number of bins
    for (int i = 0; i < strlen(word); i++)
    {
        total_chars += toupper(word[i]);
    }
    return total_chars % N;
}

// Loads dictionary into memory, returning true if successful, else false
bool load(const char *dictionary)
{
    // Open the dictionary file
    FILE *source = fopen(dictionary, "r");

    if (!source)
    {
        printf("Error opening file.\n");
        return false;
    }

    char word[LENGTH + 1];

    // Read each word in the file
    while (fscanf(source, "%s", word) != EOF)
    {
        // Add each word to the hash table
        node *new_node = malloc(sizeof(node));
        if (!new_node)
        {
            unload();
            return false;
        }

        // copying the word into new node
        strcpy(new_node->word, word);

        // getting the "bin" of the word
        int index = hash(word);

        // adding the node to the bin in the hash table
        new_node->next = table[index];
        table[index] = new_node;

        // adding to counter for number of words in dictionary
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
    for (int i = 0; i < N; i++)
    {
        // start at beginning of the hash table
        node *unload_node = table[i];
        while (unload_node)
        {
            // need temp node so won't lose other nodes after
            node *tmp = unload_node;
            unload_node = unload_node->next;

            if (!tmp)
            {
                return false;
            }
            free(tmp);
        }
    }
    return true;
}