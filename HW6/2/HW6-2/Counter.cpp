#include "Counter.h"
    int Counter::getCount()
    {
        return (count);
    }
    void Counter::increment()
    {
        count++;
    }
    void Counter::decrement()
    {
        count--;
    }
    Counter::Counter()
    {
        count = 1;
    }
    Counter::Counter(int count)
    {
        this->count = count;
    }
