// Algo HW4-3.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//
#include <iostream>
#include <Windows.h>

void remove_dynamic_array_head(int*& arr, int& logSize, int& factSize)
{
    if ((logSize - 1) <= (factSize / 3))
    {
        factSize = factSize / 3;
    }
    
    int* newArr = new int[factSize];

    for (int i = 1; i < logSize; i++)
    {
        newArr[i-1] = arr[i];
    }
    std::memcpy(&arr, &newArr, factSize * sizeof(int));

    logSize--;
}


void print_dynamic_array(int* arr, int logSize, int factSize)
{
    for (int i = 0; i < factSize; i++)
    {
        if (i < logSize)
        {
            std::cout << arr[i] << " ";
        }
        else
        {
            std::cout << " _ ";
        }
    }
    std::cout << std::endl;
}

int main()
{
    int factSize = 0, logSize = 0;
    std::string inValue = "";

    setlocale(LC_ALL, "Rus");
    SetConsoleOutputCP(1251);
    SetConsoleCP(1251);

    std::cout << "Введите фактический размер массива: ";
    std::cin >> factSize;
    std::cout << "Введите логический размер массива: ";
    std::cin >> logSize;

    if (logSize > factSize)
    {
        std::cout << "Ошибка! Логический размер массива не может превышать фактический!" << std::endl;
        return 1;
    }
    int* arr = new int[factSize];

    for (int i = 0; i < logSize; i++)
    {
        std::cout << "Введите arr[" << i << "]: ";
        std::cin >> arr[i];
    }


    while (true)
    {
        std::cout << "Динамический массив: ";
        print_dynamic_array(arr, logSize, factSize);

        std::cout << "Удалить первый элемент? ";
        std::cin >> inValue;

        if (inValue == "нет") break;

        if (logSize == 0)
        {
            std::cout << "Невозможно удалить первый элемент, так как массив пустой. До свидания!";
            delete[] arr;
            return 0;
        }
        remove_dynamic_array_head(arr, logSize, factSize);
    }


    std::cout << "Спасибо! Ваш массив: ";
    print_dynamic_array(arr, logSize, factSize);

    delete[] arr;
    return 0;
}


