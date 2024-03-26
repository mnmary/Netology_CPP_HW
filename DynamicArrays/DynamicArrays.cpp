// DynamicArrays.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
void push_back(int*& arr, int& size, const int value)
//увеличиваем размер рассива
{
    int* newArray = new int[size + 1];
    for (int i = 0; i < size; i++)
    {
        newArray[i] = arr[i];
    }
    newArray[size++] = value;

    delete[] arr;
    arr = newArray;
}

void print_array(int* arr, int size)
{
    for (int i = 0; i < size; i++)
    {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;
}

void pop_back(int*& arr, int& size)
//уменьшаем размер массива
{
    size--;
    int* newArray = new int[size];
    for (int i = 0; i < size; i++)
    {
        newArray[i] = arr[i];
    }

    delete[] arr;
    arr = newArray;
}

int main()
{
    int size = 5;
    int* arr = new int[size];
    
    for (int i = 0; i < size; i++)
    {
        arr[i] = i * 2;
    }
    print_array(arr, size);

    push_back(arr, size, 111);
    print_array(arr, size);

    pop_back(arr, size);
    print_array(arr, size);

    delete[] arr;
}

