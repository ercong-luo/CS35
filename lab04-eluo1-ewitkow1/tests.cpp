/*
  Copyright (c) 2020
  Swarthmore College Computer Science Department, Swarthmore PA
  J. Brody, A. Danner, M. Gagne, L. Meeden, Z. Palmer, A. Soni, M. Wehar
  Distributed as course material for Spring 2020
  CPSC 035: Data Structures and Algorithms
  https://tinyurl.com/vdxo2w8
*/

#include <UnitTest++/UnitTest++.h>
#include <iostream>

#include "mergeSort.h"

using namespace std;

TEST(threeElements) {
  // Create a static array containing the numbers 4, 8, 6.
  int array[3] = {4, 8, 6};
  mergeSort(array, 3);
  CHECK_EQUAL(4, array[0]);
  CHECK_EQUAL(6, array[1]);
  CHECK_EQUAL(8, array[2]);
}

TEST(reverseSorted) {
  int size = 20;
  // Create a dynamically-allocated array
  int *array = new int[size];
  for (int i = 0; i < size; i++) {
    array[i] = size - 1 - i;
  }
  mergeSort(array, size);
  for (int i = 0; i < size; i++) {
    CHECK_EQUAL(i, array[i]);
  }
  // de-allocate array
  delete[] array;
  array = nullptr;
}

// TODO: put your other tests here
//Sorting a single-element array to make sure nothing bad happens.
TEST(singlesSorted){
  int array[1] = {6};
  mergeSort(array, 1);
  CHECK_EQUAL(6,array[0]);
}

//Sorting an array that is already in order and seeing whether it stays that way.
TEST(leaveGoodOnesAlone){
  int size = 20;
  // create a dynamically allocated array
  int *array = new int[size];
  for (int j=0; j<size; j++){
    array[j] = j*j+1; // j^2+1 increases monotonically with respect to j, therefore array as defined is already in order
  }

  // call mergeSort
  mergeSort(array, size);

  // check implementation
  for (int j=0; j<size; j++){
    CHECK_EQUAL(j*j+1 , array[j]);
  }

  // de-allocate array
  delete[] array;
  array = nullptr;
}


//Sorting a large array of numbers that approach a midpoint from opposite directions (e.g. [0,999,1,998,2,997,…​]).
TEST(midpoint_approach){
  int size = 1000;
  // create a dynamically allocated array
  int *array = new int[size];
  // create counter for else loop
  int x = 0;
  for (int j=0; j<size; j++){
    if(j%2 == 0){
      array[j] = j/2;
    }
    else{
      //array[999-j] = 500+j/2;
      array[j] = 1000 - j + x;
      x+=1;
    }
  }

  // call mergeSort
  mergeSort(array, size);  

  //test implementation
  for(int j=0; j<size; j++){
    CHECK_EQUAL(j, array[j]);
  }

  // de-allocate array
  delete[] array;
  array = nullptr;
}

//Sorting an array that contains several duplicates to make sure that they are handled properly.
TEST(dup_test){
  //init test array with duplicates
  int array[5] = {4,8,8,6,10};

  //run mergesort
  mergeSort(array,5);

  //init correctly sorted array
  int array_correct[5] = {4,6,8,8,10};

  //implement test
  for(int k=0;k<5;k++){
    CHECK_EQUAL(array_correct[k],array[k]);
  }
}

/* no need to modify main */
int main() {
  return UnitTest::RunAllTests();
}
