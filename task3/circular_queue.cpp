#include "circular_queue.hpp"
#include <vector>
CircularQueue::CircularQueue(size_t size)
{
CircularQueue::CircularQueue(size_t size) : capacity(size), size(0), front(0), rear(0) {
    buffer.resize(size);  // Pre-allocate exact size
}
bool CircularQueue::Push(int value)
{
bool CircularQueue::Push(int value) {
    if (Full()) {
        return false;
    }
    buffer[rear] = value;
    rear = (rear + 1) % capacity;
    size++;
    return true;
}
bool CircularQueue::Pop()
{
bool CircularQueue::Pop() {
    if (Empty()) {
        return false;
    }
    front = (front + 1) % capacity;
    size--;
    return true;
}
int CircularQueue::Front() const
{
int CircularQueue::Front() const {
    if (Empty()) {
        return -1;
    }
    return buffer[front];
}
int CircularQueue::Back() const
{
int CircularQueue::Back() const {
    if (Empty()) {
        return -1;
    }
    return buffer[(rear - 1 + capacity) % capacity];
}
bool CircularQueue::Empty() const
{
bool CircularQueue::Empty() const {
    return size == 0;
}
bool CircularQueue::Full() const
{
bool CircularQueue::Full() const {
    return size == capacity;
}
