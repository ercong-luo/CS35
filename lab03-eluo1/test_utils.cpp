/*
  Copyright (c) 2020
  Swarthmore College Computer Science Department, Swarthmore PA
  J. Brody, A. Danner, M. Gagne, L. Meeden, Z. Palmer, A. Soni, M. Wehar
  Distributed as course material for Spring 2020
  CPSC 035: Data Structures and Algorithms
  https://tinyurl.com/vdxo2w8
*/

#include <cstdarg>
#include <fstream>
#include <string>
#include <stdexcept>
#include <UnitTest++/UnitTest++.h>

using namespace std;

bool CHECK_FILES_EQUAL(string expected_path, string actual_path) {
    ifstream expected_file(expected_path.c_str());
    ifstream actual_file(actual_path.c_str());
    if (expected_file.fail()) {
        throw runtime_error("File could not be opened: " + expected_path);
    }
    if (actual_file.fail()) {
        throw runtime_error("File could not be opened: " + actual_path);
    }

    // Just keep reading until one of the files terminates.
    char expected_char;
    char actual_char;
    expected_file >> expected_char;
    actual_file >> actual_char;
    while (!expected_file.eof() && !actual_file.eof()) {
        if (expected_file.fail()) {
            throw runtime_error("Error reading from " + expected_path);
        }
        if (actual_file.fail()) {
            throw runtime_error("Error reading from " + actual_path);
        }
        CHECK_EQUAL(expected_char, actual_char);
        if (expected_char != actual_char) {
            return false;
        }
        expected_file >> expected_char;
        actual_file >> actual_char;
    }
    if (!expected_file.eof() || !actual_file.eof()) {
        throw runtime_error("Files are not of equal length.");
    }
    return true;
}
