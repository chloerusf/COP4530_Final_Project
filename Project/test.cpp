/*
Names: Aubrey Kopkau, Chloe Robinson, Laray Lopez, Mark Anjoul
Purpose: Testing code with provided example
*/

#include "Graph.hpp"
#include <iostream>
#include <vector>
#include <tuple>

int main() {
    Graph g;

    std::vector<std::string> vertices1 = { "1", "2", "3", "4", "5", "6" };
    std::vector<std::tuple<std::string, std::string, unsigned long>> edges1 = {
        {"1", "2", 7}, {"1", "3", 9}, {"1", "6", 14},
        {"2", "3", 10}, {"2", "4", 15},
        {"3", "4", 11}, {"3", "6", 2},
        {"4", "5", 6},
        {"5", "6", 9}
    };

    // Add vertices
    for (const auto &v : vertices1) {
        g.addVertex(v);
    }

    // Add edges
    for (const auto &e : edges1) {
        g.addEdge(std::get<0>(e), std::get<1>(e), std::get<2>(e));
    }

    // Compute shortest path
    std::vector<std::string> path;
    unsigned long dist = g.shortestPath("1", "5", path);

    std::cout << "Shortest distance from 1 to 5: " << dist << "\n";
    std::cout << "Path: ";
    for (auto &p : path) std::cout << p << " ";
    std::cout << "\n";

    return 0;
}
