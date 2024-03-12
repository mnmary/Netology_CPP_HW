// Algo HW1-2.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>

int calcGreate(int to, int *arr, int arrSize)
{
    int l = 0, h = 0, m = 0, result = 0;

    h = arrSize - 1;
    while (l <= h)
    {
        m = (l + h) / 2;
        if (m > 0)
        {
            if ((arr[m] > to) && (to >= arr[m - 1]))
            {
                result = m + 1;//предыдущий элемент уже меньше
                break;
            }
        }
        else
        {
            //два элемента в массиве. Стоим на первом
            if (arr[m] > to)
            {
                result = m + 1;//первый элемент уже больше
                break;
            }
            else if ((arr[m] <= to) && (to < arr[m + 1]))
            {
                result = m + 1 + 1;//второй элемент уже больше
                break;
            }
        }

        if (to < arr[m])
        {
            h = m - 1;
        }
        else
        {
            l = m + 1;
        }
    }
    //если не нашли индекс - вернем 0
    if (result == 0)
    {
        return 0;
    }
    //вернем количество чисел начиная с индекса
    return (arrSize - (result - 1));
}


int main()
{
    int arr[] = { 14, 16, 19, 32, 32, 32, 56, 69, 72 };
    int to = 0;

    setlocale(LC_ALL, "Rus");

    std::cout << "Введите точку отсчета: ";
    std::cin >> to;
    std::cout << "Количество элементов в массиве больших, чем " << to << ": " << calcGreate(to, arr, sizeof(arr) / sizeof(arr[0])) << std::endl;
}

