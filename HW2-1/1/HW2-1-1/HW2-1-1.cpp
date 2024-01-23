// HW2-1-1.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>

int main()
{
    enum class months
    {
        yan = 1,
        feb,
        mar,
        apr,
        may,
        jun,
        jul,
        aug,
        sep,
        oct,
        nov,
        dec
    };

    int monNum;
    months monNumCast;
    
    setlocale(LC_ALL, "Russian");

    while (true)
    {
        std::cout << "Введите номер месяца или 0 для завершения работы: ";
        std::cin >> monNum;
        if (monNum == 0)
        {
            std::cout << "до свидания!" << std::endl;
            return 0;
        }
        monNumCast = static_cast<months>(monNum);
        switch (monNumCast)
        {
        case months::yan:
        {
            std::cout << "январь" << std::endl;
            break;
        }
        case months::feb:
        {
            std::cout << "февраль" << std::endl;
            break;
        }
        case months::mar:
        {
            std::cout << "март" << std::endl;
            break;
        }
        case months::apr:
        {
            std::cout << "апрель" << std::endl;
            break;
        }
        case months::may:
        {
            std::cout << "май" << std::endl;
            break;
        }
        case months::jun:
        {
            std::cout << "июнь" << std::endl;
            break;
        }
        case months::jul:
        {
            std::cout << "июль" << std::endl;
            break;
        }
        case months::aug:
        {
            std::cout << "август" << std::endl;
            break;
        }
        case months::sep:
        {
            std::cout << "сентябрь" << std::endl;
            break;
        }
        case months::oct:
        {
            std::cout << "октябрь" << std::endl;
            break;
        }
        case months::nov:
        {
            std::cout << "ноябрь" << std::endl;
            break;
        }
        case months::dec:
        {
            std::cout << "декабрь" << std::endl;
            break;
        }
        default:
        {
            std::cout << "такого месяца не существует" << std::endl;
        }
        }
    }
    return 0;
}
