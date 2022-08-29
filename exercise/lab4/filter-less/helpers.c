#include "helpers.h"
#include <math.h>

// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
    for(int i=0; i<height; i++)
    {
        for(int j=0; j<width; j++)
        {
            int red = image[i][j].rgbtRed;
            int green = image[i][j].rgbtGreen;
            int blue = image[i][j].rgbtBlue;

            int average = round(((float)red + (float)green + (float)blue) / 3);

            image[i][j].rgbtRed = image[i][j].rgbtBlue = image[i][j].rgbtGreen = average;
        }
    }
    return;
}

// Convert image to sepia
void sepia(int height, int width, RGBTRIPLE image[height][width])
{
    for(int i=0; i<height; i++)
    {
        for(int j=0; j<width; j++)
        {
            int red = image[i][j].rgbtRed;
            int green = image[i][j].rgbtGreen;
            int blue = image[i][j].rgbtBlue;

            int redSepia = round(0.393 * red + 0.769 * green + 0.189 * blue);

            if(redSepia > 255)
                image[i][j].rgbtRed = 255;
            else
                image[i][j].rgbtRed = redSepia;

            int greenSepia = round(0.349 * red + 0.686 * green + 0.168 * blue);

            if(greenSepia > 255)
                image[i][j].rgbtGreen = 255;
            else
                image[i][j].rgbtGreen = greenSepia;

            int blueSepia = round(0.272 * red + 0.534 * green + 0.131 * blue);

            if(blueSepia > 255)
                image[i][j].rgbtBlue = 255;
            else
                image[i][j].rgbtBlue = blueSepia;
        }
    }
    return;
}

// Reflect image horizontally
void reflect(int height, int width, RGBTRIPLE image[height][width])
{
    for(int i=0; i<height; i++)
    {
        for(int j=0; j<width/2; j++)
        {
            RGBTRIPLE temp;
            temp = image[i][j];
            image[i][j] = image[i][width-j-1];
            image[i][width-j-1] = temp;
        }
    }
    return;
}

// Blur image
void blur(int height, int width, RGBTRIPLE image[height][width])
{
    RGBTRIPLE copy[height][width];
    for(int i=0; i<height; i++)
    {
        for(int j=0; j<width; j++)
        {
            copy[i][j] = image[i][j];
        }
    }

    for(int i=0; i<height; i++)
    {
        for(int j=0; j<width; j++)
        {
            int red, blue, green;
            red = 0;
            blue = 0;
            green = 0;
            float counter = 0;

            for(int x=-1; i<2; i++)
            {
                for(int y=-1; y<2; y++)
                {
                    int nX = height + x;
                    int nY = width + y;
                    if(nX < 0 || nX > height - 1 || nY < 0 || nY > width-1)
                    {
                        continue;
                    }

                    red += image[nX][nY].rgbtRed;
                    blue += image[nX][nY].rgbtBlue;
                    green += image[nX][nY].rgbtGreen;

                    counter ++;
                }
                copy[i][j].rgbtRed = round(red/counter);
                copy[i][j].rgbtBlue = round(blue/counter);
                copy[i][j].rgbtGreen = round(green/counter);
            }

        }
    }

    for(int i=0; i<height; i++)
    {
        for(int j=0; j<width; j++)
        {
            image[i][j].rgbtRed = copy[i][j].rgbtRed;
            image[i][j].rgbtGreen = copy[i][j].rgbtGreen;
            image[i][j].rgbtBlue = copy[i][j].rgbtBlue;
        }
    }

    return;
}