#pragma once
/*
  Copyright (c) 2020
  Swarthmore College Computer Science Department, Swarthmore PA
  J. Brody, A. Danner, M. Gagne, L. Meeden, Z. Palmer, A. Soni, M. Wehar
  Distributed as course material for Spring 2020
  CPSC 035: Data Structures and Algorithms
  https://tinyurl.com/vdxo2w8
*/

#include <vector>
#include <string>

using std::string;
using std::vector;

#include "adts/dictionary.h"
#include "adts/edge.h"
#include "adts/graph.h"

/**
 * Returns whether vertex dest is reachable from vertex src in the graph g
 *  using depth-first search.
 * @param src The source vertex.
 * @param dest The destination vertex.
 * @param g A pointer to the Graph object.
 * @return true if a path exists
 */
bool reachableDFS(string src, string dest, Graph *g);

/**
 * Returns the shortest length path found from the vertex src
 * to the vertex dest, using an unweighted breadth-first search of the graph.
 * @param src - source vertex
 * @param dest - destination vertex
 * @param g - pointer to Graph object
 * @return vector<string> - sequence of vertices in path from src to dest
 * @error throws runtime_error if no path exists
 */
vector<string> shortestLengthPathBFS(string src, string dest, Graph *g);

/**
 * dijkstra calculates the single source minimum distance to all other
 *   vertices in the graph from a src node
 * @param src - source vertex
 * @param g - pointer to Graph object to search
 * @return Dictionary<string,int> - Dictionary of vertices and their distance
 *    from src
 */
Dictionary<string, int> *singleSourceShortestPath(string src, Graph *g);

/**
 * Loads a graph from a file
 * @param graphFile  The name of the file containing the graph
 * @return a pointer to a Graph object.
 * Note: this function creates a new Graph object on the heap.
 *  It is the caller's responsibility to delete this graph
 */
Graph* loadGraphFromFile(string graphFile);
