// HW8-2.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <vector>
#include <set>
#include <list>
#include "HW8_2.h"

int main()
{
    std::set<std::string> test_set = { "one", "two", "three", "four" };
    HW8_2::print_container(test_set); // four one three two. помните почему такой порядок? :) отсортирован по значению

    std::list<std::string> test_list = { "one", "two", "three", "four" };
    HW8_2::print_container(test_list); // one, two, three, four

    std::vector<std::string> test_vector = { "one", "two", "three", "four" };
    HW8_2::print_container(test_vector); // one, two, three, four

    return 0;
}


