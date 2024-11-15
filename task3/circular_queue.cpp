#include "circular_queue.hpp"
#include <stdexcept>

CircularQueue::CircularQueue(size_t size) : capacity(size), head(0), tail(0), size(0) {
    buffer = new int[size];
}

bool CircularQueue::Push(int value) {
    if (Full()) {
        return false;
    }
    buffer[tail] = value;
    tail = (tail + 1) % capacity;
    size++;
    return true;
}

bool CircularQueue::Pop() {
    if (Empty()) {
        return false;
    }
    head = (head + 1) % capacity;
    size--;
    return true;
}

int CircularQueue::Front() const {
    if (Empty()) {
        return -1;
    }
    return buffer[head];
}

int CircularQueue::Back() const {
    if (Empty()) {
        return -1;
    }
    return buffer[(tail - 1 + capacity) % capacity];
}

bool CircularQueue::Empty() const {
    return size == 0;
}

bool CircularQueue::Full() const {
    return size == capacity;
}