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

#include <UnitTest++/TestReporterStdout.h>
#include <UnitTest++/TestRunner.h>
#include <UnitTest++/UnitTest++.h>

using std::cout;
using std::endl;
using std::string;

int main(int argc, char** argv) {
    const int VALID_GROUP_COUNT = 4;
    string validGroups[4] = {"all", "linearDictionary", "hashTable", "scrabbleAssistant"};

    bool valid;
    if (argc != 2) {
        valid = false;
    } else {
        valid = false;
        for (int i = 0; i < VALID_GROUP_COUNT; i++) {
            if (validGroups[i] == argv[1]) {
                valid = true;
            }
        }
    }

    if (!valid) {
        cout << "You must give exactly one argument: the name of the group of "
                "tests to run."
             << endl;
        cout << "This may be any of the following:" << endl;
        for (int i = 0; i < VALID_GROUP_COUNT; i++) {
            cout << "    " << validGroups[i] << endl;
        }
        return 1;
    }

    char* suiteName;
    if (argv[1] == string("all")) {
        suiteName = NULL;
    } else {
        suiteName = argv[1];
    }

    UnitTest::TestReporterStdout reporter;
    UnitTest::TestRunner runner(reporter);
    return runner.RunTestsIf(UnitTest::Test::GetTestList(), suiteName,
                             UnitTest::True(), 0);
}
