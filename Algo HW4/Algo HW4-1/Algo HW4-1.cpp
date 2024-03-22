// Algo HW4-1.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>


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

    setlocale(LC_ALL, "Rus");
    std::cout << "Введите фактичеcкий размер массива: ";
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
    
    std::cout << "Исходный массив: ";
    print_dynamic_array(arr, logSize, factSize);

    delete[] arr;

    return 0;
}


