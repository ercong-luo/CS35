/*
  Copyright (c) 2020
  Swarthmore College Computer Science Department, Swarthmore PA
  J. Brody, A. Danner, M. Gagne, L. Meeden, Z. Palmer, A. Soni, M. Wehar
  Distributed as course material for Spring 2020
  CPSC 035: Data Structures and Algorithms
  https://tinyurl.com/vdxo2w8
*/

#include <string>

#include "caesar.h"

using namespace std;

CaesarCipher::CaesarCipher(string configuration) {
    // Nothing to do.
}

CaesarCipher::~CaesarCipher() {
    // Nothing to do.
}

char CaesarCipher::encrypt(char c) {
    // Recall that we assume c to be an alphabetic upper-case character.  We now
    // calculate the index of that character in the alphabet.
    int alphabet_index = c - 'A';
    // Now update the index to reflect the encryption.
    alphabet_index -= 3;
    if (alphabet_index < 0) {
        alphabet_index += 26;
    }
    // Now convert back to a letter.
    return 'A' + alphabet_index;
}

char CaesarCipher::decrypt(char c) {
    // Recall that we assume c to be an alphabetic upper-case character.  As
    // above, we calculate its alphabetic index.
    int alphabet_index = c - 'A';
    // Now update the index to remove the encryption.
    alphabet_index += 3;
    alphabet_index %= 26;
    // And convert back to a letter.
    return 'A' + alphabet_index;
}
