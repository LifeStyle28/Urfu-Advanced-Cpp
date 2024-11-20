#pragma once

#include <cstddef>

class CircularQueue {
private:
	int* queue;
	size_t maxSize;
	size_t front;
	size_t rear;
	size_t count;

public:
    CircularQueue(size_t size); // создать очередь с определенным размером буффера
    bool Push(int value); // добавить значение в конец очереди (false, если очередь заполнена)
    bool Pop(); // удалить значение из начала очереди (false, если очередь пустая)
    int Front() const; // получить значение из начала очереди (-1, если очередь пустая)
    int Back() const; // получить значение из конца очереди (-1, если очередь пустая)
    bool Empty() const; // проверить пустая ли очередь
    bool Full() const; // проверить заполнена ли очередь
};
