#pragma once

#include <cstddef>
#include <vector>

class CircularQueue {
public:
    CircularQueue(size_t size); 
    bool Push(int value);
    bool Pop(); 
    int Front() const; 
    int Back() const;
    bool Empty() const; 
    bool Full() const; 

private:
    std::vector<int> buffer; 
    size_t head;   
    size_t tail;    
    size_t capacity; 
    size_t size;    
};
