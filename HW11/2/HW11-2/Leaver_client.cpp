// Leaver_client.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <Windows.h>

#include "Leaver.h"
int main()
{
    setlocale(LC_ALL, "Russian");
    SetConsoleOutputCP(1251);
    SetConsoleCP(1251);

    std::string n;
    std::cout << "Введите имя: ";
    std::cin >> n;

    Leaver l;    
    l.leave(n);
	system("pause");
    return 0;
}


