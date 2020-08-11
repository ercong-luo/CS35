/*
  Copyright (c) 2020
  Swarthmore College Computer Science Department, Swarthmore PA
  J. Brody, A. Danner, M. Gagne, L. Meeden, Z. Palmer, A. Soni, M. Wehar
  Distributed as course material for Spring 2020
  CPSC 035: Data Structures and Algorithms
  https://tinyurl.com/vdxo2w8
*/

// TO DO: include header files here
#include "graphAlgorithms.h"
#include "directedGraph.h"
#include "undirectedGraph.h"
#include <string>
#include <iostream>


int main(int argc, char** argv) {
  // TO DO: write a program that takes three inputs: a map, a source, and
  //   a destination.  Your program should see if you can get from source
  //   to destination on this graph.

  //input verification
  if(argc !=4){
    throw runtime_error("Incorrect number of command line arguments. This program needs four.");
  }
  
  //grab input arguments
  string filename = argv[1];
  string source = argv[2];
  string destination = argv[3];

  Graph* graph = loadGraphFromFile(filename);
  bool canReach = reachableDFS(source, destination, graph);

  std::cout << "You ";
  if(canReach){
    std::cout << "can ";
  }
  else{
    std::cout << "can't ";
  }
  std::cout << "go from " << source << " to " << destination << "." << std::endl;

  delete graph;
  return 0;
}
