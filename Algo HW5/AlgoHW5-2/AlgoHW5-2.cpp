// AlgoHW5-2.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>

void print_array(int* arr, int size)
{
    for (int i = 0; i < size; i++)
    {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;
}

void print_current_item(int* arr, int index, int size)
{
    std::string leftOrRight;

    std::cout << "OK" << std::endl;
    if (index == 0)
    {
        std::cout << "Вы находитесь здесь: " << index << " root " << arr[index] << " " << std::endl;
        return;
    }
    //index
    int level = static_cast<int>(log2(index + 1));
    int parent = (index - 1) / 2;
    if ((index % 2) != 0)
    {
        leftOrRight = "Left";
    }
    else
    {
        leftOrRight = "Right";
    }
    std::cout << "Вы находитесь здесь: " << level << " " << leftOrRight << " (" << arr[parent] << ") " << arr[index] << std::endl;
}

void print_item(int* arr, int index, int size)
{
    std::string leftOrRight;
    if (index == 0)
    {
        std::cout << index << " root " << arr[index] << " " << std::endl;
        return;
    }
    //index
    int level = static_cast<int>(log2(index + 1));
    int parent = (index - 1) / 2;
    if ((index % 2) != 0)
    {
        leftOrRight = "Left";
    }
    else
    {
        leftOrRight = "Right";
    }
    std::cout << level << " " << leftOrRight << " (" << arr[parent] << ") " << arr[index] << std::endl;
}

void print_pyramid(int* arr, int size)
{
    std::cout << "Исходный массив: ";
    print_array(arr, size);

    //int i = 0;
    // while (i < size)
    //{
    //    print_item(arr, i, size);
    //    i++;
    // }

}
int main()
{
    std::string command;
    setlocale(LC_ALL, "rus");

    //int arr[] = { 1, 3, 6, 5, 9, 8 };
    //int arr[] = { 94, 67, 18, 44, 55, 12, 6, 42 };
    int arr[] = { 16, 11, 9, 10, 5, 6, 8, 1, 2, 4 };
    int arrSize = sizeof(arr) / sizeof(int);
    
    int i = 0;

    print_pyramid(arr, arrSize);

    while (true)
    {
        std::cout << "Введите команду: ";
        std::cin >> command;

        if (command == "up")
        {
            if (i == 0)
            {
                std::cout << "Ошибка! Отсутствует родитель" << std::endl;
            }
            else
            {
                i = (i-1)/2;
                print_current_item(arr, i, arrSize);
            }
        }
        else if (command == "left")
        {
            if (2 * i + 1 >= arrSize)
            {
                std::cout << "Ошибка! Отсутствует левый потомок" << std::endl;
            }
            else
            {
                i = 2*i+1;
                print_current_item(arr, i, arrSize);

            }
        }
        else if (command == "right")
        {
            if (2 * i + 2 >= arrSize)
            {
                std::cout << "Ошибка! Отсутствует правый потомок" << std::endl;
            }
            else
            {
                i = 2 * i + 2;
                print_current_item(arr, i, arrSize);
            }

        }
        else if (command == "exit")
        {
            return(0);
        }
        else
        {
            std::cout << "Неизвестная команда" << std::endl;
        }
    }
}


