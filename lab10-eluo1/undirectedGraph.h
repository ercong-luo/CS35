#pragma once

/*
  Copyright (c) 2020
  Swarthmore College Computer Science Department, Swarthmore PA
  J. Brody, A. Danner, M. Gagne, L. Meeden, Z. Palmer, A. Soni, M. Wehar
  Distributed as course material for Spring 2020
  CPSC 035: Data Structures and Algorithms
  https://tinyurl.com/vdxo2w8
*/

#include "directedGraph.h"

/**
 * UndirectedGraph is a class representing
 *   undirected, weighted graphs.
 *
 * It is a subclass of DirectedGraph for the purpose of code reuse.
 */
class UndirectedGraph : public DirectedGraph {
public:
  UndirectedGraph(vector<string> vertices, vector<Edge> edges);

 /**
 * Adds an undirected edge to this graph.
 * @param source The source vertex for the edge.
 * @param destination The destination vertex for the edge.
 * @param weight The weight of the edge to add.
 * @throws runtime_error If an edge already exists between the given source
 *                       and target.
 */
  void insertEdge(string src, string dest, int weight);

/**
 * Removes an edge from this graph.
 * @param source The source vertex for the edge.
 * @param destination The destination vertex for the edge.
 * @throws runtime_error If the edge does not exist.
 */
  void removeEdge(string src, string dest);

  /**
 * Retrieves all edges from this graph.
 * @return A vector containing every edge in this graph.
 */
  vector<Edge> getEdges();
};
