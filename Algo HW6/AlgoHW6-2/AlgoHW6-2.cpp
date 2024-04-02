// AlgoHW6-2.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
int real_string_hash(std::string s, int n, int p)
{
    long long result = 0;
    long long p_temp = p;
    for (int i = 0; i < s.length(); i++)
    {
        if (i == 0)
        {
            result = s[i];
        }
        else
        {
            result = result + p_temp * s[i];
            p_temp = p_temp * p;
        }
    }
    return result % n;
}

int main()
{
    std::string cmd;
    int p = 0, n = 0;   //p - простое число - на него умножаем
                        //n - размер хэш-таблицы

    setlocale(LC_ALL, "Rus");

    std::cout << "Введите p: ";
    std::cin >> p;
    std::cout << "Введите n: ";
    std::cin >> n;
    while (true)
    {
        std::cout << "Введите строку: ";
        std::cin >> cmd;
        if (cmd == "exit") break;
        std::cout << "Хэш строки " << cmd << " = " << real_string_hash(cmd, n, p) << std::endl;
    }
    std::cout << "Хэш строки " << cmd << " = " << real_string_hash(cmd, n, p) << std::endl;

    return 0;
}


