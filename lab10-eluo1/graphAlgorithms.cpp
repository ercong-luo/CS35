/*
  Copyright (c) 2020
  Swarthmore College Computer Science Department, Swarthmore PA
  J. Brody, A. Danner, M. Gagne, L. Meeden, Z. Palmer, A. Soni, M. Wehar
  Distributed as course material for Spring 2020
  CPSC 035: Data Structures and Algorithms
  https://tinyurl.com/vdxo2w8
*/

#include <stdexcept>
#include <fstream>

#include "graphAlgorithms.h"
#include "adts/stlBST.h"
#include "adts/stlMinPriorityQueue.h"
#include "adts/stlQueue.h"
#include "adts/stlStack.h"
#include "directedGraph.h"
#include "undirectedGraph.h"

using std::ifstream;

bool reachableDFS(string src, string dest, Graph *g) { //works for any graph: weighted or not, directed or not
  //input verification
  if(src == dest){
    return true;
  } else{
    vector<string> vertices = g->getVertices();
    bool flag1, flag2;
    flag1 = true;
    flag2 = true;
    for(int i = 0; i < vertices.size(); i++){
      if(vertices[i] == src){
        flag1 = false;
      } else if(vertices[i] == dest){
        flag2 = false;
      }
    }
    if(flag1 || flag2){
      throw runtime_error("Recheck source and destination vertices.");
    }
  }

  //DFS starts here
  Stack<string>* stack = new STLStack<string>(); //DFS uses a stack
  Dictionary<string,bool>* visited = new STLBST<string, bool>(); 
  
  //get started
  stack->push(src);
  visited->insert(src,true);

  while(!stack->isEmpty()){ //still vertices to explore
    string current = stack->pop();
    if(current == dest){ // found it! return true and exit
      delete stack;
      delete visited;
      return true;
    } else{ // keep looking
      vector<string> neighbors = g->getNeighbors(current);
      // Dictionary<string,bool>* BSTneighbors = new STLBST<string,string>();
      for(int i=0; i<neighbors.size(); i++){ //go through each neighbor of current vertex
        if(!visited->contains(neighbors[i])){
          stack->push(neighbors[i]);
          visited->insert(neighbors[i],true); //mark the neighbor we visited
        }
      }
    }
  }

  delete stack;
  delete visited;
  return false; 
}

vector<string> shortestLengthPathBFS(string src, string dest, Graph *g) {//unweighted, directed or undirected
  vector<string> path;

  //input verification
  vector<string> vertices = g->getVertices();
  if(src == dest){
    path.push_back(src);
    return path;
  } else{
    bool flag1, flag2;
    flag1 = true;
    flag2 = true;
    for(int i = 0; i < vertices.size(); i++){
      if(vertices[i] == src){
        flag1 = false;
      } else if(vertices[i] == dest){
        flag2 = false;
      }
    }
    if(flag1 || flag2){
      throw runtime_error("Recheck source and destination vertices.");
    }
  }

  //BFS starts here
  Queue<string>* queue = new STLQueue<string>(); //BFS utilizes a queue
  Dictionary<string,string>* previous = new STLBST<string,string>(); //dictionary for constructing path later

  queue->enqueue(src);
  previous->insert(src,src);

  while(!queue->isEmpty()){
    string current = queue->dequeue();
    if(current == dest){ //found it! generate and return path, exit
      while(current != src){//generate path in reverse
        path.push_back(current);
        current = previous->get(current);
      }
      path.push_back(current);
      for(int j=0; j < path.size()/2; j++){ //flip path so that it is in order
        string temp = path[j];
        path[j] = path[path.size()-j-1];
        path[path.size()-j-1] = temp;
      }
      delete queue;
      delete previous;
      return path;

    } else{
      vector<string> neighbors = g->getNeighbors(current);
      for(int i=0; i<neighbors.size(); i++){
        if(!previous->contains(neighbors[i])){
          previous->insert(neighbors[i], current);
          queue->enqueue(neighbors[i]);
        }
      }
    }
  }

  delete queue;
  delete previous;
  throw runtime_error("No path exists from source to destination."); //should I throw runtime error here?
}

Dictionary<string,int> *singleSourceShortestPath(string src, Graph *g) {//weighted and directed, solved using Dijkstra's algorithm
  
  //input verification
  bool flag = true;
  vector<string> vertices = g->getVertices();
  for(int i=0; i<vertices.size(); i++){
    if(vertices[i] == src){
      flag = false;
    }
  }
  if(flag){
    throw runtime_error("Recheck source vertex.");
  }

  //Dijkstra's Algorithm starts here
  Dictionary<string,int>* output = new STLBST<string,int>(); //this is to be returned
  PriorityQueue<int, string>* pq = new STLMinPriorityQueue<int, string>(); //SSSP utilizes a minimum priority queue

  output->insert(src, 0);
  pq->insert(0,src);

  while(!pq->isEmpty()){
    int currentP = pq->peekPriority();
    string currentV = pq->remove();
    int currentCost = output->get(currentV);
    if(currentCost == currentP){
      vector<Edge> edges = g->getOutgoingEdges(currentV);
      for(int i=0; i<edges.size(); i++){
        string next = edges[i].destination;
        int newCost = currentCost+edges[i].weight;
        if(!output->contains(next)){
          output->insert(next,newCost);
          pq->insert(newCost, next);
        }
        else if(newCost < output->get(next)){
          output->update(next, newCost);
          pq->insert(newCost,next);
        }
      }
    }
  }

  delete pq;
  return output;
}

Graph* loadGraphFromFile(string graphFile) {
  ifstream mapFile;
  mapFile.open(graphFile);

  int n,m;
  mapFile >> n >> m;

  string temp;
  bool weighted = true;
  bool directed = false;
  mapFile >> temp;
  if(temp == "weighted") {
    weighted = true;
  } else if (temp == "unweighted") {
    weighted = false;
  } else {
    throw runtime_error("invalid choice for weight");
  }

  mapFile >> temp;
  if(temp == "undirected") {
    directed = false;
  } else if(temp == "directed") {
    directed = true;
  } else {
    throw runtime_error("invalid choice for directed");
  }

  vector<string> vertices;
  for(int i=0; i< n; i++) {
    mapFile >> temp;
    vertices.push_back(temp);
  }

  vector<Edge> edges;
  string src,dest;
  int weight;
  for(int i=0; i<m; i++) {
    mapFile >> src;
    mapFile >> dest;
    if(weighted) {
      mapFile >> weight;
      edges.push_back(Edge(src, dest, weight));
    } else {
      edges.push_back(Edge(src,dest));
    }
  }

  if(directed) {
    return new DirectedGraph(vertices,edges);
  }
  return new UndirectedGraph(vertices,edges);
}
