#include "circular_queue.hpp"

CircularQueue::CircularQueue(size_t size) : maxSize(size), front(0), rear(0), count(0)
{
	queue.resize(maxSize);
}

bool CircularQueue::Push(int value)
{
	if (Full()) 
	{
        	return false;
        }
        queue[rear] = value;
        rear = (rear + 1) % maxSize;
        count++;
        return true;
}

bool CircularQueue::Pop()
{
	if (Empty()) 
	{
        	return false;
        }
        front = (front + 1) % maxSize; 
        count--;
        return true;
}

int CircularQueue::Front() const
{
	if (Empty()) 
	{
        	return -1;
        }
        return queue[front];
}

int CircularQueue::Back() const
{
	if (Empty()) 
	{
        	return -1; 
        }
        return queue[(rear - 1 + maxSize) % maxSize]; 
}

bool CircularQueue::Empty() const
{
	return count == 0; 
}

bool CircularQueue::Full() const
{
	return count == maxSize;
}
