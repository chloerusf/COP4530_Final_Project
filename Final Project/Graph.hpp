#ifndef GRAPH_H
#define GRAPH_H

#include "GraphBase.hpp"
#include <vector>
using namespace std;


class Graph: public GraphBase {
    private: 
        vector <vector<int>> adjList;
        bool isDirected;

        public:
        Graph(int vertices, bool directed = false);
        ~Graph();
        void addVertex(std::string label);
        void removeVertex(std::string label);
        void addEdge(std::string label1, std::string label2, unsigned long weight);
        void removeEdge(std::string label1, std::string label2);
        unsigned long shortestPath(std::string startLabel, std::string endLabel,
        std::vector<std::string> &path);
};

class Vertex{

};

class Edge{

};

#endif