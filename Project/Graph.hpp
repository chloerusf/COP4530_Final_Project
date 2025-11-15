/*
Names: Aubrey Kopkau, Chloe Robinson, Laray Lopez, Mark Anjoul
Purpose: Header file for Graph.cpp
*/

#ifndef GRAPH_H
#define GRAPH_H

#include "GraphBase.hpp"
#include <string>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <list>

class Edge {
public:
    std::string destLabel; // label of the destination vertex
    unsigned long weight; // weight of the edge

    Edge(std::string dest, unsigned long w)
        : destLabel(dest), weight(w) {}
};

class Vertex {
public:
    std::string label; // vertex name
    std::vector<Edge> edges; // edges connected to this vertex

    Vertex(std::string l) : label(l) {}
};

class Graph: public GraphBase {
private: 
    std::unordered_map<std::string, Vertex*> vertices;

    // Prevents accidental copying
    Graph(const Graph&) = delete;
    Graph& operator=(const Graph&) = delete;

public:
    Graph();
    ~Graph();

    void addVertex(std::string label);
    void removeVertex(std::string label);
    void addEdge(std::string label1, std::string label2, unsigned long weight);
    void removeEdge(std::string label1, std::string label2);
    unsigned long shortestPath(std::string startLabel, std::string endLabel,
    std::vector<std::string> &path);
};

#endif
