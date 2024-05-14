// HW7-1.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <map>
#include <string>
#include <vector>
#include <utility>
#include <algorithm>

int main()
{
    std::map< std::string, int> myMap;
    std::multimap< int, std::string, std::greater<int> > myMapR;
    std::string myStr, myS;

    std::cout << "[IN]: ";
    std::getline(std::cin, myStr);

    for (int i = 0; i < myStr.size(); i++)
    {
        myS = myStr[i];
        myMap[myS]++;
    }
    std::cout << "[OUT]: " << std::endl;
    
    for (auto v : myMap)
    {
        std::pair<int, std::string> myPair(v.second, v.first);
        myMapR.insert(myPair);
    }
    for (auto v : myMapR)
    {
        std::cout << v.first << " " << v.second << std::endl;
    }
}


