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

class SubstitutionCipher : public Cipher {
public:
    SubstitutionCipher(std::string configuration);
    ~SubstitutionCipher();
    virtual char encrypt(char c);
    virtual char decrypt(char c);
private:
    std::string configuration;
};
