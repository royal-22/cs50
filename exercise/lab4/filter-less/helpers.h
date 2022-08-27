#include "bmp.h"

// convert image to greyscale
void grayscale(int height, int width, RGBTRIPLE image[height][width]);

// convert image to sepia
void sepia(int height, int width, RGB image[height][width]);

// reflect image horizontally
void reflect(int height, int width, RGB image[height][width]);

// Blur image
void blur(int height, int width, RGB image[height][width]);