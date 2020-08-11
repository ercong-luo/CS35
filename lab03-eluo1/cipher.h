#pragma once
/*
  Copyright (c) 2020
  Swarthmore College Computer Science Department, Swarthmore PA
  J. Brody, A. Danner, M. Gagne, L. Meeden, Z. Palmer, A. Soni, M. Wehar
  Distributed as course material for Spring 2020
  CPSC 035: Data Structures and Algorithms
  https://tinyurl.com/vdxo2w8
*/

class Cipher {
public:
    virtual ~Cipher () { }

    /**
     * Encrypts a single character.
     * @param c The character to encrypt.  This is assumed to be an upper-case
     *          alphabetic character.
     * @return The encrypted character.
     */
    virtual char encrypt(char c) = 0; //makes the method 'encrypt' **pure virtual**

    /**
     * Decrypts a single character.
     * @param c The character to decrypt.  This is assumed to be an upper-case
     *          alphabetic character.
     * @return The decrypted character.
     */
    virtual char decrypt(char c) = 0; //makes 'decrypt' **pure virtual**
};
