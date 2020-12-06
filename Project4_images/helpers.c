#include "helpers.h"
#include <math.h>

// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
    for (int i=0; i<height;i++)
    {
        for (int j=0;j<width;j++)
        {
            float percent=(image[i][j].rgbtRed+image[i][j].rgbtGreen+image[i][j].rgbtBlue)/(float)3;
            int avg=round(percent);
            image[i][j].rgbtRed=avg;
            image[i][j].rgbtGreen=avg;
            image[i][j].rgbtBlue=avg;
        }
    }
    return;
}

// Convert image to sepia
void sepia(int height, int width, RGBTRIPLE image[height][width])
{
    for (int i=0; i<height;i++)
    {
        for (int j=0;j<width;j++)
        {
            int sepiaRed = round(.393 * image[i][j].rgbtRed + .769 *  image[i][j].rgbtGreen + .189 *  image[i][j].rgbtBlue);
            int sepiaGreen = round(.349 * image[i][j].rgbtRed + .686 *  image[i][j].rgbtGreen + .168 *  image[i][j].rgbtBlue);
            int sepiaBlue = round(.272 * image[i][j].rgbtRed + .534 *  image[i][j].rgbtGreen + .131 *  image[i][j].rgbtBlue);

            if (sepiaRed >255)
            {
                sepiaRed=255;
            }

            if (sepiaGreen >255)
            {
                sepiaGreen=255;
            }
            if (sepiaBlue >255)
            {
                sepiaBlue=255;
            }
            image[i][j].rgbtRed=sepiaRed;
            image[i][j].rgbtGreen=sepiaGreen;
            image[i][j].rgbtBlue=sepiaBlue;
        }
    }
    return;
}

// Reflect image horizontally
void reflect(int height, int width, RGBTRIPLE image[height][width])
{
    for (int i=0;i<height;i++){
        for (int j=0;j<width/2;j++){
            int red=image[i][j].rgbtRed;
            int green=image[i][j].rgbtGreen;
            int blue=image[i][j].rgbtBlue;

            image[i][j].rgbtRed=image[i][width-j-1].rgbtRed;
            image[i][j].rgbtGreen=image[i][width-j-1].rgbtGreen;
            image[i][j].rgbtBlue=image[i][width-j-1].rgbtBlue;

            image[i][width-j-1].rgbtRed=red;
            image[i][width-j-1].rgbtGreen=green;
            image[i][width-j-1].rgbtBlue=blue;

        }
    }
    return;
}

// Blur image
void blur(int height, int width, RGBTRIPLE image[height][width])
{
    RGBTRIPLE tempimg[height][width];
    for (int i=0;i<height;i++){
        for (int j=0;j<width;j++){
            tempimg[i][j].rgbtBlue=image[i][j].rgbtBlue;
            tempimg[i][j].rgbtGreen=image[i][j].rgbtGreen;
            tempimg[i][j].rgbtRed=image[i][j].rgbtRed;
        }
    }
    //Top left corner
    image[0][0].rgbtBlue=(tempimg[0][0].rgbtBlue + tempimg[0][1].rgbtBlue + tempimg[1][0].rgbtBlue + tempimg[1][1].rgbtBlue)/4;
    image[0][0].rgbtGreen=(tempimg[0][0].rgbtGreen + tempimg[0][1].rgbtGreen + tempimg[1][0].rgbtGreen + tempimg[1][1].rgbtGreen)/4;
    image[0][0].rgbtRed=(tempimg[0][0].rgbtBlue + tempimg[0][1].rgbtBlue + tempimg[1][0].rgbtBlue + tempimg[1][1].rgbtRed)/4;
    //Top right corner
    image[0][width-1].rgbtBlue=(tempimg[0][width-1].rgbtBlue + tempimg[0][width-2].rgbtBlue + tempimg[1][width-1].rgbtBlue + tempimg[1][width-2].rgbtBlue)/4;
    image[0][width-1].rgbtGreen=(tempimg[0][width-1].rgbtGreen + tempimg[0][width-2].rgbtGreen + tempimg[1][width-1].rgbtGreen + tempimg[1][width-2].rgbtGreen)/4;
    image[0][width-1].rgbtRed=(tempimg[0][width-1].rgbtBlue + tempimg[0][width-2].rgbtBlue + tempimg[1][width-1].rgbtBlue + tempimg[1][width-2].rgbtRed)/4;
    //Bottom left corner
    image[height-1][0].rgbtBlue=(tempimg[height-1][0].rgbtBlue + tempimg[height-2][0].rgbtBlue + tempimg[height-1][1].rgbtBlue + tempimg[height-2][1].rgbtBlue)/4;
    image[height-1][0].rgbtGreen=(tempimg[height-1][0].rgbtGreen + tempimg[height-2][0].rgbtGreen + tempimg[height-1][1].rgbtGreen + tempimg[height-2][1].rgbtGreen)/4;
    image[height-1][0].rgbtRed=(tempimg[height-1][0].rgbtBlue + tempimg[height-2][0].rgbtBlue + tempimg[height-1][1].rgbtBlue + tempimg[height-2][1].rgbtRed)/4;
    //bottom right corner
    image[height-1][width-1].rgbtBlue=(tempimg[height-2][width-2].rgbtBlue + tempimg[height-2][width-1].rgbtBlue + tempimg[height-1][width-2].rgbtBlue + tempimg[height-1][width-1].rgbtBlue)/4;
    image[height-1][width-1].rgbtGreen=(tempimg[height-2][width-2].rgbtGreen + tempimg[height-2][width-1].rgbtGreen + tempimg[height-1][width-2].rgbtGreen + tempimg[height-1][width-1].rgbtGreen)/4;
    image[height-1][width-1].rgbtRed=(tempimg[height-2][width-2].rgbtBlue + tempimg[height-2][width-1].rgbtBlue + tempimg[height-1][width-2].rgbtBlue + tempimg[height-1][width-1].rgbtRed)/4;
    //topmost non-corner row
    for (int q=1;q<width-1;q++){
                int blue=0;
                int green=0;
                int red=0;
        for( int w=-1;w<=1;w++){
            for(int e=0;e<=1;e++){


                blue+=tempimg[e][q+w].rgbtBlue;
                green+=tempimg[e][q+w].rgbtGreen;
                red+=tempimg[e][q+w].rgbtRed;
            }
        }
                image[0][q].rgbtBlue=blue/6;
                image[0][q].rgbtGreen=green/6;
                image[0][q].rgbtRed=red/6;
    }

    //bottommost non-corner row
    for (int q=1;q<width-1;q++){
        int blue=0;
                int green=0;
                int red=0;
        for (int w=-1;w<=1;w++){
            for(int e=0;e<=1;e++){


                blue+=tempimg[height-2+e][q+w].rgbtBlue;
                green+=tempimg[height-2+e][q+w].rgbtGreen;
                red+=tempimg[height-2+e][q+w].rgbtRed;
            }
        }
                image[height-1][q].rgbtBlue=blue/6;
                image[height-1][q].rgbtGreen=green/6;
                image[height-1][q].rgbtRed=red/6;
    }
    //leftmost column
    for (int q=1;q<height-1;q++){
                 int blue=0;
                int green=0;
                int red=0;
        for( int w=0;w<=1;w++){
            for(int e=-1;e<=1;e++){


                blue+=tempimg[q+e][w].rgbtBlue;
                green+=tempimg[q+e][w].rgbtGreen;
                red+=tempimg[q+e][w].rgbtRed;
            }
        }
                image[q][0].rgbtBlue=blue/6;
                image[q][0].rgbtGreen=green/6;
                image[q][0].rgbtRed=red/6;
    }

    //rightmost column
    for (int q=1;q<height-1;q++){
            int blue=0;
            int green=0;
            int red=0;
        for( int w=0;w<=1;w++){
            for(int e=-1;e<=1;e++){


                blue+=tempimg[q+e][width-2+w].rgbtBlue;
                green+=tempimg[q+e][width-2+w].rgbtGreen;
                red+=tempimg[q+e][width-2+w].rgbtRed;
            }
        }
                image[q][width-1].rgbtBlue=blue/6;
                image[q][width-1].rgbtGreen=green/6;
                image[q][width-1].rgbtRed=red/6;
    }
    //centre pixels
        for (int p=1;p<height-1;p++){
            for (int q=1;q<width-1;q++){
                        int blue=0;
                        int green=0;
                        int red=0;
                for (int d=-1;d<=1;d++){
                    for(int u=-1;u<=1;u++){


                        blue+=tempimg[p+d][q+u].rgbtBlue;
                        green+=tempimg[p+d][q+u].rgbtGreen;
                        red+=tempimg[p+d][q+u].rgbtRed;
                    }
                }
                image[p][q].rgbtBlue=blue/9;
                image[p][q].rgbtGreen=green/9;
                image[p][q].rgbtRed=red/9;
            }
        }
    return;
}
