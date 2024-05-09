// HW5-1.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//
//Обратите внимание на подключение заголовочных файлов:
//сначала стандартные
#include <iostream>
#include <vector>
//потом свои
#include "Pow2.h"
//"Бутербродов" лучше не делать

int main()
{
    std::vector<int> arr{ 3, 20 };
    std::vector<int> res = pow2(arr);
    //double arr = 3.0;
    //double res = pow2(arr);
    std::cout << "[IN]: ";
    printValue(arr);
    std::cout << "[OUT]: ";
    printValue(res);

}

