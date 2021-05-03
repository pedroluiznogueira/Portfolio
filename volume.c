// Modifies the volume of an audio file

#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// declaring a data type to read from the input file to the output file 
typedef uint8_t BYTE;
typedef uint16_t BYTE_16;

// Number of bytes in .wav header
const int HEADER_SIZE = 44;

int main(int argc, char *argv[])
{
    // Check command-line arguments
    if (argc != 4)
    {
        printf("Usage: ./volume input.wav output.wav factor\n");
        return 1;
    }

    // Open files and determine scaling factor
    FILE *input = fopen(argv[1], "r");
    if (input == NULL)
    {
        printf("Could not open file.\n");
        return 1;
    }

    FILE *output = fopen(argv[2], "w");
    if (output == NULL)
    {
        printf("Could not open file.\n");
        return 1;
    }

    float factor = atof(argv[3]);
    
    BYTE bytes[HEADER_SIZE];
    
    // argument 1 ==> variável 
    // argument 2 ==> sizeof();
    //argument 3 ==> quantidade de vezes que vai iterar (read or write)
    // argument 4 ==> pointer que aponta para o arquivo que você quer iterar

    // TODO: Copy header from input file to output file
    fread(bytes, sizeof(BYTE), HEADER_SIZE, input);
    fwrite(bytes, sizeof(BYTE), HEADER_SIZE, output);

    // TODO: Read samples from input file and write updated data to output file
    BYTE_16 bytes_16;
    
    fseek(input, 44,0);
    fseek(output, 44,0);
    
    // a cada 2 bytes que passar eu multiplico eles 
    // depois copio o resultado para o output file 
    
    while (fread(&bytes_16, sizeof(BYTE_16), 1, input))
    {
        bytes_16 = (float)(factor * bytes_16);
        fwrite(&bytes_16, sizeof(BYTE_16), 1, output);
    }

    
    // Close files
    fclose(input);
    fclose(output);
}
