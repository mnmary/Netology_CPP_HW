// HW10-1.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <vector>
#include <memory>

class tridiagonal_matrix
{
public:
    std::vector<double> m_down;
    std::vector<double> m_upper;
    std::vector<double> m_middle;
    tridiagonal_matrix(
        const std::vector<double>& down,
        const std::vector<double>& upper,
        const std::vector<double>& middle) :
        m_down{ down }, m_upper{ upper }, m_middle{ middle }
    {};
    ~tridiagonal_matrix() { std::cout << "destructor called\n"; }

    std::unique_ptr<tridiagonal_matrix> clone()
    {
        std::cout << "clone called\n";
        return std::make_unique<tridiagonal_matrix>(
            this->m_down,
            this->m_upper,
            this->m_middle);
    }
    void print_matrix()
    {
        for (const auto& d : m_down)
        {
            std::cout << d << " ";
        }
        std::cout << std :: endl;
        for (const auto& d : m_upper)
        {
            std::cout << d << " ";
        }
        std::cout << std::endl;
        for (const auto& d : m_middle)
        {
            std::cout << d << " ";
        }
        std::cout << std::endl;
    }
};

int main()
{
    auto down = std::vector<double>{ -4.0, 5.0 };
    auto upper = std::vector<double>{ 14.0, 8.0 };
    auto middle = std::vector<double>{ 3.0, 1.0, 7.0 };
    auto matrix = std::make_unique<tridiagonal_matrix>(
        down,
        upper,
        middle
    );

    auto matrix_clone = matrix->clone();
    matrix_clone->print_matrix();

    return 0;
}

