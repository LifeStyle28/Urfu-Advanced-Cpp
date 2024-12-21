#pragma once

#include <cstddef>
#include <vector>

class CircularQueue {
public:
    CircularQueue(size_t size); // создать очередь с определенным размером буффера
    bool Push(int value); // добавить значение в конец очереди (false, если очередь заполнена)
    bool Pop(); // удалить значение из начала очереди (false, если очередь пустая)
    int Front() const; // получить значение из начала очереди (-1, если очередь пустая)
    int Back() const; // получить значение из конца очереди (-1, если очередь пустая)
    bool Empty() const; // проверить пустая ли очередь
    bool Full() const; // проверить заполнена ли очередь
private:
    size_t buffer_size = 0;
    size_t buffer_capacity;
    size_t front = 0;
    size_t rear = 0;
    std::vector<int> buffer; 
};
