#pragma once
#include <string>
namespace HW5_2
{
    template <typename T>
    class Array2D
    {
    private:
        T** pArray;
        int rows, cols;
    public:
        Array2D(int r, int c) :rows(r), cols(c)
        {
            pArray = new T * [rows];
            for (int i = 0; i < rows; i++)
            {
                pArray[i] = new T[cols];
            }
        }
        ~Array2D()
        {
            for (int i = 0; i < rows; i++)
            {
                delete[] pArray[i];
            }
            delete[] pArray;
        }
        T* operator [](int index)
        {
            return pArray[index];
        }
        const T* operator[](int index) const
        {
            return pArray[index];
        }
        const std::string Size() const
        {
            return (std::to_string(rows) + " x " + std::to_string(cols));
        }
        void print()
        {
            for (int i = 0; i < rows; i++)
            {
                for (int j = 0; j < cols; j++)
                {
                    std::cout << std::fixed << pArray[i][j] << " ";
                }
                std::cout << std::endl;
            }
        }

    };
}

