#ifndef DOUBLE_LIST_H
#define DOUBLE_LIST_H

#include <stdexcept>
#include <cstddef>

template <class DataType>
class CustomList
{
private:
    struct ListNode
    {
        DataType data;
        ListNode* prev;
        ListNode* next;
        
        ListNode(const DataType& val, ListNode* p = nullptr, ListNode* n = nullptr) 
            : data(val), prev(p), next(n) {}
    };

    ListNode* head;
    ListNode* tail;
    size_t count;

    void clear() {
        while (!empty()) {
            removeFront();
        }
    }

public:
    CustomList() : head(nullptr), tail(nullptr), count(0) {}
    
    ~CustomList() {
        clear();
    }
    
    // Добавление в конец (для очереди)
    void pushBack(const DataType& value) {
        ListNode* newNode = new ListNode(value, tail);
        
        if (empty()) {
            head = tail = newNode;
        } else {
            tail->next = newNode;
            tail = newNode;
        }
        count++;
    }
    
    // Удаление из начала (для очереди)
    void removeFront() {
        if (empty()) {
            throw std::logic_error("List is empty");
        }
        
        if (head == tail) {
            delete head;
            head = tail = nullptr;
        } else {
            ListNode* temp = head;
            head = head->next;
            head->prev = nullptr;
            delete temp;
        }
        count--;
    }
    
    // Получение первого элемента
    DataType front() const {
        if (empty()) {
            throw std::logic_error("List is empty");
        }
        return head->data;
    }
    
    bool empty() const {
        return count == 0;
    }
    
    size_t size() const {
        return count;
    }
    
    // Запрещаем копирование и присваивание
    CustomList(const CustomList&) = delete;
    CustomList& operator=(const CustomList&) = delete;
};

#endif
