// AlgoHW5-1.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
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
    print_array(arr,size);

    int i = 0;
    while (i<size)
    {
        print_item(arr, i, size);
        i++;
    }

}
int main()
{
    setlocale(LC_ALL, "rus");

    //int arr[] = { 1, 3, 6, 5, 9, 8 };
    //int arr[] = { 94, 67, 18, 44, 55, 12, 6, 42 };
    int arr[] = { 16, 11, 9, 10, 5, 6, 8, 1, 2, 4 };
    int arrSize = sizeof(arr) / sizeof(int);
    print_pyramid(arr, arrSize);
}

