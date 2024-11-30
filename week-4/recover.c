#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

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

    // Create a buffer for a block of data
    uint8_t buffer[512];
    char filename[8];

    int fname=0;
    sprintf(filename, "%03i.jpg", fname);
    FILE *img = fopen(filename, "w");
    while (fread(buffer, 1, 512, card) == 512) {
        if (buffer[0] == 0xFF) {
            if (buffer[1] == 0xD8) {
                if (buffer[2] == 0xFF) {
                    if ((buffer[3] & 0xF0) == 0xE0) {
                        fclose(img);
                        sprintf(filename, "%03i.jpg", fname++);
                        img = fopen(filename, "w");
                    }

                }
            }
        }
        fwrite(buffer, 1, 512, img);
    }
    if (img != NULL) {
        fclose(img);
    }
    fclose(card);
}
