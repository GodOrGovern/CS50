#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#define BLOCK_SIZE 512

int main(int argc, char *argv[])
{
  if (argc!=2)
  {
    fprintf(stderr, "Usage: ./recover forensic-image-file\n");
    return 1;
  }

  FILE *inpt=fopen(argv[1], "r");
  if (inpt==NULL)
  {
    fprintf(stderr, "Could not open %s\n", argv[1]);
    return 2;
  }

  fseek(inpt, 0, SEEK_END);
  int size=ftell(inpt);
  int block_count;
  rewind(inpt);

  if (size % BLOCK_SIZE==0)
  {
    block_count=(size / BLOCK_SIZE);
  }

  else
  {
    block_count=(size / BLOCK_SIZE) + 1;
  }

  int i, j, start[block_count];
  char *byte_four[block_count];
  char *buffer[block_count];
  for (i=0; i < block_count; i++)
  {
    buffer[i]=(char *)malloc(BLOCK_SIZE * sizeof(char));
    byte_four[i]=(char *)malloc(2 * sizeof(char));
  }

  int k=0, m=0, n=0;
  for (i=0; i < block_count; i++)
  {
    for (j=0; j < BLOCK_SIZE; j++)
    {
      fread(&buffer[i][j], 1, 1, inpt);
    }

    if (buffer[i][0 & 2]==(char)0xff && buffer[i][1]==(char)0xd8)
    {
      sprintf(byte_four[k], "%02hhx", buffer[i][3]);
      if (byte_four[k][0]=='e')
      {
        start[m]=i;
        m++;
      }
      k++;
    }
  }

  FILE *jpg;
  char file_name[7], p;
  int q, jpg_size;
  for (n=0; n < m; n++)
  {
    sprintf(file_name, "%03i.jpg", n);
    jpg=fopen(file_name, "w");
    if (jpg==NULL)
    {
      printf("Could not open %s\n", file_name);
      return 1;
    }

    q=0;
    fseek(inpt, BLOCK_SIZE * start[n], SEEK_SET);
    p=fgetc(inpt);

    if (n != m - 1)
    {
      jpg_size=(start[n+1] - start[n]) * BLOCK_SIZE;
    }

    else
    {
      jpg_size=(block_count - start[n]) * BLOCK_SIZE;
    }

    while (q < jpg_size)
    {
      fputc(p, jpg);
      q++;
      p=fgetc(inpt);
    }

    fclose(jpg);
  }

  for (i=0; i < block_count; i++)
  {
    free(buffer[i]);
    free(byte_four[i]);
  }
  fclose(inpt);
  return 0;
}
