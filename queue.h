//Point 3. Queue class (header)


#include "container_interface.h"
#include "double_list.h"

class Char_queue : public Container_interface<char>
{
private:
    CustomList<char> storage;

public:
    bool empty() const override;
    size_t size() const;
    void push(const char& c) override;
    void pop() override;
    char front() const;
    char top() const override { return front(); }
};
