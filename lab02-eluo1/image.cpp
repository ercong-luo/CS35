/*
  Copyright (c) 2020
  Swarthmore College Computer Science Department, Swarthmore PA
  J. Brody, A. Danner, M. Gagne, L. Meeden, Z. Palmer, A. Soni, M. Wehar
  Distributed as course material for Spring 2020
  CPSC 035: Data Structures and Algorithms
  https://tinyurl.com/vdxo2w8
*/

#include "image.h"

// Note: Rohan the CS ninja who helped me asked me to comment out
// the following two lines because the compiler was giving me
// errors. After I commented out these lines, compilation was
// successful again. I would love to ask Professor Brody to see
// what the issue was.
// #include <iostream>
// using namespace std;


// Note: see image.h for documentation on functions.

int pixelToIndex(int width, int x, int y) {
  return (y * 3 * width) + (3 * x); // gives me the index in the ppm array according to input x,y coordinates
}

void noRed(int width, int height, int* ppm) {
  for(int i=0; i<(3*width*height); i+=3){
    ppm[i] = 0; // zero out every Red pixel value
  }
}

// TODO: write your other image transformation functions here

void noGreen(int width, int height, int* ppm) {
  for(int i=1; i<(3*width*height); i+=3){
    ppm[i] = 0; // zero out every Green pixel value
  }
}

void noBlue(int width, int height, int* ppm) {
  for(int i=2; i<(3*width*height); i+=3){
    ppm[i] = 0; // zero out every Blue pixel value
  }
}

void invert(int width, int height, int* ppm) {
  for(int i=0; i<(3*width*height); i++){
    ppm[i] = 255 - ppm[i]; // invert every pixel value by subtracting each value from 255, the upper range of pixel values
  }
}

void grayscale(int width, int height, int* ppm) {
  for(int i=0; i<(width*height); i++){
    int sum = ppm[3*i] + ppm[3*i+1] + ppm[3*i+2]; // get the sum of RGB pixel values for each pixel
    for(int j=0; j<3; j++){
      ppm[3*i+j] = sum/3; // get the average of RGB pixel values for each pixel
    }
  }
}

void flipHorizontally(int width, int height, int* ppm) {
  if( (width%2) == 1){ // if horizontally, there is an odd number of pixels
    for(int j=0; j<height; j++){ // iterate over each row of the image
      for(int i=0; i<(width-1)/2; i++){ // counting one swap as one action, I need to swap (width-1)/2 times
        for(int k=0; k<3; k++){ // each pixel has three corresponding values to RGB
          int storing[3] = {}; //initialize an array to store temporary values
          storing[k] = ppm[pixelToIndex(width, i, j) + k]; // assign 'storing' as the left RGB values to be swapped
          ppm[pixelToIndex(width, i, j) + k] = ppm[pixelToIndex(width, width-1-i, j) + k]; // assign the left RGB value as the right RGB value
          ppm[pixelToIndex(width, width-i-1, j) + k] = storing[k]; // get the temporary values into the right RGB value
        }
      }
    } 
  }
  
  else{ // if horizontally, there is an even number of pixels 
    for(int j=0; j<height; j++){ // iterate over each row of the image
      for(int i=0; i<(width)/2; i++){ // counting one swap as one action, I need to swap (width-1)/2 times
        for(int k=0; k<3; k++){ // each pixel has three corresponding values to RGB
            int storing[3] = {}; //initialize an array to store temporary values
            storing[k] = ppm[pixelToIndex(width, i, j) + k]; // assign 'storing' as the left RGB values to be swapped
            ppm[pixelToIndex(width, i, j) + k] = ppm[pixelToIndex(width, width-1-i, j) + k];// assign the left RGB value as the right RGB value
            ppm[pixelToIndex(width, width-i-1, j) + k] = storing[k];// get the temporary values into the right RGB value
        }
      }
    }
  }
}     

void flipVertically(int width, int height, int* ppm) {
  if( (height%2) == 1){ // if vertically, there is an odd number of pixels
    for(int i=0; i<width; i++){ // iterate over each column of the image
      for(int j=0; j<(height-1)/2; j++){ // counting one swap as one action, I need to swap (height-1)/2 times
        for(int k=0; k<3; k++){ // each pixel has three corresponding values to RGB
          int storing[3] = {}; //initialize an array to store temporary values
          storing[k] = ppm[pixelToIndex(width, i, j)+k]; // assign 'storing' as the top RGB values to be swapped
          ppm[pixelToIndex(width, i, j)+k] = ppm[pixelToIndex(width, i, height-1-j)+k]; // assign the top RGB value as the bottom RGB value
          ppm[pixelToIndex(width, i, height-1-j)+k] = storing[k]; // get the temporary values into the bottom RGB value
        }
      }
    }
  }
  else{ // if horizontally, there is an even number of pixels 
    for(int i=0; i<width; i++){ // iterate over each column of the image
      for(int j=0; j<(height)/2; j++){ // counting one swap as one action, I need to swap (height-1)/2 times
        for(int k=0; k<3; k++){ // each pixel has three corresponding values to RGB
          int storing[3] = {}; //initialize an array to store temporary values
          storing[k] = ppm[pixelToIndex(width, i, j)+k]; // assign 'storing' as the top RGB values to be swapped
          ppm[pixelToIndex(width, i, j)+k] = ppm[pixelToIndex(width, i, height-1-j)+k];// assign the top RGB value as the bottom RGB value
          ppm[pixelToIndex(width, i, height-1-j)+k] = storing[k]; // get the temporary values into the bottom RGB value
        }
      }
    }
  }
}    
    
  
/* Remember that the two flips are significantly harder than the
   other transofmations. We recommend that you work out the math
   on paper before attempting to write the code.
*/
