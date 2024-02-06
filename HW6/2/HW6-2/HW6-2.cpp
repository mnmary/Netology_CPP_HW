// HW6-2.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <Windows.h>
#include "Counter.h"

int main()
{
    std::string yesOrNo;
    int count;
    std::string cmd;

    setlocale(LC_ALL, "Russian");
    SetConsoleOutputCP(1251);
    SetConsoleCP(1251);

    std::cout << "Вы хотите указать начальное значение счётчика? Введите да или нет: ";
    std::cin >> yesOrNo;
    if (yesOrNo == "да")
    {

        std::cout << "Введите начальное значение счётчика: ";
        std::cin >> count;

        Counter myCounter(count);

        std::cout << "Введите команду ('+', '-', '=' или 'x'): ";
        std::cin >> cmd;
        while (cmd != "x")
        {
            if (cmd == "+")
            {
                myCounter.increment();
            }
            else if (cmd == "-")
            {
                myCounter.decrement();
            }
            else if (cmd == "=")
            {
                std::cout << myCounter.getCount() << std::endl;
            }
            else
            {
                //nothing
            }
            std::cout << "Введите команду ('+', '-', '=' или 'x'): ";
            std::cin >> cmd;
        }//while cmd
        std::cout << "До свидания!";

    }//yes
    else
    {

        Counter myCounter;

        std::cout << "Введите команду ('+', '-', '=' или 'x'): ";
        std::cin >> cmd;
        while (cmd != "x")
        {
            if (cmd == "+")
            {
                myCounter.increment();
            }
            else if (cmd == "-")
            {
                myCounter.decrement();
            }
            else if (cmd == "=")
            {
                std::cout << myCounter.getCount() << std::endl;
            }
            else
            {
                //nothing
            }
            std::cout << "Введите команду ('+', '-', '=' или 'x'): ";
            std::cin >> cmd;
        }//while cmd
        std::cout << "До свидания!";

    }//no


    
    return 0;
}


