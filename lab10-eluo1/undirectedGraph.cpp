/*
  Copyright (c) 2020
  Swarthmore College Computer Science Department, Swarthmore PA
  J. Brody, A. Danner, M. Gagne, L. Meeden, Z. Palmer, A. Soni, M. Wehar
  Distributed as course material for Spring 2020
  CPSC 035: Data Structures and Algorithms
  https://tinyurl.com/vdxo2w8
*/
#include "undirectedGraph.h"

UndirectedGraph::UndirectedGraph(vector<string> vertices, vector<Edge> edges)
 : DirectedGraph(vertices, vector<Edge>()) {

   // need to explicitly add edges here to force undirected insertEdge
   for(int i=0; i<edges.size(); i++) {
     this->insertEdge(edges[i].source, edges[i].destination, edges[i].weight);
   }
 }

void UndirectedGraph::insertEdge(string src, string dest, int weight) {
  // insert the edge as two directional edges.
  // This lets getNeighbors to work without changes
  DirectedGraph::insertEdge(src, dest, weight);
  DirectedGraph::insertEdge(dest, src, weight);
}

void UndirectedGraph::removeEdge(string src, string dest) {
  DirectedGraph::removeEdge(src, dest);
  DirectedGraph::removeEdge(dest, src);
}

vector<Edge> UndirectedGraph::getEdges() {
  vector<Edge> toReturn;
  vector<Edge> withDups = DirectedGraph::getEdges();
  bool foundDup = false;

  // iterate over withDups.  add in only if not already there.
  for (int i = 0; i < withDups.size(); i++) {
    foundDup = false;
    for (int j = 0; j < toReturn.size(); j++) {
      if ((withDups[i].source == toReturn[j].destination) &&
          (withDups[i].destination == toReturn[j].source)) {
        foundDup = true;
        break;
      }
    }
    if (!foundDup) {
      toReturn.push_back(withDups[i]);
    }
  }

  return toReturn;
}
