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

using std::string;

/**
 * An Edge is a class that represents a directed, weighted edge in a
 * graph.
 */
class Edge {
public:
  // This constructor specifies initial values of each data member
  Edge(string src, string dest, int wt) : source(src),
    destination(dest), weight(wt) {};

  // For unweighted graphs, initialize the "weight" to 1
  Edge(string src, string dest) : source(src),
    destination(dest), weight(1) {};


  string source;
  string destination;
  int weight;
};
