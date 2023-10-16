// Implements a dictionary's functionality

#include <ctype.h>
#include <stdbool.h>

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

// Returns true if word is in dictionary, else false
bool check(const char *word)
{
    // TODO
    return false;
}

// Hashes word to a number
unsigned int hash(const char *word)
{
    // TODO: Improve this hash function
    return toupper(word[0]) - 'A';
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

    // While there's still data left to read from the memory card
    while (fscanf(source, "%s", word) != EOF)
    {
        
    }

        fread(, 1, BLOCKSIZE, card) == BLOCKSIZE)
    {
        // Create JPEGs from the data
        if (buffer[0] == 0xff && buffer[1] == 0xd8 && buffer[2] == 0xff && buffer[3] >= 0xe0 && buffer[3] <= 0xef)
        {
            // checking if file is null or not
            if (outptr)
            {
                fclose(outptr);
            }

            sprintf(outfile, "%03i.jpg", jpeg_count);

            // Open output file
            outptr = fopen(outfile, "w");
            if (outptr == NULL)
            {
                printf("Could not create %s.\n", outfile);
                return 1;
            }

            jpeg_count++;
        }
        // writing to jpeg
        if (outptr)
        {
            fwrite(buffer, 1, BLOCKSIZE, outptr);
        }
    }
    fclose(card);
    if (outptr)
    {
        fclose(outptr);
    }

    // Read each word in the file

        // Add each word to the hash table

    // Close the dictionary file
    fclose(source);
}
}

// Returns number of words in dictionary if loaded, else 0 if not yet loaded
unsigned int size(void)
{
    // TODO
    return 0;
}

// Unloads dictionary from memory, returning true if successful, else false
bool unload(void)
{
    // TODO
    return false;
}
