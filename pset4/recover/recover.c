#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>


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
    
   unsigned char* buffer = malloc(sizeof(unsigned char)*512);
   char* filename = malloc(10*sizeof(char));
   
   FILE* img;
   
   int fileCounter = 0;
   bool start = 0;
   
   while (fread(buffer, 512, 1 , inptr) !=0)
    {
        // start of a new JPG? (if yes?)
        if((int) buffer[0]==255 && (int) buffer[1]==0xd8 && (int) buffer[2]==255 && (int) buffer[3]>=0xe0 && (int) buffer[3]<=0xef)
        {
            if (start == true)
            {
                fclose(img);
            }
            else 
            {
                start = true;
            }
            
            sprintf(filename, "%03i.jpg",fileCounter);
            
            img = fopen(filename,"w");
            if (img == NULL)
            {
                fprintf(stderr, "Could not open %s.\n",infile);
                return 2;
            }
            
            fwrite(buffer, 512, 1, img);
            fileCounter++;
        }
        // Start of a new JPG (if no?)
        else
        {
            // have you already started a JPG?
           if (start == true) 
           {
               fwrite(buffer, 512, 1, img);
           }
        }
    }
    
    free(buffer);
    free(filename);
    fclose(img);
    fclose(inptr);
    return 0;
}
