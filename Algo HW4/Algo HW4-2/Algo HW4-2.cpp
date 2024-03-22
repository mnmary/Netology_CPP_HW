// Algo HW4-2.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>

void append_to_dynamic_array(int*& arr, int& logSize, int& factSize, int inValue)
{
    logSize++;
    if (factSize < logSize)
    {
        factSize = factSize * 2;


        int* newArr = new int[factSize];


        for (int i = 0; i < logSize; i++)
        {
            newArr[i] = arr[i];
        }
        delete[] arr;
        arr = newArr;
    }
    arr[logSize - 1] = inValue;
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
    int factSize = 0, logSize = 0, inValue = 0;

    setlocale(LC_ALL, "Rus");
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

        std::cout << "Введите элемент для добавления: ";
        std::cin >> inValue;

        if (inValue == 0) break;
        append_to_dynamic_array(arr, logSize, factSize, inValue);            
    }


    std::cout << "Спасибо! Ваш массив: ";
    print_dynamic_array(arr, logSize, factSize);

    delete[] arr;

    return 0;
}


