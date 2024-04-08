// AlgoDijstera.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
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
            std::cout << arr[i][j] << " ";
        }
        std::cout << std::endl;
    }
}



int main()
{
    int** graph;
    int vCount = 0;
    int weight[100];
    bool visited[100];
    int minValue = 0;
    int u = 0;
    int INF = 9999;
    int path[100];

    setlocale(LC_ALL, "Rus");
    std::cout << "Алгоритм Дейкстры (нахождение кратчайшего пути в ориентированном графе)" << std::endl;

    graph = loadArrayFromFile(vCount);  //грузим начальную конфигурацию из файла, возвращаем размер массива и сам массив

    if (graph == nullptr)  //массив не загружен
    {
        std::system("pause");
        return -1;
    }
    printArray(graph, vCount);
    
    //dijkstra
    //graph - матрица смежности с весами ребер
    //vCount - размер матрицы - количество точек графа
    //INF - максимально возможное значение
    //weight - стоимость пути в каждой вершине графа
    //visited - флаг посещения вершины графа

    for (int i = 0; i < vCount; i++)
    {
        weight[i] = INF;
        visited[i] = false;
    }

    //стартуем с нулевой вершины графа
    weight[0] = 0;  //стоимость пути в начальной точке равна 0
    //перебираем все вершины графа
    for (int j = 0; j < vCount; j++)
    {
        minValue = INF; //самый минимальный путь
        //цикл по вершинам
        for (int i = 0; i < vCount; i++)
        {
            if (!visited[i] && (weight[i] < minValue))
            {
                minValue = weight[i];
                u = i;  //запомнили вершину с минимальным стоимостью пути
            }
        }

        visited[u] = true;  //посещаем вершину с минимальной стоимостью пути


        for (int i = 0; i < vCount; i++)
        {
            if (!visited[i] && graph[u][i] && (weight[u]!=INF) && (weight[u]+graph[u][i] < weight[i]))
            {
                weight[i] = weight[u]+graph[u][i];
            }
        }


    }//for j
    std::cout << "Стоимость пути вершин графа (начало с вершины 0): " << std::endl;
    for (int i = 0; i < vCount; i++)
    {
        std::cout << weight[i] << " ";
    }
    std::cout << std::endl;

    //восстанавливаем кратчайший путь
    int finish = 3; //конечная точка
    path[0] = finish;    //конечная точка маршрута
    int k = 1;
    int currentWeight = weight[finish]; //стоимость пути конечной точки маршрута
    int currentVertex = finish;
    do
    {
        for (int i = 0; i < vCount; i++)    //сканируем все вершины графа на предмет связи с конечной точкой маршрута
        {
            if (graph[i][currentVertex] != 0)   //узел смежный?
            {
                int tempWeight = currentWeight - graph[i][currentVertex];   //из стоимости пути вычитаем вес ребра
                if (tempWeight == weight[i])    //ребро подходит?
                {
                    currentWeight = weight[i];  //запоминаем оставшуюся стоимость пути
                    currentVertex = i;  //переходим в следующую точку маршрута
                    path[k] = i;    //обновляем маршрут
                    k++;    //обновляем счетчик маршрута
                }
            }
        }
    } while (currentVertex != 0);

    std::cout << "Кратчайший путь из точки " << finish << " в точку  " << 0 << ": " << std::endl;
    for (int i = 0; i < k; i++)
    {
        if (i == k - 1)
        {
            std::cout << path[i];
        }
        else
        {
            std::cout << path[i] << " <- ";
        }
    }
    std::cout << std::endl;

    deleteArray(graph, vCount);
    return 0;
}


