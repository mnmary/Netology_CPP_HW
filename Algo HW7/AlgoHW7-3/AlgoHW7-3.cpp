// AlgoHW7-3.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
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
                inputFile >> arr[i][j];
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




bool dfs(int** graph, int i, bool* visited, int vCount, int prev, bool showVertex)
{
    visited[i] = true;
    if (showVertex)
    {
        std::cout << "" << i + 1 << " ";
    }

    //смежные обходим
    for (int v = 0; v < vCount; v++)
    {
        if (i != v)
        {
            if (graph[i][v])
            {
                if (!visited[v])
                {
                    dfs(graph, v, visited, vCount, i, showVertex);
                }
                else
                {
                    if (v != prev)
                    {
                        return true;
                    }
                }
            }
        }
    }
    return false;
}

bool is_cyclic(int** arr, int vCount)
{
    bool visited[100];

    for (int i = 0; i < vCount; i++)
    {
        visited[i] = false;
    }
    for (int i = 0; i < vCount; i++)
    {
        if (!visited[i])
        {
            if (dfs(arr, i, visited, vCount, 0, false))
            {
                return true;
            }
        }
    }

    return false;
}

int main()
{
    int** graph;
    int vCount = 0;

    setlocale(LC_ALL, "Rus");

    graph = loadArrayFromFile(vCount);  //грузим начальную конфигурацию из файла, возвращаем размер массива и сам массив

    if (graph == nullptr)  //массив не загружен
    {
        std::system("pause");
        return -1;
    }
    printArray(graph, vCount);

    if (is_cyclic(graph, vCount))
    {
        std::cout << "В графе есть цикл!" << std::endl;
    }
    else
    {
        std::cout << "В графе нет циклов" << std::endl;
    }

    deleteArray(graph, vCount);
    return 0;
}



