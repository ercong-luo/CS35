/*
  Copyright (c) 2020
  Swarthmore College Computer Science Department, Swarthmore PA
  J. Brody, A. Danner, M. Gagne, L. Meeden, Z. Palmer, A. Soni, M. Wehar
  Distributed as course material for Spring 2020
  CPSC 035: Data Structures and Algorithms
  https://tinyurl.com/vdxo2w8
*/

#include <iostream>
#include <fstream>
#include "cipher.h"
#include "caesar.h"
#include "rotation.h"
#include "substitution.h"
#include "stream.h"
#include "enigma.h"
#include <stdexcept> // to throw runtime_error

using namespace std;

void validateInput(int argc, char** argv); // a function that validates command line arguments
string readAsString(string ifname); // a function that will read in an input file name and return file contents as a string
string encryptOrDecrypt(Cipher* cipher_poitner, string operation, string input_string); // a function that operates encryption/decryption on the given string
void writeStringOut(string output_string, string ofname); // a function that writes out the encrypted/decrypted string into a file with the given output file name 

int main(int argc, char** argv) {

  // input validation command line input by checking: argument count, operation and cipher name
  validateInput(argc, argv);

  // store the input arguments in string variables
  string ifname, ofname, operation, cipher_name, configuration;
  ifname = argv[1];
  operation = argv[2];
  cipher_name = argv[3];
  configuration = argv[4];
  ofname = argv[5];
  

  // read in input file as a char array
  string input_string;
  input_string = readAsString(ifname);

  // create the cipher pointer according to what cipher is wanted by user
  Cipher* cipher_pointer;  // declare cipher pointer
  if (cipher_name == "caesar"){
    cipher_pointer = new CaesarCipher(configuration);  
  }
  else if (cipher_name == "rotation"){
    cipher_pointer = new RotationCipher(configuration);  
  }
  else if (cipher_name == "substitution"){
    cipher_pointer = new SubstitutionCipher(configuration);  
  }
  else if (cipher_name == "stream"){
    cipher_pointer = new StreamCipher(configuration);  
  }
  else{ // input validation: is the given cipher name valid
    throw runtime_error("Either your entered 'enigma' which isn't yet implemented, or the given cipher name is invalid. Please try again: ");
  }

  // Use cipher_pointer to convert the file contents into a new string
  string output_string;
  output_string = encryptOrDecrypt(cipher_pointer, operation, input_string);

  
  // Write the resulting string to the output file.
  writeStringOut(output_string, ofname);
  
  delete cipher_pointer; // deallocate memory

  return 1; 
}


void validateInput(int argc, char** argv){
  // input validation: argument count
  if(argc != 6){
    throw runtime_error("Incorrent number of command line arguments. There should be 5. ");
  }

  string operation = argv[2];
  // input validation: is argv[2] actually "decrypt" or "encrypt"?
  if(operation != "decrypt" && operation != "encrypt"){
    throw runtime_error("For the third commandline argument, please enter 'encrypt' or 'decrypt': ");
  }
}

string readAsString(string ifname){

  ifstream File; // declare file stream-in
  File.open(ifname); //open file
  File >> noskipws; // do not skip spaces

  string input_string = ""; // initialize the string
  char d; // declare placeholder character-typed variable d

  File >> d; 
  while(!File.eof()) {
    input_string += d; // concatenate d with the current string c
    File >> d; // stream characters in from the input file
  }
  File.close(); // close the file

  return input_string;
}

string encryptOrDecrypt(Cipher* cipher_pointer, string operation, string input_string){
  string c = ""; // initialize a place holder string variable
  if(operation == "encrypt"){ 
    for(int i=0; i<input_string.size(); i++){ // encrypt through the entire string
      if(input_string[i] >= 'A' && input_string[i] <= 'Z'){ // if the current letter is upper case
        c += cipher_pointer->encrypt(input_string[i]); // encrypt this letter and append to output string
      }
      else{ // if the current letter is not an upper case letter
        c += input_string[i]; // skip encryption for the current letter and append to output string
      }
    }
  }
  else {
    for(int i=0; i<input_string.size(); i++){
      if(input_string[i] >= 'A' && input_string[i] <= 'Z'){ // if the current letter is upper case
        c += cipher_pointer->encrypt(input_string[i]); // decrypt this letter and append to output string
      }
      else{ // if the current letter is not an upper case letter
        c += input_string[i]; // skip decryption for the current letter and append to output string
      }
    }
  }
  return c;
}

void writeStringOut(string output_string, string ofname){
  ofstream outFile;
  outFile.open(ofname);
  outFile << output_string;
  outFile.close();
}