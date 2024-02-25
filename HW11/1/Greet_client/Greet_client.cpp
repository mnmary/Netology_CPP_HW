// Greet_client.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <Windows.h>

#include "Greeter.h"
int main()
{
    setlocale(LC_ALL, "Russian");
    SetConsoleOutputCP(1251);
    SetConsoleCP(1251);

    std::string n;
    std::cout << "Введите имя: ";
    std::cin >> n;

    Greeter g;    
    g.greet(n);
	system("pause");
    
    return 0;
}


