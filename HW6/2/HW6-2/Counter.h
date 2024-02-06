#pragma once
class Counter
{
private:
    int count;
public:
    int getCount();
    void increment();
    void decrement();
    Counter();
    Counter(int count);
};

