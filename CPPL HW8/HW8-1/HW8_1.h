#pragma once
#include <iostream>
#include <vector>
#include <algorithm>

namespace HW8_1
{
    template <typename T>
    void print(const std::vector<T>& vect)
    {
        for (const auto& v : vect)
        {
            std::cout << std::fixed << v << " ";
        }
        std::cout << std::endl;
    }

    template <typename T>
    void deleteDouble(std::vector<T>& vect)
    {
        std::sort(vect.begin(), vect.end());
        auto iterator = std::unique(vect.begin(), vect.end());
        vect.erase(iterator, vect.end());
    }
}
