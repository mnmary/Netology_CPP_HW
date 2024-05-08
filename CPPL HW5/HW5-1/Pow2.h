#pragma once
#include <iostream>
#include <vector>

template <typename T>
T pow2(T value)
{
	return value * value;
}

template <typename T>
std::vector<T> pow2(std::vector<T> value)
{
    for (int i = 0; i < value.size(); i++)
    {
        value[i] = value[i] * value[i];
    }

    return value;
}

template<typename T>
void printValue(T value)
{
    std::cout << value;
    std::cout << std::endl;
}

template<typename T>
void printValue(const std::vector<T>& vect)
{
    for (auto a : vect)
    {
        std::cout << std::fixed << a << " ";
    }
    std::cout << std::endl;
}

