// HW7-1.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <map>
#include <string>
#include <vector>
#include <utility>
#include <algorithm>

bool mySort(const std::pair< std::string, int>& a, const std::pair < std::string, int>& b)
{
    return a.second > b.second;
}

int main()
{
    std::map< std::string, int > myMap;
    std::string myStr, myS;

    std::cout << "[IN]: ";
    std::getline(std::cin, myStr);

    for (int i = 0; i < myStr.size(); i++)
    {
        myS = myStr[i];
        myMap[myS]++;
    }
    std::cout << "[OUT]: " << std::endl;
    
    std::vector< std::pair<std::string, int> > myVec(myMap.begin(), myMap.end());

    std::sort(myVec.begin(), myVec.end(),mySort);
    for (auto v : myVec)
    {
        std::cout << v.first << " " << v.second << std::endl;
    }
}


