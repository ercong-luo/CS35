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

using namespace std;

// TO DO: modify main to ask the user to enter a name, then say hello to
// that person (using their name)
int main(int argc, char **argv) {
  string name;
  cout << "Please enter your name: " << endl;
  cin >> name;
  cout << "hello " << name << endl;
}
