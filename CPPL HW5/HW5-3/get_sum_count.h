#pragma once
#include <vector>

class get_sum_count
{
private:
    int sum = 0;
    int cnt = 0;
public:
    void operator ()(std::vector<int> v);
    int get_sum();
    int get_count();
};

