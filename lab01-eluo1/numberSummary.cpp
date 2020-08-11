/*
  Copyright (c) 2020
  Swarthmore College Computer Science Department, Swarthmore PA
  J. Brody, A. Danner, M. Gagne, L. Meeden, Z. Palmer, A. Soni, M. Wehar
  Distributed as course material for Spring 2020
  CPSC 035: Data Structures and Algorithms
  https://tinyurl.com/vdxo2w8
*/
#include<iostream>
#include<fstream>

using namespace std;

float getLargestNum(float* array, int size);
int countLessThanTen(float* array, int size);
float calcAverage(float* array, int size);

int main() {
    string filename; int size; float x;

    //prompt user input
    cout << "Please input file name: ";
    cin >> filename;

    //open file
    ifstream rawdata;
    rawdata.open(filename);

    //safety
    if (!rawdata) {
    cout << "Unable to open file datafile.txt";
    exit(1);   // call system to stop
}
    //allocate my array so that it is ready for file streaming
    rawdata >> size; // get array size
    float * array; //dynamically allocating array
    array = new float[size]; 

    //file stream data from the file to array
    int i = 0;
    while (rawdata >> x){
      array[i++] = x;
    }

    //close file
    rawdata.close();

    // output
    cout << "The last number is " << array[size-1] << "." << endl;
    cout << "The largest number is " << getLargestNum(array, size) << "." << endl;
    cout << "There are " << countLessThanTen(array, size) << " less than 10 in the sequence." << endl;
    cout << "The average is " << calcAverage(array, size) << endl;

    delete array;
    return 0;
    }

float getLargestNum(float* array, int size){
  float num = array[0]; //initialize largest number
  for (int i=0; i<size;i++){
    if(array[i]>num){ //if there is a larger number
      num = array[i]; //overwrite the larger number as the largest number
    }
  }
  return num; //return the largest number
}

int countLessThanTen(float* array, int size){
  int counter = 0; // initialize counter
  for (int i=0; i<size;i++){
    if(array[i]<10){ //if there is an element less than 10
      counter++; //increment counter by 1
    }
  }
  return counter; 
}

float calcAverage(float* array, int size){
  float sum = 0; //initialize sum
  for (int i=0; i<size;i++){
    sum += array[i]; //sum up over all entries of the array
  }
  return sum / size; //return the average
}
