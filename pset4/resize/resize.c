/**
 * Copies a BMP piece by piece, just because.
 */
       
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#include "bmp.h"

int main(int argc, char *argv[])
{
    // ensure proper usage
    if (argc != 4)
    {
        fprintf(stderr, "Usage: ./copy float infile outfile\n");
        return 1;
    }
    
    float f; // creat a float
    
    sscanf (argv[1],"%f", &f); // take the first value from the user entry and scan it for a value that it turns into a float
    
    if (f < 0.0 || f > 100.0) // if entry is not between 0 - 100 exit with error 1
    {
        fprintf(stderr,"Float entry has to be between 0.00 and 100.00\n");
        return 1;
    }
    
    // remember filenames
    char *infile = argv[2];
    char *outfile = argv[3];

    // open input file 
    FILE *inptr = fopen(infile, "r");
    if (inptr == NULL)
    {
        fprintf(stderr, "Could not open %s.\n", infile);
        return 1;
    }

    // open output file
    FILE *outptr = fopen(outfile, "w");
    if (outptr == NULL)
    {
        fclose(inptr);
        fprintf(stderr, "Could not create %s.\n", outfile);
        return 1;
    }

    // read infile's BITMAPFILEHEADER
    BITMAPFILEHEADER bf, bfResized;
    fread(&bf, sizeof(BITMAPFILEHEADER), 1, inptr);
    bfResized = bf;
    
    // read infile's BITMAPINFOHEADER
    BITMAPINFOHEADER bi, biResized;
    fread(&bi, sizeof(BITMAPINFOHEADER), 1, inptr);
    biResized = bi;
    
    // ensure infile is (likely) a 24-bit uncompressed BMP 4.0
    if (bf.bfType != 0x4d42 || bf.bfOffBits != 54 || bi.biSize != 40 || 
        bi.biBitCount != 24 || bi.biCompression != 0)
    {
        fclose(outptr);
        fclose(inptr);
        fprintf(stderr, "Unsupported file format.\n");
        return 4;
    }
    
    // take the original file width/height and multiple by f to change resized file
    biResized.biWidth = bi.biWidth * f;
    biResized.biHeight = bi.biHeight * f;
    
    // determine padding for original and resized file
    int padding = (4 - (bi.biWidth * sizeof(RGBTRIPLE)) % 4) % 4;
    int paddingResized = (4 - (biResized.biWidth * sizeof(RGBTRIPLE)) % 4) %4;
    
    // create resized image size - including padding
    biResized.biSizeImage = ((sizeof(RGBTRIPLE) * biResized.biWidth) + paddingResized) * abs(biResized.biHeight);
    
    // create the new resized file size 
    bfResized.bfSize = biResized.biSizeImage + sizeof(BITMAPFILEHEADER) + sizeof(BITMAPINFOHEADER);
    
    // write outfile's BITMAPFILEHEADER
    fwrite(&bfResized, sizeof(BITMAPFILEHEADER), 1, outptr);

    // write outfile's BITMAPINFOHEADER
    fwrite(&biResized, sizeof(BITMAPINFOHEADER), 1, outptr);

    
    // create an original line that has the dimension of positive height size and postive width size
    RGBTRIPLE originalLine[(int)abs(bi.biHeight)][bi.biWidth];
    
    // read in original file | go through each line, height and width, and save each pixels location, and skip 
    for (int i = 0, biHeight = abs(bi.biHeight); i < biHeight; i++)
    {
        for (int j = 0; j < bi.biWidth; j++)
        {
            fread(&(originalLine[i][j]), sizeof(RGBTRIPLE), 1, inptr);
        }
        fseek(inptr, padding, SEEK_CUR);
    }
    
    // create a resized line that has the dimension of positive height size and postive width size
    RGBTRIPLE resizedLine[(int)abs(biResized.biHeight)][biResized.biWidth];
    
    // go into the each line of the original height
    for (int i = 0, biHeight = abs(bi.biHeight); i < biHeight; i++)
    {
        int tempI = floor(i*f); // create tempI value that is a rounded number (downwards) that show where the original pixel goes after scaling 
        
        for (int j = 0; j < bi.biWidth; j++)
        {
            int tempJ = ceil (f*j); // create tempJ value that is a rounded number (downwards) that show where the original pixel goes after scaling
            
            // Copy the original pixel to its scaled counterpart with i,j position
            resizedLine[tempI][tempJ] = originalLine[i][j];
            
            for (int k = floor(f) - 1; k > 0; k--)
            {
                // create a copy of the original pixel and move it by right
                resizedLine[tempI][tempJ + k] =  originalLine[i][j]; 
            }
        }
        
        for (int m = floor(f) - 1; m > 0; m--)
        {
            for (int j = 0; j < bi.biWidth; j++)
            {
                int tempJ = ceil(f*j);
                
                // Copy the original pixel to its scaled counterpart with i+ add line position,j position
                resizedLine[tempI + m][tempJ] = originalLine[i][j]; 
                
                for (int k = floor(f) - 1; k > 0; k--)
                {   
                    // create a copy of the original pixel and move it by right
                    resizedLine[tempI + m][tempJ + k] =  originalLine[i][j]; // take original pix
                }
            }
        }
    }
    
    // go through the structure of the new hight and size and write the new file plus add the padding.
    for (int i = 0, biHeight = abs(biResized.biHeight); i < biHeight; i++)
    {
        for (int j = 0; j < biResized.biWidth; j++)
        {
            fwrite(&resizedLine[i][j], sizeof(RGBTRIPLE), 1, outptr);
        }
        for (int k = 0; k < paddingResized; k++)
        {
            fputc(0x00, outptr);
        }
    }
    

    // close infile
    fclose(inptr);

    // close outfile
    fclose(outptr);
    
    // success
    return 0;
}
