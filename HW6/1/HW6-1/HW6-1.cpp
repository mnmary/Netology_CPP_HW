// HW6-1.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include "math.h"

int main()
{
    int x, y, oper;

    setlocale(LC_ALL, "Russian");

    std::cout << "Введите первое число: ";
    std::cin >> x;
    std::cout << "Введите второе число: ";
    std::cin >> y;
    std::cout << "Выберите операцию (1 - сложение, 2 вычитание, 3 - умножение, 4 - деление, 5 - возведение в степень): ";
    std::cin >> oper;
    switch (oper)
    {
    case 1:
        std::cout << x << " плюс " << y << "= " << add(x, y) << std::endl;
        break;
    case 2:
        std::cout << x << " минус " << y << "= " << sub(x, y) << std::endl;
        break;
    case 3:
        std::cout << x << " умножить на " << y << "= " << mul(x, y) << std::endl;
        break;
    case 4:
        std::cout << x << " поделить на " << y << "= " << divide(x, y) << std::endl;
        break;
    case 5:
        std::cout << x << " в степени " << y << "= " << pow_f(x, y) << std::endl;
        break;
    default:
        break;
    }
    return 0;
}


