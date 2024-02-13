// HW8-1.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <Windows.h>

enum errors
{
    no_error,
    bad_length
};

int function(std::string str, int forbidden_length)
{
    if (str.length() == forbidden_length)
    {
        throw(bad_length);
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
        catch (const errors e)
        {
            if (e == bad_length)
            {
                std::cout << "Вы ввели слово запретной длины! До свидания." << std::endl;
            }
            return -1;
        }

    }

    return 0;
}

