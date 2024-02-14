// HW8-1.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <Windows.h>
#include <stdexcept>

int function(std::string str, int forbidden_length)
{
    if (str.length() == forbidden_length)
    {
        std::string errorMessage = "bad_length";
        throw std::runtime_error(errorMessage);
    }
    return (str.length());
}

int main()
{
    setlocale(LC_ALL, "Rus");
    SetConsoleOutputCP(1251);
    SetConsoleCP(1251);

    int forbidden_length = 0;
    std::string word = "";
    int word_len = 0;

    std::cout << "Введите запретную длину:";
    std::cin >> forbidden_length;

    while (true)
    {
        std::cout << "Введите слово: ";
        std::cin >> word;
        try
        {
            word_len = function(word, forbidden_length);
            std::cout << "Длина слова \"" << word << "\" равна " << word_len << std::endl;
        }
        catch (const std::runtime_error& e)
        {
            std::string errorMessage = e.what();
            if (errorMessage == "bad_length")
            {
                std::cout << "Вы ввели слово запретной длины. До свидания." << std::endl;
                return -1;
            }
        }

    }

    return 0;
}

