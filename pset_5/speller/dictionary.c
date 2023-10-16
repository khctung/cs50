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

    node *new_node;
    (new_node = malloc(sizeof(node))) != NULL

    // Read each word in the file
    while (fscanf(source, "%s", new_node->word) != EOF) // making the condition in the while loop true, loop forever, use if condition to break
    {
        *new_node = malloc(sizeof(node));
        if (!new_node)
        {
            free(new_node);
            return false;
        }

        // getting the "bin" of the word
        int index = hash(new_node->word);

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
    // if dictionary loaded, then can just return num_words; if unloaded, would just be 0
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
            // don't need to check if false because tmp will never be null (since then while loop won't run)
            free(tmp);
        }
    }
    return true;
}