/*
Names:

*/

#include "Graph.hpp"

using namespace std;

Graph::Graph(){}
Graph::~Graph(){}

void Graph::addVertex(std::string label){
    //Check if label used
    if(vertices.find(label) != vertices.end()) return;

    //Adds new vertex to the end of list
    vertices[label] == new Vertex(label);
}

void Graph::removeVertex(std::string label){

    //Find label to remove, return if not found
    unordered_map<string, Vertex*>::iterator it = vertices.find(label);
    if (it == vertices.end()) return;

    for(unordered_map<string, Vertex*>::iterator p = vertices.begin(); p != vertices.end(); p++){
        vector<Edge> &edges = p->second->edges;

        for(int i = 0; i < edges.size();i++){
            edges.erase(edges.begin()+i);
            i--;
        }
    }

    delete it->second;
    vertices.erase(it);
}

void Graph::addEdge(std::string label1, std::string label2, unsigned long weight){

}

void Graph::removeEdge(std::string label1, std::string label2){

}

unsigned long Graph:: shortestPath(std::string startLabel, std::string endLabel,
    std::vector<std::string> &path){
        
        //Determine if shorted path between start and end exist
        if(!find(startLabel)||!find(endLabel))
            return (unsigned long)(-1);

}