/*
  Copyright (c) 2020
  Swarthmore College Computer Science Department, Swarthmore PA
  J. Brody, A. Danner, M. Gagne, L. Meeden, Z. Palmer, A. Soni, M. Wehar
  Distributed as course material for Spring 2020
  CPSC 035: Data Structures and Algorithms
  https://tinyurl.com/vdxo2w8
*/


#include <algorithm>
#include <fstream>
#include <string>
#include <vector>
#include <UnitTest++/UnitTest++.h>

#include "directedGraph.h"
#include "undirectedGraph.h"
#include "graphAlgorithms.h"
#include "adts/dictionary.h"
#include "adts/graph.h"

using namespace std;

/* helper check function that verifies there are no
   duplicate values in a vector */
template <typename T>
void noDupesCheck(vector<T> expr);

/* helper check function that verifies that
   two vectors are set equivalent. An item
   is in the first vector iff it is in the
   second vector.  */
template <typename T>
void vectorsEqualCheck(vector<T> first, vector<T> second);

/* helper function to check if two paths are equivalent */
void checkEqualPath(vector<string> expected, vector<string> actual);

template <class G = UndirectedGraph>
Graph *makeGraph(int size, vector<Edge> edges) {
  vector<string> vertices;
  for(int i=0; i<size; i++) {
    vertices.push_back(to_string(i));
  }
  Graph *graph = new G(vertices, edges);

  return graph;
}

TEST(getEdges) {
  // Creates an undirected graph with 4 edges:
  // 0 {no edges to 0}
  // 1  ---       1     --- 2  ---  1  --- 4
  //    \                  /
  //     \                /
  //      1             1
  //        \          /
  //         \        /
  //            3
  // and queries getEdges to ensure duplicates are correctly removed
  Graph* graph = makeGraph(5,
      {
        {"1","2",1}, {"1","3",1}, {"2","3",1}, {"2","4",1}
      });
  vector<Edge> edges = graph->getEdges();
  CHECK_EQUAL(4,edges.size());
  delete graph;
}

TEST(dfsTwoVertexGraph) {
  // This creates the *undirected* graph:
  //    0  --- 1 ---  1
  Graph *graph = makeGraph(2, {{"0", "1", 1}});
  CHECK(reachableDFS("0", "1", graph));
  CHECK(reachableDFS("1", "0", graph));
  delete graph;
}

TEST(dfsTwoDisconnectedVertices) {
  // This creates the *undirected* graph:
  //    0                 1
  Graph *graph = makeGraph(2, {});
  CHECK(!reachableDFS("0", "1", graph));
  CHECK(!reachableDFS("1", "0", graph));
  delete graph;
}

TEST(dfsThreeVertexDirectedGraph) {
  // This call makes a *directed* graph!
  Graph *graph = makeGraph<DirectedGraph>(3,
          {
              {"0", "1", 1}, {"0", "2", 1},
          });
  CHECK(reachableDFS("0", "0", graph));
  CHECK(reachableDFS("0", "1", graph));
  CHECK(reachableDFS("0", "2", graph));
  CHECK(!reachableDFS("2", "0", graph));
  CHECK(!reachableDFS("1", "0", graph));
  CHECK(!reachableDFS("1", "2", graph));
  delete graph;
}


TEST(bfsThreeVertexClique) {
  // This call makes an undirected graph.
  Graph *graph = makeGraph(3,
      {
          {"0", "1", 1}, {"0", "2", 1}, {"1", "2", 1},
      });
  vector<string> path = {"0", "2"};
  checkEqualPath(path, shortestLengthPathBFS("0", "2", graph));
  path = {"0", "1"};
  checkEqualPath(path, shortestLengthPathBFS("0", "1", graph));
  delete graph;
}

TEST(bfsFiveVertex) {
  // This call makes an undirected graph.
  Graph *graph = makeGraph(5, {{"0", "1", 1},
                                             {"1", "2", 1},
                                             {"2", "3", 1},
                                             {"0", "4", 1},
                                             {"4", "3", 1}});
  vector<string> path = {"0","4","3"};
  checkEqualPath(path, shortestLengthPathBFS("0", "3", graph));
  delete graph;
}

TEST(bfsFiveVertexDirected) {
  // This call makes a directed graph.
  Graph *graph =
      makeGraph<DirectedGraph>(5, {{"0", "1", 1},
                                                 {"1", "2", 1},
                                                 {"2", "3", 1},
                                                 {"3", "4", 1},
                                                 {"4", "0", 1}});
  vector<string> path = {"0","1","2","3"};
  checkEqualPath(path, shortestLengthPathBFS("0", "3", graph));
  delete graph;
}



TEST(ssspFiveVertex) {
  // This call makes an undirected graph.
  Graph *graph = makeGraph(5, {{"0", "1", 3},
                                             {"1", "2", 4},
                                             {"2", "3", 2},
                                             {"0", "4", 5},
                                             {"4", "3", 6}});
  Dictionary<string,int> *results =
      singleSourceShortestPath("0", graph);
  CHECK_EQUAL(9, results->get("3"));
  CHECK_EQUAL(7, results->get("2"));
  CHECK_EQUAL(5, results->get("4"));
  delete results;
  delete graph;
}

TEST(ssspFiveVertexDirected) {
  // This call makes a directed graph.
  Graph *graph =
      makeGraph<DirectedGraph>(5, {{"3", "2", 3},
                                                 {"2", "1", 4},
                                                 {"1", "0", 2},
                                                 {"0", "4", 5},
                                                 {"4", "3", 6}});
  Dictionary<string, int> *results =
      singleSourceShortestPath("0", graph);
  CHECK_EQUAL(11, results->get("3"));
  CHECK_EQUAL(14, results->get("2"));
  CHECK_EQUAL(5, results->get("4"));
  delete results;
  delete graph;
}


int main() { return UnitTest::RunAllTests(); }

void checkEqualPath(vector<string> expected, vector<string> actual) {
  CHECK_EQUAL(expected.size(), actual.size());
  for(int i=0; i<expected.size(); i++) {
    CHECK_EQUAL(expected.at(i), actual.at(i));
  }

}

template <typename T>
void noDupesCheck(vector<T> expr){
    auto vec = expr;
    auto it = vec.begin();
    while (it < vec.end()) {
      if (find(it + 1, vec.end(), *it) != vec.end()) {
        CHECK_EQUAL(to_string(*it) + " to be unique in vector",
                    to_string(*it) + " in vector twice");
      }
      it++;
    }
}

template <typename T>
void vectorsEqualCheck(vector<T> first, vector<T> second){
    auto expected = first;
    auto actual = second;
    noDupesCheck(actual);
    CHECK_EQUAL(expected.size(), actual.size());
    for (int i = 0; i < expected.size(); i++) {
      if (find(actual.begin(), actual.end(), expected[i]) ==
          actual.end()) {
        CHECK_EQUAL(to_string(expected[i]) + " to be in vector", "no such result");
      }
    }
    for (int i = 0; i < actual.size(); i++) {
      if (find(expected.begin(), expected.end(), actual[i]) ==
          expected.end()) {
        CHECK_EQUAL(to_string(actual[i]) + " not to be in vector",
                    to_string(actual[i]) + " in vector");
      }
    }
  }
