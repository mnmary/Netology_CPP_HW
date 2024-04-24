// HW1-3.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <functional>
#include <vector>
#include "math.h"

int main()
{
    auto sinus = [](int a)
        {
            std::cout << "sinus = " << sin(a*3.14/180) << std::endl;
            return sin(a * 3.14 / 180);
        };
    auto cosinus = [](int a)
        {
            std::cout << "cosinus = " << cos(a * 3.14 / 180) << std::endl;
            return cos(a * 3.14 / 180);
        };

    std::vector<int> angles = {30,60,90};
    std::vector< std::function<int(int a)>> functions;
    functions.push_back(sinus); //теперь в векторе у нас будут функции
    functions.push_back(cosinus);

    for (const auto& angle : angles) {
        std::cout << angle << ": ";
        for (const auto& function : functions)
            function(angle);    //вызываем функцию
        std::cout << std::endl;
    }
}

