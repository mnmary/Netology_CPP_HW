#pragma once
#include <iostream>
#include <string>
namespace HW7_3
{
    template <typename T>
    class MyVector
    {
    private:
        int _size = 0;
        int _capacity = 0;
        T* pArray;

        T* resizeArray()
        {
            if (_capacity == 0)
            {
                _capacity = 1;
            }

            _capacity *= 2;

            T* pNewArray = new T[_capacity];
            for (int i = 0; i < _size; i++)
            {
                pNewArray[i] = pArray[i];
            }
            delete[] pArray;

            return pNewArray;
        }
    public:
        T at(int index)
        {
            if (index > _size - 1)
            {
                throw std::runtime_error("Нет элемента с индексом " + std::to_string(index));
            }
            return pArray[index];
        }
        void push_back(T value)
        {
            if ((_size + 1) > _capacity)
            {
                pArray = resizeArray();
            }
            pArray[_size++] = value;
        }

        int size()
        {
            return _size;
        }
        int capacity()
        {
            return _capacity;
        }
        MyVector()
        {
            pArray = new T[_capacity];
        }
        ~MyVector()
        {
            delete[] pArray;
        }
    };

}