// HW7-1.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>

#define MODE 1

#ifndef MODE
#error "Необходимо сформировать переменную MODE"
#endif

#if MODE == 1
int add(int a, int b)
{
    return a + b;
}
#endif

int main()
{
    setlocale(LC_ALL, "Russian");
#if MODE==0
    std::cout << "Работаю в режиме тренировки";
#elif MODE == 1
    int a, b;
    std::cout << "Работаю в боевом режиме" << std::endl;
    std::cout << "Введите число 1: ";
    std::cin >> a;
    std::cout << "Введите число 2: ";
    std::cin >> b;
    std::cout << "Результат сложения: " << add(a,b);

#else
    std:: cout << "Неизвестный режим. Завершение работы";
#endif
}

