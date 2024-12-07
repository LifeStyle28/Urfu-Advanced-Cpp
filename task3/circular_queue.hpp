#pragma once

#include <vector>

class CircularQueue {
private:
    std::vector<int> buffer;            // Dynamic array to store elements
    size_t capacity;        // Maximum size of the queue
    size_t size;           // Current count of elements
    size_t front;          // Index of the front element
    size_t rear;     
public:
    CircularQueue(size_t size); // создать очередь с определенным размером буффера
    bool Push(int value); // добавить значение в конец очереди (false, если очередь заполнена)
    bool Pop(); // удалить значение из начала очереди (false, если очередь пустая)
    int Front() const; // получить значение из начала очереди (-1, если очередь пустая)
    int Back() const; // получить значение из конца очереди (-1, если очередь пустая)
    bool Empty() const; // проверить пустая ли очередь
    bool Full() const; // проверить заполнена ли очередь
};
