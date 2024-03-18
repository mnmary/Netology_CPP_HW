// Algo HW2-1.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
int fib(int n)
{
    if (n == 0)
        return 0;
    if (n == 1)
        return 1;
    return fib(n - 2) + fib(n - 1);//на единицу числа требуется выполнить два вызова
}
int main()
{
    setlocale(LC_ALL, "Rus");
    int index = 0;
    std::cout << "Введите номер числа: ";
    std::cin >> index;
    std::cout << fib(index) << std::endl;//временная сложность О(2^n) - экспоненциальная, сложность по памяти О(1)
}
