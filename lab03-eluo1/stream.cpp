/*
  Copyright (c) 2020
  Swarthmore College Computer Science Department, Swarthmore PA
  J. Brody, A. Danner, M. Gagne, L. Meeden, Z. Palmer, A. Soni, M. Wehar
  Distributed as course material for Spring 2020
  CPSC 035: Data Structures and Algorithms
  https://tinyurl.com/vdxo2w8
*/

#include <iostream>

#include "stream.h"

using namespace std;

StreamCipher::StreamCipher(string configuration) {
   this->configuration = configuration;
   this->counter = 0;
   this->accumulator=0;

   // input validation: is every letter upper case? Throw runtime error if not. 
  for(int i=0; i<this->configuration.size(); i++){
      int alphabet_index =this-> configuration[i] - 'A';
      if(alphabet_index < 0 || alphabet_index >= 26){
          throw runtime_error("For configuration of substitution cipher, enter UPPER CASE letters only. Try again: ");
      }
  }

  // convert the configuration to alphabet indeces
    for(int i=0; i<this->configuration.size(); i++){ 
        this->configuration[i] = this->configuration[i] - 'A';
    }

}

StreamCipher::~StreamCipher() {
}

char StreamCipher::encrypt(char c) {
    int alphabet_index = c - 'A'; // calculate the alphabetical index of the given character

    this->counter = this->counter % this->configuration.size(); // let the pointer point to where in the configuration string we are at right now
    this->accumulator += this->configuration[this->counter] + 1; // get how much we want to rotate the current character

    this->counter++; // increment the counter variable for the next operation
    return ((this->accumulator + alphabet_index) % 26)+ 'A'; 
}

char StreamCipher::decrypt(char c) {
    int alphabet_index = c - 'A'; // calculate the alphabetical index of the given character
    int offset;
    
    this->counter = this->counter % this->configuration.size(); // let the pointer point to where in the configuration string we are at right now
    this->accumulator += this->configuration[this->counter] + 1; // get how much we want to rotate the current character

    this->counter++; // increment the counter variable for the next operation
    offset = this->accumulator%26; // the offset can be over 26 easily so we want to make sure it stays within 26
    return (alphabet_index - offset+26) % 26 + 'A'; // return back the character; 
}
