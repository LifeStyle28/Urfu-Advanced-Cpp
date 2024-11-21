#pragma once

#include <vector>
#include <cstddef>

class CircularQueue {
private:
    std::vector<int> data; // Elements
    size_t capacity;       // Maximum count of elements
    size_t front;          // Index of the front element
    size_t rear;           // Index of the rear element

public:
    CircularQueue(size_t size);  // Constructor

    bool Push(int value);        // Add value to the end
    bool Pop();                  // Remove value from the front
    int Front() const;           // Get front value
    int Back() const;            // Get back value
    
    bool Empty() const;          // Check if empty
    bool Full() const;           // Check if full
};
