/*
  Copyright (c) 2020
  Swarthmore College Computer Science Department, Swarthmore PA
  J. Brody, A. Danner, M. Gagne, L. Meeden, Z. Palmer, A. Soni, M. Wehar
  Distributed as course material for Spring 2020
  CPSC 035: Data Structures and Algorithms
  https://tinyurl.com/vdxo2w8
*/

#include <iostream>
#include <string>

#include "image.h"
#include "ppmio.h"

using namespace std;

int main(int argc, char** argv) {

  // TODO: write your program here
  // Remember:
  //   * The first command-line argument in argv is always the name of the
  //     program.
  //   * You can convert from char* to string just by assignment:
  //         string infile = argv[1];
  //   * You should (eventually) have code that deals with the case that your
  //     user gave you too few or too many command-line arguments.
  // Good luck!  Remember to ask for help!

  // To check there are the right number of command line arguments
  if(argc != 4){
    throw runtime_error("Redo command line arguments.");
  }

  string ifName, actionName, ofName; // declare input file name, action name
  ifName = argv[1]; // second argument is input file name
  actionName = argv[2]; // third argument is action name
  ofName = argv[3];// fourth argument is output file name

  // get the array of pixel values, the width and the height of the input image
  int* ppm = read_ppm(ifName);
  int width = ppm_width(ifName);
  int height = ppm_height(ifName);

  // call the transformation function that corresponds to actionName
  // if actionName is not one of the names of functions, throw error
  if(actionName == "noRed"){
    noRed(width, height, ppm);
  }
  else if (actionName == "noGreen"){
    noGreen(width, height, ppm);
  }
  else if (actionName == "noBlue"){
    noBlue(width, height, ppm);
  }
  else if (actionName == "invert"){
    invert(width, height, ppm);
  }
  else if (actionName == "grayscale"){
    grayscale(width, height, ppm);
  }
  else if (actionName == "flipHorizontally"){
    flipHorizontally(width, height, ppm);
  }
  else if (actionName == "flipVertically"){
    flipVertically(width, height, ppm);
  }
  else{
    throw runtime_error("Action not found."); // if actionName is not one of the names of functions, throw error
  }


  // write out the transformed image
  write_ppm(ofName, width, height, ppm); 

  return 0; // convention
}
