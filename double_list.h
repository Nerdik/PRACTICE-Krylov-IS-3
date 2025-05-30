#ifndef DOUBLE_LIST_H
#define DOUBLE_LIST_H

#include <stdexcept>

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

    void clear()
    {
        while (!empty())
        {
            removeFront();
        }
    }

public:
    CustomList() : head(nullptr), tail(nullptr), count(0) {}
    
    // 1. Деструктор
    ~CustomList()
    {
        clear();
    }

    // 2. Конструктор копирования
    CustomList(const CustomList& other) 
    : head(nullptr), tail(nullptr), count(0) 
    {
        ListNode* current = other.head;
        while (current) {
            pushBack(current->data);
            current = current->next;
        }
    }

    // 3. Оператор присваивания копированием
    CustomList& operator=(const CustomList& other)
    {
        if (this != &other)
        { 
            clear();
            
            ListNode* current = other.head;
            while (current)
            {
                pushBack(current->data);
                current = current->next;
            }
        }
        return *this;
    }
        
    // Add front
    void pushFront(const DataType& value)
    {
        ListNode* newNode = new ListNode(value, nullptr, head);
        
        if (empty())
        {
            head = tail = newNode;
        }
        else
        {
            head->prev = newNode;
            head = newNode;
        }
        count++;
    }

    // Add back
    void pushBack(const DataType& value)
    {
        ListNode* newNode = new ListNode(value, tail);
        
        if (empty())
        {
            head = tail = newNode;
        }
        else
        {
            tail->next = newNode;
            tail = newNode;
        }
        count++;
    }
    
    // Delete front element
    void removeFront()
    {
        if (empty())
        {
            throw std::logic_error("List is empty");
        }
        
        if (head == tail)
        {
            delete head;
            head = tail = nullptr;
        }
        else
        {
            ListNode* temp = head;
            head = head->next;
            head->prev = nullptr;
            delete temp;
        }
        count--;
    }

    // Delete back element
    void removeBack()
    {
        if (empty())
        {
            throw std::logic_error("List is empty");
        }
        
        if (head == tail)
        {
            delete tail;
            head = tail = nullptr;
        }
        else
        {
            ListNode* temp = tail;
            tail = tail->prev;
            tail->next = nullptr;
            delete temp;
        }
        count--;
    }
    
    // Get front element
    DataType front() const
    {
        if (empty())
        {
            throw std::logic_error("List is empty");
        }
        return head->data;
    }

    // Get back element
    DataType back() const
    {
        if (empty())
        {
            throw std::logic_error("List is empty");
        }
        return tail->data;
    }
    
    // State
    bool empty() const
    {
        return count == 0;
    }
    
    size_t size() const 
    {
        return count;
    }
};

#endif
