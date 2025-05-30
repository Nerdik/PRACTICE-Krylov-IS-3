//Point 3. Queue class (realisation)

#include "queue.h"

bool CharQueue::empty() const
{
    return storage.isEmpty();
}

size_t CharQueue::size() const
{
    return storage.count();
}

void CharQueue::push(const char& c)
{
    storage.appendElement(c);
}

void CharQueue::pop()
{
    storage.removeLastElement();
}

char CharQueue::front() const
{
    return storage.getLast();
}