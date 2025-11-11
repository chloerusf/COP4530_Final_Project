#ifndef GRAPH_H
#define GRAPH_H

#include "GraphBase.hpp"
#include <string>
#include <vector>
#include <unordered_map>
using namespace std;

class Edge {
public:
    string destLabel; // label of the destination vertex
    unsigned long weight; // weight of the edge

    Edge(string dest, unsigned long w)
        : destLabel(dest), weight(w) {}
};

class Vertex {
public:
    string label; // vertex name
    vector<Edge> edges; // edges connected to this vertex

    Vertex(string l) : label(l) {}
};

class Graph: public GraphBase {
private: 
    unordered_map<string, Vertex*> vertices;

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