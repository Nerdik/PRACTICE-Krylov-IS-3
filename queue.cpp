//Point 3. Queue class (realisation)

#include "queue.h"

bool CharQueue::empty() const
{
    return storage.empty();
}

size_t CharQueue::size() const
{
    return storage.size();
}

void CharQueue::push(const char& c)
{
    storage.pushBack(c);
}

void CharQueue::pop() {
    storage.removeFront();
}

char CharQueue::front() const
{
    return storage.front();
}

char CharQueue::back() const
{
    return storage.back();
}