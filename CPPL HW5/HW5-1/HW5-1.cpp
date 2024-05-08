// HW5-1.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include "Pow2.h"
#include <vector>

int main()
{
    std::vector<int> arr{ 3, 20 };
    std::vector<int> res = pow2(arr);
    std::cout << "[IN]: ";
    printValue(arr);
    std::cout << "[OUT]: ";
    printValue(res);

}

