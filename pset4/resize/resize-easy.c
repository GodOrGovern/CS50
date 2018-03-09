#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <math.h>
#include "bmp.h"

int main(int argc, char *argv[])
{
	if (argc != 4)
	{
		fprintf(stderr, "Usage: ./resize n infile outfile\n");
		fprintf(stderr, "The infile will be increased in size by a factor of n, the product of which will be stored in the outfile\n");
		return 1;
	}

	float f = atof(argv[1]);
	if (f <= 0 || f > 100 || fmodf(10 * f, 1) != 0)
	{
		fprintf(stderr, "Usage: ./resize f infile outfile\n");
		fprintf(stderr, "f must be a floating-point value over the range (0.0, 100.0]\n");
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

	int origpad = (4 - (bi.biWidth * sizeof(RGBTRIPLE)) % 4) % 4;
	RGBTRIPLE image[bi.biWidth][abs(bi.biHeight)];

	for (int a = 0, arbit = abs(bi.biHeight); a < arbit; a++)
	{
		for (int b = 0; b < bi.biWidth; b++)
		{
			RGBTRIPLE triple;
			fread(&triple, sizeof(RGBTRIPLE), 1, inpt);
			image[a][b] = triple;
		}

		fseek(inpt, origpad, SEEK_CUR);
	}

	bi.biWidth *= f;
	bi.biHeight *= f;
	int padding = (4 - (bi.biWidth * sizeof(RGBTRIPLE)) % 4) % 4;
	bi.biSizeImage = (bi.biWidth * abs(bi.biHeight) * 3) + (padding * abs(bi.biHeight));
	bf.bfSize = bi.biSizeImage + bf.bfOffBits;

	fwrite(&bf, sizeof(BITMAPFILEHEADER), 1, outpt);
    fwrite(&bi, sizeof(BITMAPINFOHEADER), 1, outpt);

    for (int i = 0, height = abs(bi.biHeight); i < height; i++)
    {
		for (int k = 0; k < bi.biWidth; k++)
		{
			RGBTRIPLE triple;
			triple = image[(int) (i / f)][(int) (k / f)];
			fwrite(&triple, sizeof(RGBTRIPLE), 1, outpt);
		}

		fseek(inpt, origpad, SEEK_CUR);
		for (int m = 0; m < padding; m++)
		{
			fputc(0x00, outpt);
		}
	}

	fclose(inpt);
	fclose(outpt);
	return 0;
}
