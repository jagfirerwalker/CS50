#include <stdio.h>
#include <stdbool.h>


int main (int argc, char *argv[])
{
    // check if the input has only 2 entries
    if (argc != 2)
    {
        fprintf(stderr, "Usage: ./recover card.raw\n");
        return 1;
    }
    
    char *infile = argv[1];
    
    // open input file
    FILE *inptr = fopen(infile, "r");
    // sanity check the input file is not empty
    if (inptr == NULL)
    {
        fprintf(stderr, "Could not open %s.\n",infile);
        return 1;
    }
    
    int buffer[512];
    char filename[50];
    int fileCounter = 0;
    bool start = false;
    do
    {
        fread(buffer, 1, 512, inptr);
        
        // start of a new JPG? (if yes?)
        if (buffer[0] == 0xff && buffer[1] == 0xd8 && buffer[2] == 0xff && (buffer[3] & 0xf0) == 0xe0)
        {
            sprintf(filename, "%03i.jpg",fileCounter);
            FILE *img = fopen(filename,"w");
            fwrite(&buffer, 1, 512, img);
            start = true;
            fclose(img);
            fileCounter++;
        }
        // Start of a new JPG (if no?)
        else
        {
            // have you already started a JPG?
           if (start == true) 
           {
               sprintf(filename, "%03i.jpg",fileCounter);
               FILE *img = fopen(filename,"w");
               fwrite(buffer, 1, 512, img);
               fclose(img);
           }
        }
    }
    while (fread(buffer, 1, 512, inptr));
    
}
