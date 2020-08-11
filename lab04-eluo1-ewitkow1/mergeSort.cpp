/*
  Copyright (c) 2020
  Swarthmore College Computer Science Department, Swarthmore PA
  J. Brody, A. Danner, M. Gagne, L. Meeden, Z. Palmer, A. Soni, M. Wehar
  Distributed as course material for Spring 2020
  CPSC 035: Data Structures and Algorithms
  https://tinyurl.com/vdxo2w8
*/

#include "mergeSort.h"

// TODO: you will need to write an appropriate "merge" function here
// It does not need to be in your header file because no one else will call it.

void merge(int *A1, int n1, int *A2, int n2, int *result);

void mergeSort(int *array, int length) {
  int *A1, *A2; // pointers for divided arrays A1 and A2
  int s1, s2; // sizes for the divided arrays A1 and A2

  if(length <= 1){ //base case: if there is just one element or none in the input array
    return; // just return the input untouched
  }

  if(length % 2 == 1){ // if there are an odd number of elements in input array
    s1 = (length+1)/2; // consistently make A1 the larger array between the two divided arrays
    s2 = (length-1)/2;
  }
  else{
    s1 = length/2;
    s2 = length/2;
  }

  // dynamically allocate the divided arrays 
  A1 = new int[s1];
  A2 = new int[s2];

  // assign 'A1' and 'A2' the entries of 'array'
  for(int i=0; i<length; i++){
    if(i<s1){
      A1[i] = array[i];
    }
    else{
      A2[i-s1] = array[i];
    }
  }

  
  mergeSort(A1, s1); // recursion 
  mergeSort(A2, s2); // recursion 
  merge(A1,s1,A2,s2,array); //merge the sorted divided arrays

  // free up heap memory
  delete[] A1;
  delete[] A2;
}

void merge(int* A1, int s1, int* A2, int s2, int* result){
  int i,j,k;
  i=0; // index for A1
  j=0; // index for A2
  k=0; // index for result

  // merge based on array values
  while(i<s1 && j<s2){
    if(A1[i] > A2[j]){
      result[k++] = A2[j++]; // assign kth element of result as jth element of A2, increment both k and j by 1
    }
    else{
      result[k++] = A1[i++]; // assign kth element of result as ith element of A1, increment both k and i by 1
    }
  }

  while(i<s1){ // if s1 > s2
    result[k++] = A1[i++]; // assign kth element of result as ith element of A1, increment both k and i by 1
  }
  while(j<s2){ // if s2 > s1
    result[k++] = A2[j++]; // assign kth element of result as jth element of A2, increment both k and j by 1
  }
}
