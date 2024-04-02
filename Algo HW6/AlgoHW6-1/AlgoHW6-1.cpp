// AlgoHW6-1.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
int simple_string_hash(std::string s)
{
    int result = 0;
    for (int i = 0; i < s.length(); i++)
    {
        result = result + s[i];
    }
    return result;
}

int main()
{
    std::string cmd;

    setlocale(LC_ALL, "Rus");

    while (true)
    {
        std::cout << "Введите строку: ";
        std::cin >> cmd;
        if (cmd == "exit") break;
        std::cout << "Наивный хэш строки " << cmd << " = " << simple_string_hash(cmd) << std::endl;
    }
    std::cout << "Наивный хэш строки " << cmd << " = " << simple_string_hash(cmd) << std::endl;
}

