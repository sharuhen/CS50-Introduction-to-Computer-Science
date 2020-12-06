#include <cs50.h>
#include <stdio.h>
#include <stdlib.h>

#define buffersize 512

int main(void)
{
    // open memory card file
    FILE* file = fopen("card.raw", "r");
    if (file == NULL)
    {
        printf("Could not open card.raw.\n");
        return 2;
    }

    // create buffer
    unsigned char buffer[buffersize];


    int filecount = 0;

    FILE* picture = NULL;


    int jpgfound = 0; //false


    while (fread(buffer, buffersize, 1, file) == 1)
    {

        if (buffer[0] == 0xff && buffer[1] == 0xd8 && buffer[2] == 0xff && (buffer[3] & 0xe0) == 0xe0)
        {
            if (jpgfound == 1)
            {

                fclose(picture);
            }
            else
            {
                // jpg discovered and now we have the green light to write
                jpgfound = 1;
            }

            char filename[8];
            sprintf(filename, "%03d.jpg", filecount);
            picture = fopen(filename, "a");
            filecount++;
        }

        if (jpgfound == 1)
        {
            // write 512 bytes to file once we start finding jpgs
            fwrite(&buffer, buffersize, 1, picture);
        }

    }

    // close files
    fclose(file);
    fclose(picture);

    return 0;
}