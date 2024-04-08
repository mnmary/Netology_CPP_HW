// AlgoHW8-2.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
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

void dfs(int** graph, int i, bool* visited, int vCount, int* order)
{
    visited[i] = true;

    //смежные обходим
    for (int v = 0; v < vCount; v++)
    {
        if (i != v)
        {
            if (graph[i][v])
            {
                if (!visited[v])
                {
                    dfs(graph, v, visited, vCount, order);
                }
            }
        }
    }
    //вставить i в начало order
    for (int v = vCount-1; v >= 1; v--)
    {
        order[v] = order[v-1];
    }
    order[0] = i+1;
}

int main()
{
    int** graph;
    int vCount = 0;
    bool visited[100];
    int order[100];

    setlocale(LC_ALL, "Rus");

    graph = loadArrayFromFile(vCount);  //грузим начальную конфигурацию из файла, возвращаем размер массива и сам массив

    if (graph == nullptr)  //массив не загружен
    {
        std::system("pause");
        return -1;
    }
    for (int i = 0; i < vCount; i++)
    {
        visited[i] = false;
        order[i] = 0;
    }
    printArray(graph, vCount);

    for (int i = 0; i < vCount; i++)
    {
        if (!visited[i])
        {
            dfs(graph, i, visited, vCount, order);
        }
    }
     std::cout << "Топологический порядок вершин: ";
    for (int i = 0; i < vCount; i++)
    {
        std::cout << order[i] << " ";
    }
    std::cout << std::endl;

    deleteArray(graph, vCount);
    return 0;
}


