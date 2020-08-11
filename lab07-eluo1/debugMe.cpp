/*
  Copyright (c) 2020
  Swarthmore College Computer Science Department, Swarthmore PA
  J. Brody, A. Danner, M. Gagne, L. Meeden, Z. Palmer, A. Soni, M. Wehar
  Distributed as course material for Spring 2020
  CPSC 035: Data Structures and Algorithms
  https://tinyurl.com/vdxo2w8
*/

/* This program is supposed to get a positive integer from the first command
 *  line argument, then compute and print out the sum of every other integer up
 *  to the input limit.  For example:
 *
 *  ./debugMe 5     should compute 1+3+5 = 9
 *  ./debugMe 4     should compute 2+4 = 6
 *  ./debugMe 200   should compute 2+4+...+198+200 = 10100
 *
 * Unforutnately, there is an error that causes the program to segfault on some
 *  inputs.  TO DO: use GDB to identify the error, and fix the bug.
 *
 * To Compile this program, use clang++:
 *        clang++ -g -o debugMe debugMe.cpp
 *
 */

#include <iostream>
#include <string>

using namespace std;

/* addEveryOther
 *
 * Input: n, the number to add up to
 * Output: the sum of every other number up to and including n.
 */
int addEveryOther(int n) {
  // base case: stop recursing when n equals 0
  if(n == 0) {
    return 0;
  } else if (n == 1){
    return 1;
  }

  // general case:  add n to the sum of every other number up to n-2
  // we skipp n-1 because we're adding every other number.
  return n + addEveryOther(n-2);
}

int main(int argc, char **argv) {
  int limit;

  if(argc < 2) {
    cout << "Invalid number of arguments." << endl;
    cout << "Usage:  ./debugMe <number>" << endl;
    return 1;
  }

  limit = stoi(argv[1]);

  cout << "The sum of every other number up to " << limit << " equals "
    << addEveryOther(limit) << endl;
}
