/*
Names: Aubrey Kopkau, Chloe Robinson, Laray Lopez, Mark Anjoul
Purpose: Implements an adjacency list to do Dijkstra's Algorithm
*/

#include "Graph.hpp"
#include "PriorityQueue.hpp"
#include <limits>
#include <algorithm>

using namespace std;

Graph::Graph() {}

// Destructor
Graph::~Graph()
{
    for (auto &pair : vertices)
    {
        delete pair.second;
    }
}

void Graph::addVertex(std::string label)
{
    // Check if label used
    if (vertices.find(label) != vertices.end())
        return;

    // Adds new vertex to the end of list
    vertices[label] = new Vertex(label);
}

void Graph::removeVertex(std::string label)
{

    // Find label to remove, return if not found
    unordered_map<string, Vertex *>::iterator it = vertices.find(label);
    if (it == vertices.end())
        return;

    // Loop through all vertices and remove edges pointing to the one being deleted.
    for (unordered_map<string, Vertex *>::iterator p = vertices.begin(); p != vertices.end(); p++)
    {
        vector<Edge> &edges = p->second->edges;

        // Remove edges that point to the vertex being deleted.
        for (size_t i = 0; i < edges.size(); i++)
        {

            // Only erase edges that point to the vertex being removed
            if (edges[i].destLabel == label)
            {
                edges.erase(edges.begin() + i);
                i--;
            }
        }
    }
    delete it->second;
    vertices.erase(it);
}

// This function adds a bi-directional edge to two labels
void Graph::addEdge(std::string label1, std::string label2, unsigned long weight)
{
    // Edge case that makes sure label 1 and label 2 don't loop back to itself
    if (label1 == label2)
        return;

    // Make sure the vertex actually exist
    unordered_map<string, Vertex *>::iterator iterator1 = vertices.find(label1);
    unordered_map<string, Vertex *>::iterator iterator2 = vertices.find(label2);
    // Or condition, if one vertice was not found then return
    if (iterator1 == vertices.end() || iterator2 == vertices.end())
    {
        return;
    }
    // Point to the objects
    Vertex *vert1 = iterator1->second;
    Vertex *vert2 = iterator2->second;

    // Edge case that checks the vertices for duplicate edges
    for (size_t i = 0; i < vert1->edges.size(); i++)
    {
        if (vert1->edges[i].destLabel == label2)
        {
            return;
        } // If edge already exists
    }
    // Add an edge in both direction (so they both know each other)
    vert1->edges.push_back(Edge(label2, weight));
    vert2->edges.push_back(Edge(label1, weight));
}

void Graph::removeEdge(std::string label1, std::string label2)
{
    // Assignment
    unordered_map<string, Vertex *>::iterator iterator1 = vertices.find(label1);
    unordered_map<string, Vertex *>::iterator iterator2 = vertices.find(label2);
    // If one condition not true return
    if (iterator2 == vertices.end() || iterator1 == vertices.end())
        return;

    // Point to object
    Vertex *vert1 = iterator1->second;
    Vertex *vert2 = iterator2->second;

    // Remove connection from vertex 1
    for (size_t i = 0; i < vert1->edges.size();)
    {
        // If edge points to label 2 remove it
        if (vert1->edges[i].destLabel == label2)
        {
            vert1->edges.erase(vert1->edges.begin() + i);
        }
        else
        {
            i++; // Else continue through
        }
    }
    // Remove connection from vertex 2
    for (size_t i = 0; i < vert2->edges.size();)
    {
        // If edge points to label 1 remove it
        if (vert2->edges[i].destLabel == label1)
        {
            vert2->edges.erase(vert2->edges.begin() + i);
        }
        else
        {
            i++; // Else continue through
        }
    }
}

unsigned long Graph::shortestPath(std::string startLabel, std::string endLabel,
                                  std::vector<std::string> &path)
{

    // Validation- determine if shortest path between start and end exist
    if (vertices.find(startLabel) == vertices.end() || vertices.find(endLabel) == vertices.end())
        return (unsigned long)(-1);

    path.clear();

    // Initialization
    unordered_map<string, unsigned long> dist; // Current shortest dist to each vertex
    unordered_map<string, string> prev;        // Previous vertex in shortest path
    unordered_map<string, bool> visited;       // Whether vertex has been processed

    // Make distances infinity and visited false
    for (unordered_map<string, Vertex *>::iterator it = vertices.begin(); it != vertices.end(); ++it)
    {
        dist[it->first] = (unsigned long)(-1);
        visited[it->first] = false;
    }
    dist[startLabel] = 0; // start distance is 0

    // Setting up priority queue
    PriorityQueue pq;
    pq.push(0, startLabel);

    // Dijkstra loop
    while (!pq.isEmpty())
    {
        std::pair<unsigned long, std::string> current = pq.pop(); // Vertex with smallest distance
        std::string u = current.second;

        // If we've already processed this vertex, skip it
        if (visited[u])
            continue;
        visited[u] = true; // Mark as processed

        // Early exit if destination is reached
        if (u == endLabel)
            break;

        // Relaxation step
        vector<Edge> &edges = vertices[u]->edges; // Neighbors of u
        for (size_t i = 0; i < edges.size(); ++i)
        {
            Edge e = edges[i];
            string v = e.destLabel;
            unsigned long weight = e.weight;

            // Relax the edge u -> v
            if (!visited[v] &&
                dist[u] != (unsigned long)(-1) &&
                dist[u] + weight < dist[v])
            {
                dist[v] = dist[u] + weight; // Update shortest dist
                prev[v] = u;                // Track path
                pq.push(dist[v], v);        // Add neighbor to queue
            }
        }
    }
    // Reconstructing the shortest path
    if (dist[endLabel] == (unsigned long)(-1))
        return (unsigned long)(-1); // No path exists

    string at = endLabel;
    while (at != startLabel)
    { // Backtrack from end to start
        path.push_back(at);
        at = prev[at];
    }
    path.push_back(startLabel);
    reverse(path.begin(), path.end()); // Reverse to get start to end

    return dist[endLabel]; // Return total shortest distance
}
