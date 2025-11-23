# **COP4530 Final Project: Dijkstra’s Algorithm**

A C++ implementation of an undirected, weighted graph that uses Dijkstra’s Algorithm and a custom priority queue to compute the shortest path between two vertices.

---

## **Course Information**

- **Course:** COP4530 – Data Structures
- **Professor:** Dr. Valentina Korzhova
- **Semester:** Fall 2025
- **Project:** Programming Project 4

---

## **Overview**

This project implements an undirected, weighted Graph Abstract Data Type (ADT) and applies Dijkstra’s Algorithm to compute the shortest path between two vertices. The goal is to design a modular, object-oriented C++ solution that supports adding/removing vertices, adding/removing weighted edges, and generating the minimum-cost route between any two nodes in the graph.

Implementing Dijkstra’s Algorithm serves two purposes:
  1. Understanding priority-based shortest-path computation using custom data structures
  2. Reinforcing non-linear data structures such as graphs, adjacency representations, and manually implemented priority queues.

The problem this project solves is determining the most efficient (least-cost) path in an undirected weighted graph, returning both the total path cost and the ordered sequence of vertices that make up the optimal route.

---

## **Technologies Used**

* Programming Language: C++
* Tools / IDEs: VS Code
* Version Control: GitHub

---

## **Project Structure**

```
project/
├── Graph.cpp
├── Graph.hpp
├── GraphBase.hpp        
├── main.cpp
├── PriorityQueue.hpp  
├── PriorityQueue.cpp
└── README.md
```

---

## **How to Compile & Run**

### **Compile**

```bash
g++ -std=c++17 -Wall main.cpp Graph.cpp PriorityQueue.cpp -o program
```


### **Run**
#### **Mac/Linux**

```bash
./program
```

#### **Windows**

```bash
program.exe
```

---

## **Requirements Checklist**

Directly aligned with the rubric from the project document:

* [x] Implements undirected weighted Graph ADT
* [x] Supports add/remove vertex
* [x] Supports add/remove edge
* [x] Implements Dijkstra’s Algorithm
* [x] Uses custom priority queue

---

## Team Members 

* Aubrey Kopkau 
* Chloe Robinson
* Laray Lopez
* Mark Anjoul

---
