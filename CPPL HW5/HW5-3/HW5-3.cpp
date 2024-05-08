// HW5-3.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <vector>
class get_sum
{
public:
    get_sum()
    {

    }
    int operator ()(std::vector<int> v)
    {
        int sum = 0;
        for (auto a : v)
        {
            if (a % 3 == 0)
            {
                sum += a;
            }
        }
        return sum;
    }
};
class get_count
{
public:
    get_count()
    {

    }
    int operator ()(std::vector<int> v)
    {
        int cnt = 0;
        for (auto a : v)
        {
            if (a % 3 == 0)
            {
                cnt++;
            }
        }
        return cnt;
    }
};

int main()
{
    std::vector<int> vect{ 4, 1, 3, 6, 25, 54 };
    std::cout << "[IN]: ";
    for (int i = 0; i < vect.size(); i++)
    {
        std::cout << vect[i] << " ";
    }
    std::cout << std::endl;

    get_sum g;
    std::cout << "[OUT]: get_sum() = " << g(vect) << std::endl;
    get_count c;
    std::cout << "[OUT]: get_count() = " << c(vect) << std::endl;
}


