//Point 3. Queue class (header)

#ifndef QUEUE_H
#define QUEUE_H

#include "container_interface.h"
#include "double_list.h"

class CharQueue : public QueueInterface<char>
{
private:
    CustomList<char> storage;

public:
    bool empty() const override;
    size_t size() const;
    void push(const char& c) override;
    void pop() override;
    char front() const override;
    char back() const override;
};

#endif