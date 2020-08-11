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

/**
 * Checks via UnitTest++ that the contents of two files are equal.  The file
 * containing the expected contents is given first.  If the two files do not
 * match, then a unit test failure is recorded.  A boolean is also returned to
 * indicate success or failure in case the caller wants to use it to e.g.
 * terminate further tests.
 * @param expected_path The path of the file containing the expected contents.
 * @param actual_path The path of the file containing the contents to check.
 * @return true if the files are equal by the definition of the PPM format;
 *         false if they are not.
 */
bool CHECK_FILES_EQUAL(std::string expected_path, std::string actual_path);
