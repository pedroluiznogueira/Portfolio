#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

#define BLOCK_SIZE 512 // Setting the size of Bytes that each chunck of memory has, relationing it to buffer

typedef uint8_t BYTE; // uint8_t is a data type in C wich stores 8 bits/1 byte

void checkUsage(int argc); //  Function that will check if the command line argument are correct
void verifyNull(FILE *file); // Verifying if the file that was just opened is not NULL
int verifyJPEG(BYTE buffer[]); // Verifying if the first bytes of the chunck buffer match with the ones that a JPEG file has

int main(int argc, char *argv[])
{
    checkUsage(argc);
    FILE *memorycard = fopen(argv[1], "r"); // Opening memory card to verify each chunck of memory
    verifyNull(memorycard);

    // Created a array of buffer, wich each oe will be from the data type BYTE(one byte)
    // It will has 512 of them
    // So I will be able to verify each first buffer of a file 512 times, to compare in the proportion I need, with a JPEG
    BYTE buffer[BLOCK_SIZE];

    //Buffer for filename

    FILE *newjpg; // Creating a pointer to a file named image
    char filename[8];
    int counter = 0;

    // If I find a JPEG file, the next one will be right next each other
    while (fread(buffer, BLOCK_SIZE, 1, memorycard) == 1) // Buffer is where I am storing the data I am reading
    {
        if (verifyJPEG(buffer) == 1) // One at a time buffers will be storing 512 bytes from the memory card, so I am checking if they are in fact a JPEG file
        {
            // Close the previous image, unless it's the first JPEG
            if (counter != 0) // -- SEE SECOND -- So we will be closing every file after already doing what we needed
            {
                fclose(newjpg);
            }
            sprintf(filename, "%03i.jpg", counter++); // (wheretowrite, whattobewritten, addingtocounter) -- SEE FIRST --
            newjpg = fopen(filename, "w"); // opening a file that image points
            fwrite(buffer, BLOCK_SIZE, 1, newjpg); // for each found in the start of the while loop, will be written the file found on image

        }
        // Unless we find another JPEG file, we will be writing to image the blocks of the current JPEG file
        else if (counter > 0)
        {
            fwrite(buffer, BLOCK_SIZE, 1, newjpg);
        }
    }

}

void checkUsage(int argc)
{
    if (argc != 2)
    {
        exit(1);
    }
}

void verifyNull(FILE *file)
{
    if (file == NULL)
    {
        exit(1);
    }
}

int verifyJPEG(BYTE buffer[])
{
    if (buffer[0] == 0Xff && buffer[1] == 0Xd8 && buffer[2] == 0xff && (buffer[3] & 0xf0) == 0xe0)
    {
        return 1;
    }
    return 0;
}