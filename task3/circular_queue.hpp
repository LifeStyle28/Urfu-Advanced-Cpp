#pragma once

#include <cstddef>

class CircularQueue {
private:
    int* buffer;            // Dynamic array to store elements
    size_t capacity;        // Maximum size of the queue
    size_t front;          // Index of the front element
    size_t rear;           // Index of the rear element
    bool is_empty;         // Flag to track empty state

public:
    CircularQueue(size_t size);  // Constructor
    ~CircularQueue();            // Destructor
    
    // Core operations
    bool Push(int value);        // Add value to the end
    bool Pop();                  // Remove value from the front
    int Front() const;           // Get front value
    int Back() const;            // Get back value
    
    // State checks
    bool Empty() const;          // Check if empty
    bool Full() const;           // Check if full
};
