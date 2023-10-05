#include <stdio.h>
#include <stdlib.h>
#define BLOCKSIZE 512

int main(int argc, char *argv[])
{
    // Accept a single command-line argument
    if (argc != 2)
    {
        printf("Usage: ./recover FILE\n");
        return 1;
    }

    // Open the memory card
    FILE *card = fopen(argv[1], "r");
    if (card == NULL)
    {
        printf("Could not open %s.\n", argv[1]);
        return 2;
    }

    // CHECK IF OPENED PROPERLY

    // Create a buffer for a block of data
    uint8_t buffer[BLOCKSIZE];

    // While there's still data left to read from the memory card
    while (fread(buffer, 1, BLOCKSIZE, card) == BLOCKSIZE)
    {
        // Create JPEGs from the data
        
    }

}