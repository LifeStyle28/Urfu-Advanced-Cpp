#include "circular_queue.hpp"
#include <iostream>

CircularQueue::CircularQueue(size_t size) : buffer_capacity(size) 
{
	buffer.resize(buffer_capacity);
}

bool CircularQueue::Push(int value)
{
    if (Full())
    {
        return false;
    }else
    {
        rear = (front + buffer_size) % buffer_capacity;
        buffer[rear] = value; 
        buffer_size++;
        return true;
    }
    
}

bool CircularQueue::Pop()
{
    if (Empty())
    {
        return false;
    }else
    {   
        front = (front + 1) % buffer_capacity;
        buffer_size--;
        return true;
    }
    
}

int CircularQueue::Front() const
{   
    if (Empty()) 
    {
        return -1;
    }
    return buffer[front];
}

int CircularQueue::Back() const
{
    if (Empty()) 
    {
        return -1;
    }
    return buffer[rear];
}

bool CircularQueue::Empty() const
{
    return buffer_size == 0;
    
}

bool CircularQueue::Full() const
{
    return buffer_size == buffer_capacity;
}
