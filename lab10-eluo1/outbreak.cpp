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
#include <random>

int main(int argc, char** argv) {
  // TO DO: write a program that models the spread of infectious diseases.
  //  * read in a directed, weighted graph.  edge weights represent the expected
  //   time it takes for src to infect dest given that src is infected.
  //  * for the input source vertex, determine the minimum amount of time it takes before each other vertex becomes infected.
  //  * If there is no src-->dest path, say that vertex src cannot infect vertex dest.
  //grab input arguments
  string filename = argv[1];
  string source = argv[2];

  //input verification
  if(argc != 3){
    throw runtime_error("Wrong number of arguments. Try again:");
  }
  
  Graph* graph = loadGraphFromFile(filename); //stream into object: graph

  // social distancing or no?
  std::cout << "Do you want to account for social distancing? Answer 'Yes' or 'No'." << std::endl;
  string input;
  std::cin >> input;

  while(input != "No" && input != "Yes"){
    std::cout << "Do you want to account for social distancing? Answer 'Yes' or 'No'." << std::endl;
    std::cin >> input;
  }

  if(input == "No"){ // if there is no social distancing
  }
  else { // yes there is social distancing
    // throw runtime_error("Social distancing part of the application is still buggy.");
    // How much social distancing then?
    std::cout << "What amount of social interaction for each individual is reduced? Please enter a floating point number between 0 and 1: " << std::endl;
    float SD; 
    std::cin >> SD; 
    while(SD < 0 || SD > 1){
      std::cout << "Input out of range. Please enter a floating point number between 0 and 1: " ;
      std::cin >> SD;
    }

    //Reduce edges depending on user input
    vector<string> vertices = graph->getVertices();
    for(int i=0; i<vertices.size(); i++){ //for each vertex
      vector<Edge> outgoingEdges = graph->getOutgoingEdges(vertices[i]);
      
      //reference: http://cplusplus.com/reference/random/bernoulli_distribution/reset/
      std::default_random_engine generator;//random generator
      std::bernoulli_distribution distribution(SD); //Bernoulli distribution with probability of success SD, success here is deletion of an edge.
      
      for(int j=0; j<outgoingEdges.size(); j++){//for each outgoing edge from the current vertex
        if(distribution(generator)){
          graph->removeEdge(vertices[i], outgoingEdges[j].destination);
        }
      }
      distribution.reset(); //reset distribution for each vertex
    }
  } 

  Dictionary<string, int>* SSSP = singleSourceShortestPath(source, graph);

  if(SSSP->isEmpty()){
    std::cout << "No infection from this person is possible. " << std::endl; 
    delete graph;
    delete SSSP; 
    return 0;
  }

  std::cout << "The following is the list of people that " << source << " can infect and the minimum number of days for each infection to occur:" << std::endl;
  vector<string> people = SSSP->getKeys();
  
  for(int i=0; i<people.size(); i++){
    std::cout << "---> " << people[i] << ": "<< std::to_string(SSSP->get(people[i])) << std::endl;
  }

  delete graph;
  delete SSSP;
  return 0;

    
}
