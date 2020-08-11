#pragma once
/*
  Copyright (c) 2020
  Swarthmore College Computer Science Department, Swarthmore PA
  J. Brody, A. Danner, M. Gagne, L. Meeden, Z. Palmer, A. Soni, M. Wehar
  Distributed as course material for Spring 2020
  CPSC 035: Data Structures and Algorithms
  https://tinyurl.com/vdxo2w8
*/

#include <string>

#include "cipher.h"

class StreamCipher : public Cipher {
public:
    StreamCipher(std::string configuration);
    ~StreamCipher();
    virtual char encrypt(char c);
    virtual char decrypt(char c);
private:
    std::string configuration;
    int counter; // a counter to account for where in the configuration string we are at when encrypting a character
    int accumulator; // an accumulator is required since the number of rotations in the stream algorithm accumulates
};
