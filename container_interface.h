//Point 2. Container interface abstract tamplate class (Queue)

#ifndef CONTAINER_INTERFACE_H
#define CONTAINER_INTERFACE_H

#include <cstddef>

// Basic class
template <typename T>
class BasicContainerInterface {
public:
    virtual ~BasicContainerInterface() = default;
    virtual void push(const T& value) = 0;
    virtual void pop() = 0;
    virtual bool empty() const = 0;
    virtual size_t size() const = 0;
};

// Queue (FIFO)
template <typename T>
class QueueInterface : public BasicContainerInterface<T> {
public:
    virtual T front() const = 0;
    virtual T back() const = 0;
};

// Stack (LIFO)
template <typename T>
class StackInterface : public BasicContainerInterface<T> {
public:
    virtual T top() const = 0;
};

#endif
