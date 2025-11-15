/*
Names:

*/
//testing testing 1 2 3 - laray
#include "Graph.hpp"
#include <queue>
#include <limits>
#include <algorithm>

using namespace std;

Graph::Graph(){}

//Destructor
Graph::~Graph(){
    for (auto &pair : vertices) {   
        delete pair.second;       
    }
}

void Graph::addVertex(std::string label){
    //Check if label used
    if(vertices.find(label) != vertices.end()) return;

    //Adds new vertex to the end of list
    vertices[label] = new Vertex(label);
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

//this function adds a bi-directional edge to two labels
void Graph::addEdge(std::string label1, std::string label2, unsigned long weight){
    //edge case that makes sure label 1 and label 2 don't loop back to itself
    if(label1 == label2) return;
    
    //Make sure the vertex actually exist
    unordered_map<string, Vertex*>::iterator iterator1 = vertices.find(label1);
    unordered_map<string, Vertex*>::iterator iterator2 = vertices.find(label2);
    //Or condition, if one vertice was not found then return
    if (iterator1 == vertices.end() || iterator2 == vertices.end()){
        return;
    }
    //point to the objects
    Vertex* vert1 = iterator1->second;
    Vertex* vert2 = iterator2->second;
    
    //edge case that checks the vertices for duplicate edges
    for(size_t i = 0; i < vert1->edges.size(); i++){
        if(vert1->edges[i].destLabel == label2){
            return;} //if edge already exists
    }
    //add an edge in both direction (so they both know each other)
    vert1->edges.push_back(Edge(label2, weight));
    vert2->edges.push_back(Edge(label1, weight));
}

void Graph::removeEdge(std::string label1, std::string label2){

}

unsigned long Graph:: shortestPath(std::string startLabel, std::string endLabel,
    std::vector<std::string> &path){
        
        // validation- determine if shortest path between start and end exist
        if(vertices.find(startLabel) == vertices.end() || vertices.find(endLabel) == vertices.end())
            return (unsigned long)(-1);

        path.clear();

        // initialization
        unordered_map<string, unsigned long> dist; // current shortest dist to each vertex
        unordered_map<string, string> prev; // previous vertex in shortest path
        unordered_map<string, bool > visited; //whether vertex has been processed

        // make distances infinity and visited false
        for (unordered_map<string, Vertex*>::iterator it = vertices.begin(); it != vertices.end(); ++it){
            dist[it-> first] = (unsigned long)(-1);
            visited[it->first] = false;
        }
        dist[startLabel] = 0; // start distance is 0

        // setting up priority queue 
        typedef pair<unsigned long, string> P;
        struct compare {
            bool operator()(const P &a, const P &b) { return a.first > b.first; }
        };
        priority_queue<P, vector<P>, compare > pq;
        pq.push(P(0,startLabel)); // start with source

        // dijkstra loop
        while (!pq.empty()) {
            P current = pq.top(); // vertex w/ smallest distance 
            pq.pop();
            string u = current.second;

            if (visited[u]) continue; // skip if already processed
            visited[u] = true; // mark as processed

            if (u == endLabel) break; // exit if dest reached

            // relaxation step
            vector<Edge> &edges = vertices[u]->edges; // neighbors of u
            for(size_t i = 0; i < edges.size(); ++i){
                Edge e = edges[i];
                string v = e.destLabel;
                unsigned long weight = e.weight;

                //relax the edge u -> v
                if (!visited[v] && 
                    dist[u] != (unsigned long)(-1) && 
                    dist[u] + weight < dist[v]) {
                        dist[v] = dist[u] + weight; // update shortest dist
                        prev[v] = u; // track path
                        pq.push(P(dist[v], v)); // add neighbor to queue
                }
            }
        }
        // reconstructing the shortest path 
        if (dist[endLabel]==(unsigned long)(-1)) return (unsigned long)(-1); // no path exists

        string at = endLabel;
        while (at != startLabel) { // backtrack from end to start
            path.push_back(at);
            at = prev[at];
        }
        path.push_back(startLabel);
        reverse(path.begin(), path.end()); // reverse to get start to end

        return dist[endLabel]; // return total shortest distance 
}


