// HW10-3.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//
#include <iostream>
#include <vector>

#include "MyUnique_Ptr.h"

int main()
{
    int val{ 5 };
    HW10_3::MyUnique_Ptr<int> a(&val);
    std::cout << "ptr a value: " << *a << std::endl;
    *a = 10;
    HW10_3::MyUnique_Ptr<int> b(a.release());
    std::cout << "ptr b value: " << *b << std::endl;
    std::cout << val << std::endl;
    return 0;
}


