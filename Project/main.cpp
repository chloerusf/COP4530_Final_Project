/*
Names: Aubrey Kopkau, Chloe Robinson, Laray Lopez, Mark Anjoul
Function: This program shows the implementation of Dijikstra's Algorithm demonstrated
in our PowerPoint
*/

#include "Graph.hpp"
#include <iostream>



int demo(){
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

    for (const auto &v : vertices1){
      std::vector<std::string>path;
      g.shortestPath("A",v,path);

      std::cout<<"Shortest path A to "<< v <<": ";
      for(auto &p:path)std::cout<<p<<" ";
      std::cout <<std::endl;
    }


    return 0;
}

int test() {
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


int main(){
  std::cout<<"Testcases: \n";
  test();

  std::cout<<"\nDemo: \n";
  demo();

  return 0;
}