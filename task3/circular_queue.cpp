#include "circular_queue.hpp"

CircularQueue::CircularQueue(size_t size) : 
    capacity(size),
    front(0),
    rear(0),
    is_empty(true)
{
    buffer = new int[size];
}

CircularQueue::~CircularQueue() {
    delete[] buffer;
}

bool CircularQueue::Push(int value) {
    if (Full()) {
        return false;
    }
    
    buffer[rear] = value;
    rear = (rear + 1) % capacity;
    is_empty = false;
    
    return true;
}

bool CircularQueue::Pop() {
    if (Empty()) {
        return false;
    }
    
    front = (front + 1) % capacity;
    is_empty = (front == rear);
    
    return true;
}

int CircularQueue::Front() const {
    if (Empty()) {
        return -1;
    }
    return buffer[front];
}

int CircularQueue::Back() const {
    if (Empty()) {
        return -1;
    }
    return buffer[(rear == 0 ? capacity : rear) - 1];
}

bool CircularQueue::Empty() const {
    return is_empty;
}

bool CircularQueue::Full() const {
    return !is_empty && (front == rear);
}
