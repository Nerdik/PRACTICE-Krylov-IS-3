//Point 1. Double link list class tamplate

#ifndef DOUBLE_LIST_H
#define DOUBLE_LIST_H

#include <stdexcept>
#include <cstddef>

template <class DataType>
class CustomList
{
private:
    struct ListElement
    {
        DataType value;
        ListElement* previous;
        ListElement* next;
        
        ListElement(const DataType& val, ListElement* prev = nullptr, ListElement* nxt = nullptr) 
            : value(val), previous(prev), next(nxt) {}
    };

    ListElement* first;
    ListElement* last;
    std::size_t element_count;

    void clearAllElements()
    {
        while (!isEmpty())
        {
            removeLastElement();
        }
    }

public:
    // Initialize
    CustomList() : first(nullptr), last(nullptr), element_count(0) {}
    
    // Copy
    CustomList(const CustomList& source) : first(nullptr), last(nullptr), element_count(0)
    {
        ListElement* current = source.first;
        while (current != nullptr)
        {
            appendElement(current->value);
            current = current->next;
        }
    }
    
    // Clear
    ~CustomList()
    {
        clearAllElements();
    }
    
    // Add data
    void appendElement(const DataType& item)
    {
        ListElement* new_element = new ListElement(item, last);
        
        if (isEmpty()) {
            first = last = new_element;
        } else {
            last->next = new_element;
            last = new_element;
        }
        element_count++;
    }
    
    // Delete
    void removeLastElement()
    {
        if (isEmpty())
        {
            throw std::logic_error("Cannot remove from empty container");
        }
        
        if (first == last)
        {
            delete last;
            first = last = nullptr;
        }
        else
        {
            ListElement* temp = last;
            last = last->previous;
            last->next = nullptr;
            delete temp;
        }
        element_count--;
    }
    
    // Get data
    DataType getLast() const
    {
        if (isEmpty())
        {
            throw std::logic_error("Container has no elements");
        }
        return last->value;
    }
    
    // State
    bool isEmpty() const
    {
        return element_count == 0;
    }
    
    std::size_t count() const
    {
        return element_count;
    }
    
};

#endif
