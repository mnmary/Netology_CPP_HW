// DynamicArraysTwoSize.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>

void incMatrix(int**& matrix, int& M, int& N, const int value)
// функция увеличения размера двумерного динамического массива на 1 строку и 1 столбец 
{
    // создание нового массива для копирования
    int** newMatrix = new int* [M+1];

    for (int i = 0; i < (M+1); i++)
    {
        newMatrix[i] = new int[N+1];
    }


    // копирование элементов старого массива в новый
    for (int i = 0; i <= M; i++)
    {
        for (int n = 0; n <= N; n++)
        {
            if ((i == M) || (n == N))
            {
                newMatrix[i][n] = 0;
            }
            else
            {
                newMatrix[i][n] = matrix[i][n];
            }
        }
    }

    // удаление старого массива
    for (int i = 0; i < M; i++)
    {
        delete[] matrix[i];
    }

    newMatrix[M][N] = value;
    M++;
    N++;

    matrix = newMatrix;

}
void print_array(int** arr, int M, int N)
{
    // вывод массива
    for (int i = 0; i < M; i++)
    {
        for (int j = 0; j < N; j++)
        {
            std::cout << arr[i][j] << " ";

        }
        std::cout << std::endl;
    }
    std::cout << std::endl;
}

int main()
{
    int M = 3, N = 5; // размеры матрицы
    int** matrix = new int* [M];

    for (int i = 0; i < M; i++)
    {
        matrix[i] = new int[N];
    }

    for (int i = 0; i < M; i++)
    {
        for (int j = 0; j < N; j++)
        {
            matrix[i][j] = i*M+j;

        }
    }

    print_array(matrix, M, N);
    incMatrix(matrix, M, N, 111);
    print_array(matrix, M, N);

    // Удаление массива
    for (int i = 0; i < M; i++)
    {
        delete[] matrix[i];
    }
    return 0;
}
