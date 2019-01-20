#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <math.h>
#define BLOCK_SIZE 512

int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        fprintf(stderr, "Usage: ./recover forensic-image-file\n");
        return 1;
    }

    FILE *inpt = fopen(argv[1], "r");
    if (inpt == NULL)
    {
        fprintf(stderr, "Could not open %s\n", argv[1]);
        return 2;
    }

    fseek(inpt, 0, SEEK_END);
    int size = ftell(inpt);
    rewind(inpt);

    int block_count = ceil(size / BLOCK_SIZE);
    int block, pos, start[block_count];
    char *byte_four[block_count];
    char *buffer[block_count];

    for (block = 0; block < block_count; block++)
    {
        buffer[block] = (char *)malloc(BLOCK_SIZE * sizeof(char));
        byte_four[block] = (char *)malloc(2 * sizeof(char));
    }

    int num_byte = 0, num_jpg = 0;
    for (block = 0; block < block_count; block++)
    {
        for (pos = 0; pos < BLOCK_SIZE; pos++)
        {
            fread(&buffer[block][pos], 1, 1, inpt);
        }

        if (buffer[block][0 & 2] == (char)0xff && buffer[block][1] == (char)0xd8)
        {
            sprintf(byte_four[num_byte], "%02hhx", buffer[block][3]);

            if (byte_four[num_byte][0] == 'e')
            {
                start[num_jpg] = block;
                num_jpg++;
            }

            num_byte++;
        }
    }

    FILE *jpg;
    char file_name[7], buff_char;
    int cur_size, cur_jpg, size_jpg;

    for (cur_jpg = 0; cur_jpg < num_jpg; cur_jpg++)
    {
        sprintf(file_name, "%03i.jpg", cur_jpg);
        jpg = fopen(file_name, "w");

        if (jpg == NULL)
        {
            printf("Could not open %s\n", file_name);
            return 1;
        }

        cur_size = 0;
        fseek(inpt, BLOCK_SIZE * start[cur_jpg], SEEK_SET);

        if (cur_jpg != num_jpg - 1)
        {
            size_jpg = (start[cur_jpg + 1] - start[cur_jpg]) * BLOCK_SIZE;
        }

        else
        {
            size_jpg = (block_count - start[cur_jpg]) * BLOCK_SIZE;
        }

        while (cur_size < size_jpg)
        {
            buff_char = fgetc(inpt);
            fputc(buff_char, jpg);
            cur_size++;
        }

        fclose(jpg);
    }

    for (block = 0; block < block_count; block++)
    {
        free(buffer[block]);
        free(byte_four[block]);
    }

    fclose(inpt);
    return 0;
}
