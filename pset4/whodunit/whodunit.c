#include <stdio.h>
#include <cs50.h>
#include "bmp.h"

int main(int argc, char * argv[])
{
  	if (argc != 3)
  	{
    	fprintf(stderr, "Usage: ./whodunit infile outfile\n");
    	return 1;
  	}

  	char * infile = argv[1];
  	char * outfile = argv[2];

  	FILE * inpt = fopen(infile, "r");
	if (inpt == NULL)
  	{
    	fprintf(stderr, "Could not open %s\n", infile);
		return 2;
  	}

	FILE * outpt = fopen(outfile, "w");
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

	if (bf.bfType != 0x4d42 || bf.bfOffBits != 54 || bi.biSize != 40 ||
        bi.biBitCount != 24 || bi.biCompression != 0)
    {
        fclose(outpt);
        fclose(inpt);
        fprintf(stderr, "Unsupported file format\n");
        return 4;
    }

	fwrite(&bf, sizeof(BITMAPFILEHEADER), 1, outpt);
    fwrite(&bi, sizeof(BITMAPINFOHEADER), 1, outpt);

    int padding =  (4 - (bi.biWidth * sizeof(RGBTRIPLE)) % 4) % 4;

    for (int i = 0, biHeight = abs(bi.biHeight); i < biHeight; i++)
    {
        for (int j = 0; j < bi.biWidth; j++)
        {
            RGBTRIPLE triple;
            fread(&triple, sizeof(RGBTRIPLE), 1, inpt);

			if (triple.rgbtRed == 255)
			{
				triple.rgbtRed = 0;
				triple.rgbtBlue = 255;
				triple.rgbtGreen = 0;
			}

            fwrite(&triple, sizeof(RGBTRIPLE), 1, outpt);
        }

        fseek(inpt, padding, SEEK_CUR);
        for (int k = 0; k < padding; k++)
        {
            fputc(0x00, outpt);
        }
    }

	fclose(inpt);
	fclose(outpt);
	return 0;
}
