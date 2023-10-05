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
        return 1;
    }

    // Create a buffer for a block of data
    uint8_t buffer[BLOCKSIZE];
    int jpeg_count = 0;
    bool found_jpeg = false;

    // While there's still data left to read from the memory card
    while (fread(buffer, 1, BLOCKSIZE, card) == BLOCKSIZE)
    {
        // assign jpg filename
        char outfile[8];
        sprintf(outfile, "%03i.jpg", jpeg_count);

        // Open output file
        FILE *outptr = fopen(outfile, "w");
        if (outptr == NULL)
        {
            printf("Could not create %s.\n", outfile);
            return 1;
        }

        // Create JPEGs from the data
        if (buffer[0] == 0xff && buffer[1] == 0xd8 && buffer[2] == 0xff && buffer[3] >= 0xe0 && buffer[3] <= 0xef)
        {
            found_jpg = true;

            if (found_jpeg)
            {
                fclose(outptr);
            }

            fwrite(buffer, sizeof(buffer[0]), BLOCKSIZE, outptr);
            jpeg_count++;
        }
        else if (found_jpg)
        {
            fwrite(buffer, sizeof(buffer[0]), BLOCKSIZE, outptr);
        }
    }
    fclose(card);
}