#ifndef PRIORITYQUEUE_H
#define PRIORITYQUEUE_H

/*
Names: Aubrey Kopkau, Chloe Robinson, Laray Lopez, Mark Anjoul
Purpose: Header file for priorityQueue.cpp
*/

#include <vector>
#include <string>

class PriorityQueue {
private:
    // Each element is (distance, label)
    std::vector<std::pair<unsigned long, std::string>> heap;

    // Helper functions
    void bubbleUp(int index);
    void bubbleDown(int index);

public:
    PriorityQueue();

    void push(unsigned long dist, const std::string &label);
    std::pair<unsigned long, std::string> pop();
    bool isEmpty() const;
};

#endif
