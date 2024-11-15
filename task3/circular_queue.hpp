#pragma once

#include <cstddef>

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
    int* buffer; 

    size_t capacity; 

    size_t head; // указатели
    size_t tail; 

    size_t size; 
};