// HW7-3.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <string>
#include "myVector.h"

int main()
{
    setlocale(LC_ALL, "Rus");

    MyVector<std::string> myVector;
    myVector.push_back("10.2");
    myVector.push_back("20");
    myVector.push_back("30");
    myVector.push_back("40");
    myVector.push_back("50");
    myVector.push_back("60");
    myVector.push_back("70");
    myVector.push_back("80");
    myVector.push_back("90.9");
    
    std::cout << "Capacity = " << myVector.capacity() << "; Size = " << myVector.size() << std::endl;
    std::cout << "My Vector: ";

    for (int i=0;i<myVector.size();i++)
    {
        std::cout << std::fixed << myVector.at(i) << " ";
    }
    std::cout << std::endl;

    try
    {
        myVector.at(20);
    }
    catch (const std::exception& e) 
    {
        std::cout << e.what() << std::endl;
    }
}


