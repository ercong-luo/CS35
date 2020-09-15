#pragma once
/*
  Copyright (c) 2020
  Swarthmore College Computer Science Department, Swarthmore PA
  J. Brody, A. Danner, M. Gagne, L. Meeden, Z. Palmer, A. Soni, M. Wehar
  Distributed as course material for Spring 2020
  CPSC 035: Data Structures and Algorithms
  https://tinyurl.com/vdxo2w8
*/

#include "adts/edge.h"
#include "adts/graph.h"
#include "adts/stlBST.h"


class DirectedGraph : public Graph {
public:
  DirectedGraph(vector<string> vertices, vector<Edge> edges);
  virtual ~DirectedGraph();

  virtual void insertEdge(string src, string dest, int weight);
  virtual void removeEdge(string src, string dest);
  virtual bool containsEdge(string source, string destination);
  virtual Edge getEdge(string source, string destination);
  virtual vector<string> getVertices();
  virtual vector<Edge> getEdges();
  virtual vector<Edge> getOutgoingEdges(string source);
  virtual vector<string> getNeighbors(string source);

private:
  STLBST<string, vector<Edge>*> adjList;
};
