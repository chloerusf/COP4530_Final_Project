/*
Names: Aubrey Kopkau, Chloe Robinson, Laray Lopez, Mark Anjoul
Function: This program shows the implementation of Dijikstra's Algorithm demonstrated
in our PowerPoint
*/

#include "Graph.hpp"
#include <iostream>

int main(){
    Graph g;
    std::vector<std::string> path;

    std::vector<std::string> vertices1 = { "A", "B", "C", "D", "E" };
    std::vector<std::tuple<std::string, std::string, unsigned long>>
    edges1 = { 
      {"A", "D", 1}, 
      {"A", "B", 2}, 
      {"D", "E", 3},
      {"A", "C", 4}, 
      {"C", "D", 5}, 
      {"B", "D", 7},
      {"B", "E", 9},
    };

    // Add vertices
    for (const auto &v : vertices1) {
        g.addVertex(v);
    }

    // Add edges
    for (const auto &e : edges1) {
        g.addEdge(std::get<0>(e), std::get<1>(e), std::get<2>(e));
    }

    g.shortestPath("A", "E", path);
    std::cout << "Path: ";
    for (auto &p : path) std::cout << p << " ";
    std::cout << "\n";


    return 0;
}