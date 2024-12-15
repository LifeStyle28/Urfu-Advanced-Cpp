#include "circular_queue.hpp"

CircularQueue::CircularQueue(size_t size) :
{
: buffer(size), capacity(size), front(0), rear(0), count(0) {}	
}

bool CircularQueue::Push(int value)
{
    if (Full()) {
            return false; 
        }
        buffer[rear] = value;
        rear = (rear + 1) % capacity; 
        ++count; 
        return true;
}

bool CircularQueue::Pop()
{
 if (Empty()) {
            return false; 
        }
        front = (front + 1) % capacity; 
        --count; 
        return true;
}

int CircularQueue::Front() const
{
    if (Empty()) {
            return -1; 
        }
        return buffer[front];
}

int CircularQueue::Back() const
{
    if (Empty()) {
            return -1; 
    }
        return buffer[(rear - 1 + capacity) % capacity];
}

bool CircularQueue::Empty() const
{
    return count == 0; 

}

bool CircularQueue::Full() const
{
    return count == capacity;
}
