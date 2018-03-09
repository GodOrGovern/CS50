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

	int n = atoi(argv[1]);
	if (n < 0 || n > 100 || (n % 1) != 0)
	{
		fprintf(stderr, "Usage: ./resize n infile outfile\n");
		fprintf(stderr, "n must be a positive integer less than or equal to 	100\n");
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

	bi.biWidth *= n;
	bi.biHeight *= n;

	int padding = (4 - (bi.biWidth * sizeof(RGBTRIPLE)) % 4) % 4;

	bi.biSizeImage = (bi.biWidth * abs(bi.biHeight) * 3) + (padding * abs(bi.biHeight));
	bf.bfSize = bi.biSizeImage + bf.bfOffBits;

	fwrite(&bf, sizeof(BITMAPFILEHEADER), 1, outpt);
    fwrite(&bi, sizeof(BITMAPINFOHEADER), 1, outpt);

    for (int i = 0, height = abs(bi.biHeight); i < height; i++)
    {

		for (int k = 0; k < origwidth; k++)
		{
			RGBTRIPLE triple;
			fread(&triple, sizeof(RGBTRIPLE), 1, inpt);

			for (int l = 0; l < n; l++)
			{
				fwrite(&triple, sizeof(RGBTRIPLE), 1, outpt);
			}
		}

		fseek(inpt, origpad, SEEK_CUR);
		for (int m = 0; m < padding; m++)
		{
				fputc(0x00, outpt);
		}

		int distance = (origwidth * sizeof(RGBTRIPLE)) + origpad;
		if ((i + 1) % n != 0)
		{
			fseek(inpt, -(distance), SEEK_CUR);
		}
	}

	fclose(inpt);
	fclose(outpt);
	return 0;
}
