/*
  Copyright (c) 2020
  Swarthmore College Computer Science Department, Swarthmore PA
  J. Brody, A. Danner, M. Gagne, L. Meeden, Z. Palmer, A. Soni, M. Wehar
  Distributed as course material for Spring 2020
  CPSC 035: Data Structures and Algorithms
  https://tinyurl.com/vdxo2w8
*/

#include <string>
#include <stdexcept>

#include "substitution.h"

using namespace std;

SubstitutionCipher::SubstitutionCipher(string configuration) {
    this->configuration = configuration; 

    // input validation: are there exactly 26 letters given?
    if(configuration.size() != 26){
        throw runtime_error("The substitution needs exactly 26 letters. The given input does not satisfy this condition. Try again: ");
    }

    // input validation: is every letter capital letter?
    for(int i=0; i<configuration.size(); i++){
        int alphabet_index = configuration[i] - 'A';
        if(alphabet_index < 0 || alphabet_index >= 26){
            throw runtime_error("For configuration of substitution cipher, please enter UPPER CASE letters only. Try again: ");
        }
    }

    // input validation: is every letter given distinct from every other letter?
    // **please read note below the largest for loop below
    for(int i=0; i<configuration.size(); i++){
        for(int j=i+1; j<configuration.size(); j++){
            if(configuration[i] == configuration[j]){
                throw runtime_error("There are repeated letters in the configuration argument. Try again: ;");
            }
        }
    }
    // **The implementation above is equivalent to checking whether there is a letter that appeared more than once,
    // because I have already checked that there are 26 letters and they are all upper case letters, therefore:
    // there is no letter in the configuration that appeared twice <==> every letter in the given string is distinct from each other

    // convert the configuration to alphabet indeces
    for(int i=0; i<configuration.size(); i++){ 
        this->configuration[i] = this->configuration[i] - 'A';
    }
}

SubstitutionCipher::~SubstitutionCipher() {
}

char SubstitutionCipher::encrypt(char c) {
    int alphabet_index = c - 'A'; // calculate the index of the given character
    
    return this->configuration[alphabet_index]+ 'A';
}

char SubstitutionCipher::decrypt(char c) {
    int alphabet_index = c - 'A'; // calculate the index of the given character
    int offset = 0; // init

    // find the entry of configuration where the index of c matches
    // the position of this entry of configuration is the alphabet index of the encrypted letter
    for(int i=0; i< this->configuration.size(); i++){
        if(alphabet_index == this->configuration[i]){
            offset=i;
            break;
        }
    }
    return offset + 'A'; // return back a character;
    
}
