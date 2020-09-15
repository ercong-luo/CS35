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
  // TO DO: write a program that models a wireless communication network.
  //  Your program should take as input three arguments: a graph, a source, and a destination.
  //  Determine if the source is <= 4 edges away from the destination vertex.
  //  Output whether or not the destination is close to the source vertex, and print out the shortest path.  If there is no source-->destination path, say so.
  
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
  if(!canReach){
    std::cout << "Communication is not possible from source to destination." << std::endl;
    delete graph;
    return 0;
  } 
  else{
    std::cout << "It is possible to communicate from source to destination." << std::endl;
    vector<string> path = shortestLengthPathBFS(source, destination, graph);
    std::cout << "The destination is " << std::to_string(path.size() - 1) << " steps from the source vertex." << std::endl;
    if(path.size()>4){
      std::cout << "Note that the destination is quite far from the source!" << std::endl;
    }
    std::cout << "Here is the shortest path: [";
    for(int i=0; i<path.size()-1; i++){
      std::cout << path[i] << " ";
    }
    std::cout << path[path.size()-1] << ']' << std::endl;
    
    delete graph;
    return 0;
  }
}
