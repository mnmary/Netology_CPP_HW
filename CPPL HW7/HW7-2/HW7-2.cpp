// HW7-2.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <set>
#include <vector>
#include <algorithm>
bool mySort(const int& a, const int& b)
{
    return a > b;
}
int main()
{
    int cnt = 0;
    int m;
    std::set<int> mySet;
    
    std::cout << "[IN]: " << std::endl;
    std::cin >> cnt;
    for (int i = 0; i < cnt; i++)
    {
        std::cin >> m;
        mySet.insert(m);
    }
    std::vector<int> myVect(mySet.begin(), mySet.end());
    std::sort(myVect.begin(), myVect.end(), mySort);

    std::cout << "[OUT]: " << std::endl;
    for (auto v : myVect)
    {
        std::cout << v << std::endl;
    }


}


