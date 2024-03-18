// Algo HW2-2.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
int main()
{
    setlocale(LC_ALL, "Rus");
    const int maxn = 100;
    int fib[maxn];//О(n)
    int index = 0;

    fib[0] = 0;
    fib[1] = 1;

    std::cout << "Введите номер числа (меньше " << maxn << "):";
    std::cin >> index;
    if (index > 1)
    {
        for (int i = 2; i <= (index); i++)    //O(n)
        {
            fib[i] = fib[i - 2] + fib[i - 1];   //0(1)
        }
    }
    std::cout << fib[index] << std::endl;  //Сложность O(n) по времени и O(n) по памяти
}
