// HW11-1.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <vector>
namespace HW11_1
{
    template <typename T>
    void move_vectors(std::vector<T>& v_from, std::vector<T>& v_to)
    {
        v_to = std::move(v_from);
    }

    template <typename T>
    void print_vector(std::vector<T>& vect, std::string name)
    {
        std::cout << name << ": ";
        for (const auto& v : vect)
        {
            std::cout << v << " ";
        }
        std::cout << std::endl;
    }
}

int main()
{
    std::vector <std::string> one = { "test_string1", "test_string2" };
    std::vector <std::string> two;
    
    //before moving
    HW11_1::print_vector<std::string>(one, "one");
    HW11_1::print_vector<std::string>(two, "two");

    HW11_1::move_vectors<std::string>(one, two);

    //after moving
    HW11_1::print_vector<std::string>(one, "one(after)");
    HW11_1::print_vector<std::string>(two, "two(after)");
}


