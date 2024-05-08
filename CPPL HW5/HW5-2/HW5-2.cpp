// HW5-2.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include "Array2D.h"

int main()
{
    setlocale(LC_ALL, "Rus");
    auto test = HW5_2::Array2D<int>(2, 2);
    test[1][1] = 4;
    std::cout << test[1][1] << std::endl;
    std::cout <<  "Размер: " <<  test.Size() << std::endl;
    //test.print();
}

