// AlgoHW8-1.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <fstream>



int** createArray(int vCount)
{
    //создаем динамический двумерный массив по заданным размерам
    //возвращаем указатель на него
    int** arr;

    arr = new int* [vCount];
    for (int i = 0; i < vCount; i++)
    {
        arr[i] = new int[vCount];
    }

    for (int i = 0; i < vCount; i++)
    {
        for (int j = 0; j < vCount; j++)
        {
            arr[i][j] = 0;
        }
    }
    return arr;
}

void deleteArray(int** arr, int vCount)
{
    for (int i = 0; i < vCount; i++) {
        delete[] arr[i];
    }
    delete[] arr;
}

int** loadArrayFromFile(int& vCount)
{
    int i, j;
    int** arr;

    std::ifstream inputFile("input.txt");
    if (inputFile.is_open())
    {
        inputFile >> vCount;  //размер массива - вершин

        arr = createArray(vCount);  //создаем массив
        i = 0;
        while (!inputFile.eof())
        {
            for (j = 0; j < vCount; j++)
            {
                inputFile >>  arr[i][j];
            }
            i++;
        }
        inputFile.close();
    }
    else
    {
        std::cout << "Error in open file" << std::endl;
        return nullptr;
    }
    return arr;

}

void printArray(int** arr, int vCount)
{
    std::cout << "Входящий файл: " << std::endl << vCount << std::endl;
    for (int i = 0; i < vCount; i++)
    {
        for (int j = 0; j < vCount; j++)
        {
            std::cout << arr[i][j];
        }
        std::cout << std::endl;
    }
}


int main()
{
    int** graph;
    int vCount = 0;
    bool flag = false;

    setlocale(LC_ALL, "Rus");

    graph = loadArrayFromFile(vCount);  //грузим начальную конфигурацию из файла, возвращаем размер массива и сам массив

    if (graph == nullptr)  //массив не загружен
    {
        std::system("pause");
        return -1;
    }
    printArray(graph, vCount);

    std::cout << "Текстовый вид орграфа:" << std::endl;
    for (int i = 0; i < vCount; i++)
    {
        std::cout << i + 1 << ": ";
        flag = true;
        for (int j = 0; j < vCount; j++)
        {
            if (i != j)
            {
                if (graph[i][j])
                {
                    std::cout << j + 1 << " ";
                    flag = false;
                }
            }
        }
        if (flag)
        {
            std::cout << "нет";
        }
        std::cout << std::endl;
    }
    std::cout << std::endl;

    deleteArray(graph, vCount);
    return 0;
}
