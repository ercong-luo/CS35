/*
  Copyright (c) 2020
  Swarthmore College Computer Science Department, Swarthmore PA
  J. Brody, A. Danner, M. Gagne, L. Meeden, Z. Palmer, A. Soni, M. Wehar
  Distributed as course material for Spring 2020
  CPSC 035: Data Structures and Algorithms
  https://tinyurl.com/vdxo2w8
*/

#include <string>

#include "rotation.h"

using namespace std;

RotationCipher::RotationCipher(string configuration) {
    this->configuration = stoi(configuration); // turns the configuration into an int
}

RotationCipher::~RotationCipher() {
}

char RotationCipher::encrypt(char c) {
    // Recall that we assume c to be an alphabetic upper-case character.  We now
    // calculate the index of that character in the alphabet.
    int alphabet_index = c - 'A';
    // Now update the index to reflect the encryption.
    alphabet_index += configuration;
    if (alphabet_index < 0) { // if we have rotated too far to the left
        alphabet_index += 26; 
    }
    else {
        alphabet_index %= 26; // if we have rotated too far to the right
    }
    // Now convert back to a letter.
    return 'A' + alphabet_index;// return back the upper case letter
}

char RotationCipher::decrypt(char c) {
    // Recall that we assume c to be an alphabetic upper-case character.  We now
    // calculate the index of that character in the alphabet.
    int alphabet_index = c - 'A';
    // Now update the index to reflect the encryption.
    alphabet_index -= configuration;
    if (alphabet_index < 0) { // if we have rotated too far to the left
        alphabet_index += 26;
    }
    else {
        alphabet_index %= 26; // if we have rotated too far to the right
    }
    // Now convert back to a letter.
    return 'A' + alphabet_index; // return back the upper case letter
}
