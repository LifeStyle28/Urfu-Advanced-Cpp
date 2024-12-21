#include "circular_queue.hpp"

CircularQueue::CircularQueue(size_t size)
{
	sz = size;
	front = -1;
	rear = -1;
}

bool CircularQueue::Push(int value)
{
	if (this->Full())
	{
		return false;
	}
	if (front == -1)
	{
		front = 0;
	}
	rear = (rear + 1) % sz;
	q.push_back(value);
	return true;
}

bool CircularQueue::Pop()
{
	if (this->Empty())
	{
		return false;
	}
	q.erase(q.begin() + front);
	if (front == rear)
	{
		front = -1;
		rear = -1;
	}
	else
	{
		front = (front + 1) % sz;
	}
	return true;
}

int CircularQueue::Front() const
{
	return q[front];
}

int CircularQueue::Back() const
{
	return q[rear];
}

bool CircularQueue::Empty() const
{
	if (front <= -1 || rear <= -1)
	{
		return true;
	}
	else
	{
		return false;
	}
}

bool CircularQueue::Full() const
{
	if ((front == 0 && rear == sz - 1) || (front == (rear + 1) % sz))
	{
		return true;
	}
	else
	{
		return false;
	}
}
