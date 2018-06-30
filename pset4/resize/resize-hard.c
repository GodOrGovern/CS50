#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include "bmp.h"

int main(int argc, char *argv[])
{
	if (argc != 4)
	{
		fprintf(stderr, "Usage: ./resize n infile outfile\n");
		fprintf(stderr, "The infile will be increased in size by a factor of n, the product of which will be stored in the outfile\n");
		return 1;
	}

	int fact = atoi(argv[1]);
	if (fact < 0 || fact > 100 || (fact % 1) != 0)
	{
		fprintf(stderr, "Usage: ./resize factor infile outfile\n");
		fprintf(stderr, "factor must be a positive integer less than or equal to 100\n");
		return 1;
	}

	char *infile = argv[2];
  	char *outfile = argv[3];

  	FILE *inpt = fopen(infile, "r");
	if (inpt == NULL)
  	{
    	fprintf(stderr, "Could not open %s\n", infile);
		return 2;
  	}

	FILE *outpt = fopen(outfile, "w");
	if (outpt == NULL)
	{
		fclose(inpt);
		fprintf(stderr, "Could not open %s\n", outfile);
		return 3;
	}

	BITMAPFILEHEADER bf;
	fread(&bf, sizeof(BITMAPFILEHEADER), 1, inpt);
	BITMAPINFOHEADER bi;
    fread(&bi, sizeof(BITMAPINFOHEADER), 1, inpt);

	if (bf.bfType != 0x4d42 || bf.bfOffBits != 54 || bi.biSize != 40 || bi.biBitCount != 24 || bi.biCompression != 0)
    {
        fclose(outpt);
        fclose(inpt);
        fprintf(stderr, "Unsupported file format\n");
        return 4;
    }

	int origwidth = bi.biWidth;
	int origpad = (4 - (origwidth * sizeof(RGBTRIPLE)) % 4) % 4;
	bi.biWidth *= fact;
	bi.biHeight *= fact;
	int padding = (4 - (bi.biWidth * sizeof(RGBTRIPLE)) % 4) % 4;
	bi.biSizeImage = (bi.biWidth * abs(bi.biHeight) * 3) + (padding * abs(bi.biHeight));
	bf.bfSize = bi.biSizeImage + bf.bfOffBits;
	fwrite(&bf, sizeof(BITMAPFILEHEADER), 1, outpt);
    fwrite(&bi, sizeof(BITMAPINFOHEADER), 1, outpt);

    for (int i = 0, biHeight = abs(bi.biHeight); i < biHeight; i++)
    {
		for (int j = 0; j < origwidth; j++)
		{
			RGBTRIPLE triple;
			fread(&triple, sizeof(RGBTRIPLE), 1, inpt);

			for (int k = 0; k < fact; k++)
			{
				fwrite(&triple, sizeof(RGBTRIPLE), 1, outpt);
			}
		}

		fseek(inpt, origpad, SEEK_CUR);
		for (int l = 0; l < padding; l++)
		{
				fputc(0x00, outpt);
		}

		int distance = (origwidth * sizeof(RGBTRIPLE)) + origpad;
		if ((i + 1) % fact != 0)
		{
			fseek(inpt, -(distance), SEEK_CUR);
		}
	}

	fclose(inpt);
	fclose(outpt);
	return 0;
}
