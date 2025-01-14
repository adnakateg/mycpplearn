#pragma once

#include <gtest/gtest.h>
#include <iostream>
#include <string>
#include <unordered_map>
#include <unordered_set>

using std::cout;
using std::string;
using std::unordered_map;
using std::unordered_set;

class Graph {
public:
  bool addVertex(const string &vertex) {
    if (m_adjList.count(vertex) == 0) {
      m_adjList.insert({vertex, {}});
      return true;
    }
    return false;
  }

  bool addEdge(const string &vertex1, const string &vertex2) {
    if (m_adjList.count(vertex1) && m_adjList.count(vertex2)) {
      m_adjList.at(vertex1).insert(vertex2);
      m_adjList.at(vertex2).insert(vertex1);

      return true;
    }
    return false;
  }

  bool removeEdge(const string &vertex1, const string &vertex2) {
    if (m_adjList.count(vertex1) && m_adjList.count(vertex1)) {
      m_adjList.at(vertex1).erase(vertex2);
      m_adjList.at(vertex2).erase(vertex1);
      return true;
    }
    return false;
  }

  bool removeVertex(const string &vertex) {
    if (m_adjList.count(vertex)) {
      for (auto &other : m_adjList.at(vertex)) {
        m_adjList[other].erase(vertex);
      }
      m_adjList.erase(vertex);
      return true;
    }
    return false;
  }

  void printGraph() {
    cout << __PRETTY_FUNCTION__ << "\n";
    for (const auto &ver : m_adjList) {
      cout << "[" << ver.first << "] : ";
      for (const auto &edg : ver.second) {
        cout << edg << " ";
      }
      cout << "\n";
    }
    cout << "\n\n";
  }

private:
  unordered_map<string, unordered_set<string>> m_adjList{};
};

TEST(graph_test, test01) {
  Graph _graph{};
  EXPECT_TRUE(_graph.addVertex("A"));
  EXPECT_FALSE(_graph.addVertex("A"));

  EXPECT_FALSE(_graph.addEdge("A", "B"));

  EXPECT_TRUE(_graph.addVertex("B"));

  EXPECT_TRUE(_graph.addEdge("A", "B"));

  EXPECT_TRUE(_graph.addVertex("C"));
  EXPECT_TRUE(_graph.addEdge("A", "C"));
  EXPECT_TRUE(_graph.addEdge("B", "C"));

  EXPECT_TRUE(_graph.removeEdge("A", "B"));
  EXPECT_FALSE(_graph.removeEdge("D", "B"));
}

TEST(graph_test, test02) {
  Graph _graph{};
  EXPECT_TRUE(_graph.addVertex("A"));
  EXPECT_TRUE(_graph.addVertex("B"));
  EXPECT_TRUE(_graph.addVertex("C"));
  EXPECT_TRUE(_graph.addVertex("D"));

  EXPECT_TRUE(_graph.addEdge("A", "B"));
  EXPECT_TRUE(_graph.addEdge("A", "C"));
  EXPECT_TRUE(_graph.addEdge("A", "D"));
  EXPECT_TRUE(_graph.addEdge("B", "D"));
  EXPECT_TRUE(_graph.addEdge("C", "D"));

  _graph.printGraph();
  EXPECT_TRUE(_graph.removeVertex("D"));
  _graph.printGraph();
}
