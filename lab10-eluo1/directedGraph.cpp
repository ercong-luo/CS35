/*
  Copyright (c) 2020
  Swarthmore College Computer Science Department, Swarthmore PA
  J. Brody, A. Danner, M. Gagne, L. Meeden, Z. Palmer, A. Soni, M. Wehar
  Distributed as course material for Spring 2020
  CPSC 035: Data Structures and Algorithms
  https://tinyurl.com/vdxo2w8
*/

#include "directedGraph.h"
#include <string>
#include <stdexcept>

using std::to_string;
using std::runtime_error;

DirectedGraph::DirectedGraph(vector<string> vertices, vector<Edge> edges) {
  for(int i=0; i<vertices.size(); i++) {
    this->adjList.insert(vertices[i], new vector<Edge>());
  }
  for(int i=0; i<edges.size(); i++) {
    this->insertEdge(edges[i].source, edges[i].destination, edges[i].weight);
  }
}

DirectedGraph::~DirectedGraph() {
  // the values in our dictionary are *pointers* to Edge vectors
  // need to traverse through items and delete these one by one
  vector<pair<string,vector<Edge>*>> items = this->adjList.getItems();
  for(int i=0; i<items.size(); i++) {
    delete items[i].second;
    items[i].second = nullptr;
  }
}


void DirectedGraph::insertEdge(string src, string dest,
				    int weight) {
  if(!this->adjList.contains(src)) {
    throw runtime_error("vertex " + src + " doesn't exist");
  }
  if(!this->adjList.contains(dest)) {
    throw runtime_error("vertex " + dest + " doesn't exist");
  }


  // see if (src, dest) already in graph
  vector<Edge>* neighbors = this->adjList.get(src);
  for(int i=0; i<neighbors->size(); i++) {
    if(neighbors->at(i).destination == dest) {
      throw runtime_error("edge (" + src + ", "+ dest + ") already exists");
    }
  }

  this->adjList.get(src)->push_back(Edge(src, dest, weight));
}

void DirectedGraph::removeEdge(string src, string dest) {
  if(!this->adjList.contains(src)) {
    throw runtime_error("vertex " + src + " doesn't exist");
  }
  if(!this->adjList.contains(dest)) {
    throw runtime_error("vertex " + dest + " doesn't exist");
  }


  // now see if edge is there to be removed
  vector<Edge>* neighbors = this->adjList.get(src);
  for(int i=0; i< neighbors->size(); i++) {
    if(neighbors->at(i).destination == dest) {
      neighbors->erase(neighbors->begin()+i, neighbors->begin()+i+1);
      return;
    }
  }

  // edge not found so throw error
  throw runtime_error("Edge does not exist from " + src
		      + " to " + dest);
}

bool DirectedGraph::containsEdge(string source, string destination) {
  // first check if source is even valid
  if(!this->adjList.contains(source)) {
    throw runtime_error("vertex " + source + " doesn't exist");
  }

  // otherwise iterate through edges
  vector<Edge>* neighbors = this->adjList.get(source);
  for(int i=0; i< neighbors->size(); i++) {
    if(neighbors->at(i).destination == destination) {
      return true;
    }
  }

  // no edge found
  return false;
}

Edge DirectedGraph::getEdge(string source, string destination) {
  if(!this->adjList.contains(source)) {
    throw runtime_error("vertex " + source + " doesn't exist");
  }
  if(!this->adjList.contains(destination)) {
    throw runtime_error("vertex " + destination + " doesn't exist");
  }

  vector<Edge>* neighbors = this->adjList.get(source);
  for(int i=0; i< neighbors->size(); i++) {
    if(neighbors->at(i).destination == destination) {
      return neighbors->at(i);
    }
  }

  throw runtime_error("edge between " + source + " and "
		      + destination + " does not exist.");

}

vector<string> DirectedGraph::getVertices() {
  return this->adjList.getKeys();
}

vector<Edge> DirectedGraph::getEdges() {
  vector<Edge> results;
  vector<Edge>* neighbors;

  vector<pair<string,vector<Edge>*>> items = this->adjList.getItems();
  for(int i=0; i<items.size(); i++) {
    neighbors = items[i].second;
    for(int j=0; j<neighbors->size(); j++) {
      results.push_back(neighbors->at(j));
    }
  }
  return results;
}

vector<Edge> DirectedGraph::getOutgoingEdges(string source) {
  if(!this->adjList.contains(source)) {
    throw runtime_error("vertex " + source + " doesn't exist");
  }

  return *(this->adjList.get(source));
}


vector<string> DirectedGraph::getNeighbors(string source) {
  if(!this->adjList.contains(source)) {
    throw runtime_error("vertex " + source + " doesn't exist");
  }

  vector<string> results;

  vector<Edge>* neighbors = this->adjList.get(source);
  for(int i=0; i<neighbors->size(); i++) {
    results.push_back(neighbors->at(i).destination);
  }

  return results;
}
