//Point 3. Queue class (realisation)


bool Char_queue::empty() const
{
    return storage.isEmpty();
}

size_t Char_queue::size() const
{
    return storage.count();
}

void Char_queue::push(const char& c)
{
    storage.appendElement(c);
}

void Char_queue::pop()
{
    storage.removeLastElement();
}

char Char_queue::front() const
{
    return storage.getLast();
}