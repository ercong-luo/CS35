#pragma once
/*
  Copyright (c) 2020
  Swarthmore College Computer Science Department, Swarthmore PA
  J. Brody, A. Danner, M. Gagne, L. Meeden, Z. Palmer, A. Soni, M. Wehar
  Distributed as course material for Spring 2020
  CPSC 035: Data Structures and Algorithms
  https://tinyurl.com/vdxo2w8
*/

/**
 * A helper function to determine the location of a pixel in a PPM image array.
 * Writing this routine makes it easier to write your other image transformation
 * functions.
 * @param width The width of the PPM image.
 * @param x The X coordinate of the pixel.
 * @param y The Y coordinate of the pixel.
 * @return The index of the first integer in the specified pixel.  For example,
 *         if x==1 and y==0, this function returns 3.
 */
int pixelToIndex(int width, int x, int y);

/**
 * A function which removes the red from an image.
 * @param width The width of the image to transform.
 * @param height The height of the image to transform.
 * @param ppm The PPM image to transform.
 */
void noRed(int width, int height, int* ppm);

/**
 * A function which removes the green from an image.
 * @param width The width of the image to transform.
 * @param height The height of the image to transform.
 * @param ppm The PPM image to transform.
 */
void noGreen(int width, int height, int* ppm);

/**
 * A function which removes the blue from an image.
 * @param width The width of the image to transform.
 * @param height The height of the image to transform.
 * @param ppm The PPM image to transform.
 */
void noBlue(int width, int height, int* ppm);

/**
 * A function which inverts the color of an image.
 * @param width The width of the image to transform.
 * @param height The height of the image to transform.
 * @param ppm The PPM image to transform.
 */
void invert(int width, int height, int* ppm);

/**
 * A function which makes the image to grayscale.
 * @param width The width of the image to transform.
 * @param height The height of the image to transform.
 * @param ppm The PPM image to transform.
 */
void grayscale(int width, int height, int* ppm);

/**
 * A function which flips the image horizontally.
 * @param width The width of the image to transform.
 * @param height The height of the image to transform.
 * @param ppm The PPM image to transform.
 */
void flipHorizontally(int width, int height, int* ppm);

/**
 * A function which flips the image vertically.
 * @param width The width of the image to transform.
 * @param height The height of the image to transform.
 * @param ppm The PPM image to transform.
 */
void flipVertically(int width, int height, int* ppm);
