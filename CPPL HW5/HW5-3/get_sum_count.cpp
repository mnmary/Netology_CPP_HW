#include "get_sum_count.h"

void get_sum_count::operator ()(std::vector<int> v)
{
    sum = 0;
    cnt = 0;
    for (auto a : v)
    {
        if (a % 3 == 0)
        {
            sum += a;
            cnt++;
        }
    }
}
int get_sum_count::get_sum()
{
    return cnt;
}

int get_sum_count::get_count()
{
    return sum;
}