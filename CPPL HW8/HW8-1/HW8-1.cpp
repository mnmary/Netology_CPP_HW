// HW8-1.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <vector>
#include "HW8_1.h"

int main()
{
    std::vector < std::string > vect{ "row", "200", "columns", "1.0", "row", "200"};

    HW8_1::deleteDouble<std::string>(vect);
    HW8_1::print<std::string>(vect);

    return 0;
}

