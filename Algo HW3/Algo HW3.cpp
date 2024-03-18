// Algo HW3.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

//сортировка слиянием
#include <iostream>

void printArr(int* arr, int arrSize)
{
    for (int i = 0; i < arrSize; i++)
    {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;
}

void merge(int* arr, int* leftArr, int nL, int* rightArr, int nR)
{
    int i = 0, j = 0, k = 0;
    while (i < nL && j < nR)
    {
        if (leftArr[i] < rightArr[j])
            arr[k++] = leftArr[i++];
        else
            arr[k++] = rightArr[j++];
    }
    while (i < nL)
    {
        arr[k++] = leftArr[i++];
    }
    while (j < nR)
    {
        arr[k++] = rightArr[j++];
    }
}
void merge_sort(int* arr, int size)
{
    if (size == 1)
    {
        return;
    }

    int mid = size / 2;
    
    int* leftArr = new int[mid];
    int* rightArr = new int[size - mid];

    for (int i = 0; i < mid; i++)
    {
        leftArr[i] = arr[i];
    }
    for (int i = mid; i < size; i++)
    {
        rightArr[i - mid] = arr[i];
    }
    merge_sort(leftArr, mid);
    merge_sort(rightArr, size - mid);
    merge(arr, leftArr, mid, rightArr, size - mid);

    delete[] leftArr;
    delete[] rightArr;
}


int main() {
    int arr[] = { 3, 43, 38, 29, 18, 72, 57, 61, 2, 33 };
    //int arr[] = {88, 91, 87, 59, 53, 49, 29, 16, 4, 27, 28, 89, 2, 25, 74};
    //int arr[] = {24, 66, 20, 79, 30, 16, 19, 62, 94, 59, 0, 7, 59, 90, 84, 60, 95, 62};
    int arrSize = 0;

    setlocale(LC_ALL, "Rus");
    arrSize = sizeof(arr) / sizeof(int);
    std::cout << "Исходный массив: ";   
    printArr(arr, arrSize);

    std::cout << "Отсортированный массив: ";
    merge_sort(arr,arrSize);
    printArr(arr, arrSize);

    return 0;
} 
