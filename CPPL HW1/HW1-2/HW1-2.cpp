// HW1-2.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <variant>
#include <vector>

std::variant<int, std::string, std::vector<int>> get_variant() {
    std::srand(std::time(nullptr));
    int random_variable = std::rand() % 3;

    std::variant<int, std::string, std::vector<int>> result;
    switch (random_variable)
    {
    case 0:
        result = 5;
        break;
    case 1:
        result = "string";
        break;
    case 2:
        result = std::vector<int>{ 1, 2, 3, 4, 5 };
        break;
    default:
        break;
    }
    return result;
}
int main()
{
    auto check_value = [](const std::variant<int, std::string, std::vector<int>>& v)
        {
            
            if (const int* pval = std::get_if<int>(&v))
                std::cout << "integer value: " << *pval * 2 << '\n';
            else if (const std::string* pval = std::get_if<std::string>(&v))
                std::cout << "string value: " << *pval << '\n';
            else if (const std::vector<int>* pval = std::get_if<std::vector<int>>(&v))
            {
                std::cout << "vector value: ";
                for (int i = 0; i < pval->size(); i++)
                {
                    std::cout << pval->at(i) << " ";
                }
                std::cout << std::endl;
            }
        };

    std::variant<int, std::string, std::vector<int>> v;
    v = get_variant();
    check_value(v);
}

