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
#include <vector>
#include "edge.h"

using std::string;
using std::vector;

/**
 * Graph is a class representing directed, weighted graphs.
 */
class Graph {
public:
    virtual ~Graph() {}

    /**
     * Adds a directed edge to this graph.
     * @param source The source vertex for the edge.
     * @param destination The destination vertex for the edge.
     * @param weight The weight of the edge to add.
     * @throws runtime_error If an edge already exists between the given source
     *                       and target.
     */
    virtual void insertEdge(string src, string dest, int weight) = 0;

    /**
     * Removes an edge from this graph.
     * @param source The source vertex for the edge.
     * @param destination The destination vertex for the edge.
     * @throws runtime_error If the edge does not exist.
     */
    virtual void removeEdge(string src, string dest) = 0;

    /**
     * Determines if this graph contains an edge.
     * @param source The source vertex for the edge.
     * @param destination The destination vertex for the edge.
     * @return true if the graph contains that edge; false if it does not.
     */
    virtual bool containsEdge(string source, string destination) = 0;

    /**
     * Retrieves an edge from this graph.
     * @param source The source vertex for the edge.
     * @param destination The destination vertex for the edge.
     * @return The edge.
     * @throws runtime_error If the edge does not exist.
     */
    virtual Edge getEdge(string source, string destination) = 0;

    /**
     * Retrieves all vertices from this graph.
     * @return a vector containing each vertex.
     */
    virtual vector<string> getVertices() = 0;
    
    /**
     * Retrieves all edges from this graph.
     * @return A vector containing every edge in this graph.
     */
    virtual vector<Edge> getEdges() = 0;

    /**
     * Retrieves all edges with a common source.
     * @param source The source vertex.
     * @return All edges in the graph which leave that source vertex.
     * @throws runtime_error if the source does not exist.
     */
    virtual vector<Edge> getOutgoingEdges(string source) = 0;

    /**
     * Retrieves all vertices which are reachable by an edge with the provided
     * source vertex.
     * @param source The source vertex.
     * @return All vertices in the graph which are a destination for an edge
     *         that has the given source.
     * @throws runtime_error if the source does not exist.
     */
    virtual vector<string> getNeighbors(string source) = 0;

    // You can safely ignore the following code.  This eliminates some default
    // class routines, preventing you from using them accidentally.
    // Specifically, we are disabling the use of the copy constructor and the
    // copy assignment operator.  You can read more here:
    //   http://www.cplusplus.com/articles/y8hv0pDG/
    //   https://tinyurl.com/yco62ouh
public:
    Graph() { }
private:
    Graph(const Graph& other) = delete;
    Graph& operator=(const Graph& other) = delete;
};
