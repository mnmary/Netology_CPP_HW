// HW7-2.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <set>
#include <vector>
#include <algorithm>
int main()
{
    int cnt = 0;
    int m;
    std::set<int,std::greater<int> > mySet;
    
    std::cout << "[IN]: " << std::endl;
    std::cin >> cnt;
    for (int i = 0; i < cnt; i++)
    {
        std::cin >> m;
        mySet.insert(m);
    }

    std::cout << "[OUT]: " << std::endl;
    for (auto v : mySet)
    {
        std::cout << v << std::endl;
    }


}


