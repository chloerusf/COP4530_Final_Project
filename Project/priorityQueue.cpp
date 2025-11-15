#include "PriorityQueue.hpp"
#include <algorithm>

PriorityQueue::PriorityQueue() {}

// Insert a new value into the min heap
void PriorityQueue::push(unsigned long dist, const std::string &label) {
    heap.push_back({dist, label});
    bubbleUp(heap.size() - 1);
}

// Remove and return the smallest element
std::pair<unsigned long, std::string> PriorityQueue::pop() {
    if (isEmpty())
        return { (unsigned long)(-1), "" };

    std::pair<unsigned long, std::string> result = heap[0];

    heap[0] = heap.back();
    heap.pop_back();

    bubbleDown(0);

    return result;
}

// Check if heap is empty
bool PriorityQueue::isEmpty() const {
    return heap.empty();
}

// Restore heap property after push
void PriorityQueue::bubbleUp(int index) {
    while (index > 0) {
        int parent = (index - 1) / 2;
        if (heap[index].first < heap[parent].first) {
            std::swap(heap[index], heap[parent]);
            index = parent;
        } else {
            break;
        }
    }
}

// Restore heap property after pop
void PriorityQueue::bubbleDown(int index) {
    int size = heap.size();

    while (true) {
        int left = 2 * index + 1;
        int right = 2 * index + 2;
        int smallest = index;

        if (left < size && heap[left].first < heap[smallest].first)
            smallest = left;

        if (right < size && heap[right].first < heap[smallest].first)
            smallest = right;

        if (smallest != index) {
            std::swap(heap[index], heap[smallest]);
            index = smallest;
        } else {
            break;
        }
    }
}