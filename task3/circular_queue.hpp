#pragma once
#include <cstddef>
#include <vector>
class CircularQueue {
private:
    std::vector<int> buffer;        
    size_t capacity;  
    size_t size;           
    size_t front;       
    size_t rear;     
public:
    CircularQueue(size_t size); // создать очередь с определенным размером буффера
    bool Push(int value); // добавить значение в конец очереди (false, если очередь заполнена)
    bool Pop(); // удалить значение из начала очереди (false, если очередь пустая)
    int Front() const; // получить значение из начала очереди (-1, если очередь пустая)
    int Back() const; // получить значение из конца очереди (-1, если очередь пустая)
    bool Empty() const; // проверить пустая ли очередь
    bool Full() const; // проверить заполнена ли очередь
    CircularQueue(size_t size);
    bool Push(int value);       
    bool Pop();        
    int Front() const;           
    int Back() const;         
    bool Empty() const;       
    bool Full() const;          
};
