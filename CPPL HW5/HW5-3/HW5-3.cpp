// HW5-3.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <vector>
#include "get_sum_count.h"
void print(const std::vector<int>& vect)
{
    for (auto v:vect)
    {
        std::cout << v << " ";
    }
    std::cout << std::endl;

}
int main()
{
    std::vector<int> vect{ 4, 1, 3, 6, 25, 54 };

    std::cout << "[IN]: ";
    print(vect);

    get_sum_count g;
    g(vect);

    std::cout << "[OUT]: get_sum() = " << g.get_sum() << std::endl;
    std::cout << "[OUT]: get_count() = " << g.get_count() << std::endl;
}


