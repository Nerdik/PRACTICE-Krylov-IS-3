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
    
    ~CustomList()
    {
        clear();
    }
    
    // Add back
    void pushBack(const DataType& value)
    {
        ListNode* newNode = new ListNode(value, tail);
        
        if (empty()) {
            head = tail = newNode;
        } else {
            tail->next = newNode;
            tail = newNode;
        }
        count++;
    }
    
    // Delete front element
    void removeFront()
    {
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
    
    // Get first element
    DataType front() const
    {
        if (empty())
        {
            throw std::logic_error("List is empty");
        }
        return head->data;
    }
    
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
