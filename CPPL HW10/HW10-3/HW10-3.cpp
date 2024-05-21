// HW10-3.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//
#include <iostream>
#include <vector>

#include "MyUnique_Ptr.h"

int main()
{
    int val{ 5 };
    std::cout << &val << std::endl;
    HW10_3::MyUnique_Ptr<int> a( &val, "ptr a" );
    std::cout << "addr ptr a: " << a.getPtr() << " value: " << *a << std::endl;
    *a = 10;
    HW10_3::MyUnique_Ptr<int> b( a.release(), "ptr b");
    std::cout << "addr ptr b: " << b.getPtr() << " value: " << *b << std::endl;
    std::cout << val << std::endl;
    return 0;
}


