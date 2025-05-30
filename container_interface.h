//Point 2. Container interface abstract tamplate class (Queue)

#ifndef CONTAINER_INTERFACE_H
#define CONTAINER_INTERFACE_H

template <typename T>
class ContainerInterface
{
public:
    virtual ~ContainerInterface() = default;
    virtual void push(const T& value) = 0;
    virtual void pop() = 0;
    virtual T top() const = 0;
    virtual bool empty() const = 0;
};

#endif
