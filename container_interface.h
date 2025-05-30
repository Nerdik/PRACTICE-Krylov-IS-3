//Point 2. Container interface abstract tamplate class (Queue)


template <typename T>
class Container_interface
{
public:
    virtual void push(const T& value) = 0;
    virtual void pop() = 0;
    virtual T top() const = 0;
    virtual bool empty() const = 0;
};
